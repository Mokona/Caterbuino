#include "gametitle.h"

#include "data_title.h"
#include "gamerunning.h"

#include <Gamebuino-Meta.h>

#include <cassert>

namespace {
    uint16_t gameStartSound[] = {
        0x0005,
        0x178, 0x17A, 0x27C, 0x17E, 0x180, 0x286, 0x188,
        0x0000
    };
}

GameTitle::GameTitle()
    : titleImage(new Gamebuino_Meta::Image(getTitleData()))
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

    if (gb.buttons.pressed(BUTTON_A)) {
        start_game();
    }
}

void GameTitle::start_game()
{
    next_state = true;
}

bool GameTitle::finished()
{
    return next_state;
}

std::unique_ptr<GameState> GameTitle::new_state()
{
    assert(next_state);
    next_state = false;
    return std::unique_ptr<GameState>(new GameRunning());
}
