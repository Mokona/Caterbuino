#include "snake.h"

#include "display.h"
#include "game_space.h"

namespace {
    const uint8_t tickForStep = 10;
}

Snake::Snake()
    : next_movement{ 1, 0 }
{
    positions.push_back(Position{ 3, 4 }).push_back(Position{ 4, 4 });
}

void Snake::display(DisplayCollector& dsp)
{
    positions.foreach ([&dsp](const Position& p) {
        dsp.push(p);
    });
}

void Snake::update(uint8_t tick, const GameSpace& space)
{
    tickAccumulator += tick;

    if (tickAccumulator >= tickForStep) {
        tickAccumulator -= tickForStep;
        move(space);
    }
}

void Snake::move(const GameSpace& space)
{
    const auto& head = positions.last();
    const auto new_head = head + next_movement;

    if (space.contains(new_head)) {
        positions.push_back(new_head);
        positions.pop_front();
    }
    // else : DEAD
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
