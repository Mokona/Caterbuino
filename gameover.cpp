#include "gameover.h"

#include "data_icons.h"
#include "gamerunning.h"

#include <Gamebuino-Meta.h>
#include <cassert>

namespace {
    const int TARGET_Y_COORD = 8;
    const uint8_t VALUE_FOR_BLINK = 10;

    void displayGameOverText(uint8_t coord_y)
    {
        gb.display.setColor(Color::lightgreen);
        gb.display.setFontSize(2);
        gb.display.setCursor(5, coord_y);
        gb.display.println("GAME OVER");
    }
}

class RetryOrTitle {
public:
    RetryOrTitle()
        : iconAtlas(getIconsData())
    {
    }

    void update()
    {
        count -= 1;
        if (count == 0) {
            count = VALUE_FOR_BLINK;
            highlight = !highlight;
        }
    }

    void display()
    {
        iconAtlas.setFrame(8);
        gb.display.drawImage(60, 30, iconAtlas);

        if (highlight) {
            iconAtlas.setFrame(9);
            gb.display.drawImage(60, 30, iconAtlas);
        }

        gb.display.setFontSize(1);
        gb.display.setColor(Color::lightblue);
        gb.display.setCursor(5, 35);
        gb.display.println("PLAY AGAIN");
    }

private:
    Gamebuino_Meta::Image iconAtlas;
    bool highlight = false;
    uint8_t count = VALUE_FOR_BLINK;
};

GameOver::GameOver(Score score)
    : score(score)
    , choice(new RetryOrTitle())
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

    displayGameOverText(currentYCoordForGameOver);
    score.display();

    if (timeBeforeRetry > 0) {
        timeBeforeRetry -= 1;
    } else {
        choice->update();
        choice->display();

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
