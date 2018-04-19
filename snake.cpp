#include "snake.h"

#include "directions.h"
#include "display.h"
#include "fruitcollection.h"
#include "game_space.h"
#include "reverse.h"

namespace {
    const uint8_t BASE_TICK_FOR_STEP = 10;
    const uint8_t FRUITS_BEFORE_SPEED_UP = 3;
    const size_t MAXIMUM_SNAKE_LENGTH = 10;

    template <typename T>
    bool is_full(const std::vector<T>& t)
    {
        return t.size() == t.capacity();
    }
}

Snake::Snake()
    : next_movement{ 1, 0 }
    , current_movement(next_movement)
    , currentTickForStep(BASE_TICK_FOR_STEP)
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

    if (tickAccumulator >= currentTickForStep) {
        tickAccumulator -= currentTickForStep;
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

            const bool is_max_size = is_full(positions);

            if (!growing || is_max_size) {
                positions.erase(positions.begin());
            }
            if (is_max_size && growing) {
                speed_up();
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

void Snake::speed_up()
{
    fruitSpeedUpCounter += 1;

    if (fruitSpeedUpCounter == FRUITS_BEFORE_SPEED_UP) {
        fruitSpeedUpCounter = 0;
        if (currentTickForStep > 1) {
            currentTickForStep -= 1;
        }
    }
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
