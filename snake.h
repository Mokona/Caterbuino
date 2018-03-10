#pragma once

#include "array.h"
#include "position.h"
#include "vector2d.h"

class DisplayCollector;
class GameSpace;

class Snake {
public:
    Snake();
    void update(uint8_t tick, const GameSpace& space);
    void display(DisplayCollector& dsp);

    void up();
    void down();
    void left();
    void right();

private:
    void move(const GameSpace& space);

private:
    array<Position, 32> positions;
    Vector2D<int8_t> next_movement;
    uint8_t tickAccumulator;
};
