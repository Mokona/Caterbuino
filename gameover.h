#pragma once

#include "gamestate.h"

class GameOver : public GameState {
public:
    GameOver();

    void update() override;
    bool finished() override;
    GameState* new_state() override;
};
