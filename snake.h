#pragma once

#include "array.h"
#include "position.h"
#include "vector2d.h"

#include <functional>

class DisplayCollector;
class FruitCollection;
class GameSpace;

class Snake {
public:
    Snake();

    void update(uint8_t tick, const GameSpace& space, const FruitCollection& fruits);
    void display(DisplayCollector& dsp);
    bool is_at(const Position& position) const;

    void up();
    void down();
    void left();
    void right();

    using move_cb_type = std::function<void()>;
    using eat_cb_type = std::function<void(const Position&)>;

    void on_move(move_cb_type cb);
    void on_eat(eat_cb_type cb);

private:
    void move(const GameSpace& space);
    void eat(const FruitCollection& fruits);

private:
    array<Position, 32> positions;
    Vector2D<int8_t> next_movement;

    move_cb_type on_move_cb;
    eat_cb_type on_eat_cb;

    uint8_t tickAccumulator;
};
