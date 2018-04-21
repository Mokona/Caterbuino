#pragma once

#include "position.h"

#include <Gamebuino-Meta.h>

#undef min
#undef max

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
