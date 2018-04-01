#pragma once

class GameState {
public:
    virtual void update() = 0;
    virtual bool finished() = 0;
    virtual GameState* new_state() = 0;
};