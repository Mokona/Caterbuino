#pragma once

#include "array.h"
#include "position.h"
#include "vector2d.h"

#include <functional>

class DisplayCollector;
class Fruit;
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

    void grow();

    using move_cb_type = std::function<void()>;
    using eat_cb_type = std::function<void(const Fruit&)>;

    void on_move(move_cb_type cb);
    void on_eat(eat_cb_type cb);

    using movement_type = Vector2D<int8_t>;

private:
    void move(const GameSpace& space);
    void eat(const FruitCollection& fruits);

private:
    movement_type next_movement;
    movement_type current_movement;

    array<Position, 42> positions;

    move_cb_type on_move_cb;
    eat_cb_type on_eat_cb;

    uint8_t tickAccumulator;
    bool growing;
};
