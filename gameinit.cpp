#include "gameinit.h"

#include "gametitle.h"

std::unique_ptr<GameState> create_game()
{
    return std::unique_ptr<GameState>(new GameTitle());
}
