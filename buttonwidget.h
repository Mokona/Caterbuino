#pragma once

#include "position.h"

#include "gamebuino_fix.h"

class ButtonWidget {
public:
    enum ButtonType {
        BLINK_A,
        BLINK_MENU
    };

    struct Parameters {
        Position buttonPlacement;
        Position textPlacement;
        ButtonType buttonType;
        const char* text;
    };

public:
    ButtonWidget(Parameters parameters);

    void update();
    void display();

private:
    Gamebuino_Meta::Image iconAtlas;
    Parameters parameters;
    bool highlight = false;
    uint8_t count;
};
