#pragma once

#include "gamestate.h"

class ButtonWidget;

class GameCredits : public GameState {
public:
    GameCredits();

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;

private:
    std::unique_ptr<ButtonWidget> backToTitleDisplay;
    bool next_state = false;

    void back_to_title();
};
