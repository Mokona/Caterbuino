#include "gamerunning.h"

#include <Gamebuino-Meta.h>

GameRunning::GameRunning()
    : space(0, 0, 10, 7)
{
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
    snake.update(1, space);
    snake.display(dsp);
}
