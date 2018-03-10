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
}

Snake::Snake()
    : next_movement{ 1, 0 }
    , growing(false)
{
    positions.push_back(Position{ 3, 4 }).push_back(Position{ 4, 4 });
}

void Snake::display(DisplayCollector& dsp)
{
    positions.foreach ([&dsp](const Position& p) {
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
    const auto& head = positions.last();
    const auto new_head = head + next_movement;

    if (space.contains(new_head)) {
        positions.push_back(new_head);
        if (!growing || positions.full()) {
            positions.pop_front();
        }
        growing = false;

        on_move_cb();
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
    next_movement = { 0, -1 };
}

void Snake::down()
{
    next_movement = { 0, 1 };
}

void Snake::left()
{
    next_movement = { -1, 0 };
}

void Snake::right()
{
    next_movement = { 1, 0 };
}

void Snake::on_move(move_cb_type cb)
{
    on_move_cb = cb;
}

void Snake::on_eat(eat_cb_type cb)
{
    on_eat_cb = cb;
}