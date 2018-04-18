#pragma once

#include "position.h"

#include <memory>

namespace Gamebuino_Meta {
    class Image;
}

class DisplayCollector {
public:
    DisplayCollector();
    ~DisplayCollector();

    void begin();

    void head_direction(const Vector2D<int8_t> direction);
    void push(const Position& position);

private:
    Vector2D<int8_t> direction = { 0, 0 };
    std::unique_ptr<Gamebuino_Meta::Image> spritesheet;
    bool head = false;
};
