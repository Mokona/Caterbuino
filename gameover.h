#pragma once

#include "gamestate.h"
#include "score.h"

#include <memory>

class RetryOrTitle;

class GameOver : public GameState {
public:
    explicit GameOver(Score score);

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;

private:
    void play_again();

private:
    Score score;
    std::unique_ptr<RetryOrTitle> choice;
    bool restartGame = false;
    uint8_t timeBeforeRetry = 30;
    uint8_t currentYCoordForGameOver = 0;
};
