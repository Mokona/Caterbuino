#pragma once

#include "gamestate.h"

namespace Gamebuino_Meta {
    class Image;
}

class ButtonWidget;

class GameTitle : public GameState {
public:
    explicit GameTitle();

    void update() override;
    bool finished() override;
    std::unique_ptr<GameState> new_state() override;

private:
    std::unique_ptr<Gamebuino_Meta::Image> titleImage;
    std::unique_ptr<ButtonWidget> startGameDisplay;
    bool next_state = false;

    void start_game();
};
