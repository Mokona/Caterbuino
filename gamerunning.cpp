#include "gamerunning.h"

#include <Gamebuino-Meta.h>

GameRunning::GameRunning()
    : space(0, 0, 10, 7)
{
    auto& captured_score = score;
    snake.on_move([&captured_score]() {
        captured_score += 1;
    });

    auto& captured_fruit_collection = fruitCollection;
    snake.on_eat([&captured_fruit_collection](const Position& position) {
        captured_fruit_collection.remove_fruit(position);
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

    fruitCollection.display();
    snake.display(dsp);
    score.display();
}
