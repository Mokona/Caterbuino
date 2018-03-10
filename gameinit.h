#pragma once

#include "gamestate.h"

#include <memory>

std::unique_ptr<GameState> create_game();
