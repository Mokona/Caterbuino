#include "gametitle.h"

#include "buttonwidget.h"
#include "data_title.h"
#include "gamecredits.h"
#include "gamerunning.h"

#include "gamebuino_fix.h"

#include <cassert>

namespace {
    uint16_t gameStartSound[] = {
        0x0005,
        0x178, 0x17A, 0x27C, 0x17E, 0x180, 0x286, 0x188,
        0x0000
    };

    const char* PLAY_TEXT = "PLAY";
    ButtonWidget::Parameters widgetParameters = {
        { 25, 47 },
        { 5, 52 },
        ButtonWidget::BLINK_A,
        PLAY_TEXT
    };
}

GameTitle::GameTitle()
    : titleImage(new Gamebuino_Meta::Image(getTitleData()))
    , startGameDisplay(new ButtonWidget(widgetParameters))
{
    gb.sound.play(gameStartSound);
}

void GameTitle::update()
{
    gb.display.drawImage(0, 0, *titleImage);

    gb.display.setColor(Color::gray);
    gb.display.setFontSize(1);
    gb.display.setCursor(64, 59);
    gb.display.println("v0.9");

    startGameDisplay->update();
    startGameDisplay->display();

    if (gb.buttons.pressed(BUTTON_A)) {
        start_game();
    } else if (gb.buttons.pressed(BUTTON_MENU)) {
        start_credits();
    }
}

void GameTitle::start_game()
{
    action = GO_TO_GAME;
}

void GameTitle::start_credits()
{
    action = GO_TO_CREDITS;
}

bool GameTitle::finished()
{
    return action != STAY_HERE;
}

std::unique_ptr<GameState> GameTitle::new_state()
{
    assert(finished());

    auto& take_action = action;
    auto state = [take_action]() -> std::unique_ptr<GameState> {
        switch (take_action) {
        case GO_TO_GAME:
            return std::unique_ptr<GameState>(new GameRunning());
        case GO_TO_CREDITS:
            return std::unique_ptr<GameState>(new GameCredits());
        }
        return {};
    }();
    action = STAY_HERE;

    return state;
};
