#pragma once

#include "gamestate.h"

#include "display.h"
#include "fruitcollection.h"
#include "fruitgenerator.h"
#include "game_space.h"
#include "lightanimation.h"
#include "score.h"
#include "snake.h"

class GameRunning : public GameState {
public:
    GameRunning();

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;

private:
    void self_collision();
    void out_of_bounds();
    void game_over();

private:
    GameSpace space;
    Snake snake;
    FruitCollection fruitCollection;
    FruitGenerator fruitGenerator;
    Score score;
    DisplayCollector dsp;
    LightAnimation lights;
    bool gameOver = false;
};
