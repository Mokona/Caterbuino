#pragma once

#include <memory>

class GameState {
public:
    virtual ~GameState(){};
    virtual void update() = 0;
    virtual bool finished() = 0;
    virtual std::unique_ptr<GameState> new_state() = 0;
};