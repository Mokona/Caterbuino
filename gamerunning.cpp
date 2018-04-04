#include "gamerunning.h"

#include "gameover.h"

#include <Gamebuino-Meta.h>
#include <cassert>

namespace {
    void process_keys(Snake& snake)
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
    }

    uint16_t fruitSound[] = { 0x0005, 0x148, 0x158, 0x168, 0x0000 };
    uint16_t moveSound[] = { 0x0005, 0x118, 0x128, 0x0000 };
    uint16_t gameOverSound[] = { 0x0005, 0x188, 0x186, 0x180, 0x17E,
        0x17C, 0x17A, 0x178, 0x0000 };
}

LightAnimation::LightAnimation()
{
    gb.lights.fill(BLACK);
}

void LightAnimation::update()
{
    if (step > 0) {
        step--;
        gb.lights.fill(BLACK);
        gb.lights.drawPixel(0, step - 1, GREEN);
        gb.lights.drawPixel(1, step - 1, GREEN);
    }
}

void LightAnimation::go()
{
    step = 4;
}

GameRunning::GameRunning()
    : space(0, 0, 10, 7)
{
    auto& captured_score = score;
    snake.on_move([&captured_score]() {
        captured_score += 1;

        gb.sound.play(moveSound);
    });

    auto& captured_fruit_collection = fruitCollection;
    auto& captured_snake = snake;
    auto& captured_lights = lights;
    snake.on_eat([&captured_fruit_collection,
                     &captured_snake,
                     &captured_score,
                     &captured_lights](const Fruit& fruit) {
        captured_fruit_collection.remove_fruit(fruit.position);
        captured_snake.grow();

        const int score = (50 * fruit.life) / fruit.max_life();
        captured_score += score;

        gb.sound.play(fruitSound);
        captured_lights.go();
    });

    snake.on_self_collision([this]() {
        self_collision();
    });

    snake.on_out_of_bounds([this]() {
        out_of_bounds();
    });
}

void GameRunning::update()
{
    process_keys(snake);

    dsp.begin();

    snake.update(1, space, fruitCollection);
    fruitGenerator.update(1, fruitCollection, space, snake);
    fruitCollection.update(1);
    lights.update();

    fruitCollection.display();
    snake.display(dsp);
    score.display();
}

void GameRunning::self_collision()
{
    game_over();
}

void GameRunning::out_of_bounds()
{
    game_over();
}

void GameRunning::game_over()
{
    gameOver = true;
    gb.sound.play(gameOverSound);
}

bool GameRunning::finished()
{
    return gameOver;
}

std::unique_ptr<GameState> GameRunning::new_state()
{
    assert(gameOver);
    gameOver = false;
    return std::unique_ptr<GameState>(new GameOver(score));
}
