#pragma once

#include "display.h"
#include "game_space.h"
#include "gamestate.h"
#include "score.h"
#include "snake.h"

class GameRunning : public GameState {
public:
    GameRunning();

    void update() override;

private:
    DisplayCollector dsp;
    GameSpace space;
    Snake snake;
    Score score;
};
