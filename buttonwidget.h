#pragma once

#include "position.h"

#include "gamebuino_fix.h"

class ButtonWidget {
public:
    struct Parameters {
        Position buttonPlacement;
        Position textPlacement;
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
