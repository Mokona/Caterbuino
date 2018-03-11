#pragma once

#include "position.h"

class DisplayCollector {
public:
    void begin();

    void head_direction(const Vector2D<int8_t> direction);
    void push(const Position& position);

private:
    Vector2D<int8_t> direction;
    bool head;
};
