#pragma once

#include "gamestate.h"
#include "score.h"

class GameOver : public GameState {
public:
    GameOver(Score score);

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;

private:
    void play_again();

private:
    Score score;
    bool restartGame = false;
    uint8_t timeBeforeRetry = 30;
};
