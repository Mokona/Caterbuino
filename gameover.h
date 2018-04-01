#pragma once

#include "gamestate.h"

class GameOver : public GameState {
public:
    GameOver();

    void update() override;
};
