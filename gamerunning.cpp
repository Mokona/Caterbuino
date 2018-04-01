#include "gamerunning.h"

#include "gameover.h"

#include <Gamebuino-Meta.h>
#include <cassert>

GameRunning::GameRunning()
    : space(0, 0, 10, 7)
{
    auto& captured_score = score;
    snake.on_move([&captured_score]() {
        captured_score += 1;
    });

    auto& captured_fruit_collection = fruitCollection;
    auto& captured_snake = snake;
    snake.on_eat([&captured_fruit_collection, &captured_snake, &captured_score](const Fruit& fruit) {
        captured_fruit_collection.remove_fruit(fruit.position);
        captured_snake.grow();

        const int score = (50 * fruit.life) / fruit.max_life();
        captured_score += score;
    });

    snake.on_self_collision([this]() {
        self_collision();
    });
}

void GameRunning::update()
{
    if (gb.buttons.timeHeld(BUTTON_UP) > 0) {
        snake.up();
    }
    if (gb.buttons.timeHeld(BUTTON_DOWN) > 0) {
        snake.down();
    }
    if (gb.buttons.timeHeld(BUTTON_LEFT) > 0) {
        snake.left();
    }
    if (gb.buttons.timeHeld(BUTTON_RIGHT) > 0) {
        snake.right();
    }

    dsp.begin();

    snake.update(1, space, fruitCollection);
    fruitGenerator.update(1, fruitCollection, space, snake);
    fruitCollection.update(1);

    fruitCollection.display();
    snake.display(dsp);
    score.display();
}

void GameRunning::self_collision()
{
    gameOver = true;
}

bool GameRunning::finished()
{
    return gameOver;
}

GameState* GameRunning::new_state()
{
    assert(gameOver);
    gameOver = false;
    return new GameOver();
}
