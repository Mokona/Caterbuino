#include "gameover.h"

#include "buttonwidget.h"
#include "data_icons.h"
#include "gameovertitle.h"
#include "gametitle.h"

#include "gamebuino_fix.h"

#include <cassert>
#include <vector>

namespace {
    const uint8_t VALUE_FOR_BLINK = 10;

    const char* PLAY_AGAIN_TEXT = "PLAY AGAIN";
    ButtonWidget::Parameters widgetParameters = {
        { 60, 30 },
        { 5, 35 },
        PLAY_AGAIN_TEXT
    };
}

GameOver::GameOver(Score score)
    : score(score)
    , buttonWidget(new ButtonWidget(widgetParameters))
    , title(new GameOverTitle())
{
}

void GameOver::update()
{
    if (finished()) {
        return;
    }

    title->update();
    title->display();

    score.display();

    if (timeBeforeRetry > 0) {
        timeBeforeRetry -= 1;
    } else {
        buttonWidget->update();
        buttonWidget->display();

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

    return std::unique_ptr<GameState>(new GameTitle());
}
