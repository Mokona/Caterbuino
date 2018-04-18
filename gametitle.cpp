#include "gametitle.h"

#include "gamerunning.h"

#include <Gamebuino-Meta.h>
#include <cassert>

GameTitle::GameTitle()
{
}

void GameTitle::update()
{
}

bool GameTitle::finished()
{
    return true;
}

std::unique_ptr<GameState> GameTitle::new_state()
{
    return std::unique_ptr<GameState>(new GameRunning());
}
