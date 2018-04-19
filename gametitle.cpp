#include "gametitle.h"

#include "data_title.h"
#include "gamerunning.h"

#include <Gamebuino-Meta.h>

#include <cassert>

GameTitle::GameTitle()
    : titleImage(new Gamebuino_Meta::Image(getTitleData()))
{
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
