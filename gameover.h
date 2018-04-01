#pragma once

#include "gamestate.h"

class GameOver : public GameState {
public:
    GameOver();

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;
};
