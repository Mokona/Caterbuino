#pragma once

#include "gamestate.h"

class GameTitle : public GameState {
public:
    explicit GameTitle();

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;
};
