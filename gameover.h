#pragma once

#include "gamestate.h"
#include "score.h"

#include <memory>

class RetryOrTitle;
class GameOverTitle;

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
    std::unique_ptr<GameOverTitle> title;
    bool restartGame = false;
    uint8_t timeBeforeRetry = 30;
};
