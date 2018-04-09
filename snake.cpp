#include "snake.h"

#include "directions.h"
#include "display.h"
#include "fruitcollection.h"
#include "game_space.h"
#include "reverse.h"

namespace {
    const uint8_t tickForStep = 10;
    const size_t MAXIMUM_SNAKE_LENGTH = 42;

    template <typename T>
    bool is_full(const std::vector<T>& t)
    {
        return t.size() == t.capacity();
    }
}

Snake::Snake()
    : next_movement{ 1, 0 }
    , current_movement(next_movement)
    , growing(false)
{
    positions.reserve(MAXIMUM_SNAKE_LENGTH);
    positions.push_back(Position{ 3, 4 });
    positions.push_back(Position{ 4, 4 });
}

void Snake::display(DisplayCollector& dsp)
{
    dsp.head_direction(next_movement);

    for (const auto& p : reverse(positions)) {
        dsp.push(p);
    }
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
    for (const auto& p : positions) {
        found |= (p == position);
    }

    return found;
}

void Snake::move(const GameSpace& space)
{
    current_movement = next_movement;

    const auto& head = positions.back();
    const auto new_head = head + next_movement;

    if (space.contains(new_head)) {
        if (is_at(new_head)) {
            on_self_collision_cb();
        } else {
            positions.push_back(new_head);
            if (!growing || is_full(positions)) {
                positions.erase(positions.begin());
            }
            growing = false;

            on_move_cb();
        }
    } else {
        on_out_of_bounds_cb();
    }
}

void Snake::eat(const FruitCollection& fruits)
{
    const auto& head = positions.back();
    fruits.try_eat_fruit(head, on_eat_cb);
}

void Snake::grow()
{
    growing = true;
}

void Snake::up()
{
    using namespace Direction;

    if (current_movement != DOWN_MOVEMENT) {
        next_movement = UP_MOVEMENT;
    }
}

void Snake::down()
{
    using namespace Direction;

    if (current_movement != UP_MOVEMENT) {
        next_movement = DOWN_MOVEMENT;
    }
}

void Snake::left()
{
    using namespace Direction;

    if (current_movement != RIGHT_MOVEMENT) {
        next_movement = LEFT_MOVEMENT;
    }
}

void Snake::right()
{
    using namespace Direction;

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

void Snake::on_out_of_bounds(move_cb_type cb)
{
    on_out_of_bounds_cb = cb;
}
