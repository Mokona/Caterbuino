#pragma once

#include "gamestate.h"

#include "display.h"
#include "fruitcollection.h"
#include "fruitgenerator.h"
#include "game_space.h"
#include "score.h"
#include "snake.h"

class GameRunning : public GameState {
public:
    GameRunning();

    void update() override;
    bool finished() override;
    GameState* new_state() override;

private:
    void self_collision();
    void out_of_bounds();

private:
    GameSpace space;
    Snake snake;
    FruitCollection fruitCollection;
    FruitGenerator fruitGenerator;
    Score score;
    DisplayCollector dsp;
    bool gameOver = false;
};
