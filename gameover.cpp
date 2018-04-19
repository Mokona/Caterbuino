#include "gameover.h"

#include "gamerunning.h"

#include <Gamebuino-Meta.h>
#include <cassert>

namespace {
    const int TARGET_Y_COORD = 8;
}

GameOver::GameOver(Score score)
    : score(score)
{
}

void GameOver::update()
{
    if (restartGame) {
        return;
    }

    if (currentYCoordForGameOver < TARGET_Y_COORD) {
        currentYCoordForGameOver += 1;
    }

    gb.display.setColor(Color::green);
    gb.display.setFontSize(2);
    gb.display.setCursor(5, currentYCoordForGameOver);
    gb.display.println("GAME OVER");

    score.display();

    if (timeBeforeRetry > 0) {
        timeBeforeRetry -= 1;
    } else {
        gb.display.setFontSize(1);
        gb.display.setCursor(1, 35);
        gb.display.println("PRESS 'A'");
        gb.display.println("TO PLAY AGAIN");

        if (gb.buttons.pressed(BUTTON_A)) {
            play_again();
        }
    }
}

void GameOver::play_again()
{
    restartGame = true;
}

bool GameOver::finished()
{
    return restartGame;
}

std::unique_ptr<GameState> GameOver::new_state()
{
    assert(restartGame);
    restartGame = false;
    return std::unique_ptr<GameState>(new GameRunning());
}
