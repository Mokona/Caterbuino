#pragma once

#include "gamestate.h"

namespace Gamebuino_Meta {
    class Image;
}

class ButtonWidget;

class GameTitle : public GameState {
public:
    GameTitle();

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;

private:
    std::unique_ptr<Gamebuino_Meta::Image> titleImage;
    std::unique_ptr<ButtonWidget> startGameDisplay;

    enum Action {
        STAY_HERE,
        GO_TO_GAME,
        GO_TO_CREDITS
    };

    Action action = STAY_HERE;

    void start_game();
    void start_credits();
};
