#pragma once

#include "array.h"
#include "position.h"
#include "vector2d.h"

#include <functional>

class DisplayCollector;
class GameSpace;

class Snake {
public:
    Snake();
    void update(uint8_t tick, const GameSpace& space);
    void display(DisplayCollector& dsp);
    bool is_at(const Position& position) const;

    void up();
    void down();
    void left();
    void right();

    void on_move(std::function<void()> cb);

private:
    void move(const GameSpace& space);

private:
    array<Position, 32> positions;
    Vector2D<int8_t> next_movement;

    std::function<void()> on_move_cb;

    uint8_t tickAccumulator;
};
