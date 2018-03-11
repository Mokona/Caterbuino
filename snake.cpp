#include "snake.h"

#include "display.h"
#include "fruitcollection.h"
#include "game_space.h"

// Because the library for Arduino seems incomplete
namespace std {
    void __throw_bad_function_call()
    {
        while (1)
            ;
    }
}

namespace {
    const uint8_t tickForStep = 10;

    const Snake::movement_type UP_MOVEMENT = { 0, -1 };
    const Snake::movement_type DOWN_MOVEMENT = { 0, 1 };
    const Snake::movement_type LEFT_MOVEMENT = { -1, 0 };
    const Snake::movement_type RIGHT_MOVEMENT = { 1, 0 };
}

Snake::Snake()
    : next_movement{ 1, 0 }
    , current_movement(next_movement)
    , growing(false)
{
    positions.push_back(Position{ 3, 4 }).push_back(Position{ 4, 4 });
}

void Snake::display(DisplayCollector& dsp)
{
    positions.rforeach([&dsp](const Position& p) {
        dsp.push(p);
    });
}

void Snake::update(uint8_t tick, const GameSpace& space, const FruitCollection& fruits)
{
    tickAccumulator += tick;

    if (tickAccumulator >= tickForStep) {
        tickAccumulator -= tickForStep;
        move(space);
        eat(fruits);
    }
}

bool Snake::is_at(const Position& position) const
{
    bool found = false;
    positions.foreach ([&found, &position](const Position& p) {
        found |= (p == position);
    });

    return found;
}

void Snake::move(const GameSpace& space)
{
    current_movement = next_movement;

    const auto& head = positions.last();
    const auto new_head = head + next_movement;

    if (space.contains(new_head)) {
        if (is_at(new_head)) {
            on_self_collision_cb();
        } else {
            positions.push_back(new_head);
            if (!growing || positions.full()) {
                positions.pop_front();
            }
            growing = false;

            on_move_cb();
        }
    }
}

void Snake::eat(const FruitCollection& fruits)
{
    const auto& head = positions.last();
    fruits.try_eat_fruit(head, on_eat_cb);
}

void Snake::grow()
{
    growing = true;
}

void Snake::up()
{
    if (current_movement != DOWN_MOVEMENT) {
        next_movement = UP_MOVEMENT;
    }
}

void Snake::down()
{
    if (current_movement != UP_MOVEMENT) {
        next_movement = DOWN_MOVEMENT;
    }
}

void Snake::left()
{
    if (current_movement != RIGHT_MOVEMENT) {
        next_movement = LEFT_MOVEMENT;
    }
}

void Snake::right()
{
    if (current_movement != LEFT_MOVEMENT) {
        next_movement = RIGHT_MOVEMENT;
    }
}

void Snake::on_move(move_cb_type cb)
{
    on_move_cb = cb;
}

void Snake::on_eat(eat_cb_type cb)
{
    on_eat_cb = cb;
}

void Snake::on_self_collision(move_cb_type cb)
{
    on_self_collision_cb = cb;
}
