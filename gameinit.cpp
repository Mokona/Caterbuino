#include "gameinit.h"

#include "gamerunning.h"

std::unique_ptr<GameState> create_game()
{
    return std::unique_ptr<GameState>(new GameRunning());
}
