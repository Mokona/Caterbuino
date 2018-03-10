#pragma once

#include "position.h"

#include <cstdint>
#include <memory>

class RandomPositionGenerator;

class GameSpace {
public:
    GameSpace(uint8_t left, uint8_t up, uint8_t right, uint8_t down);
    ~GameSpace();

    bool contains(const Position& position) const;

    Position random_position();

private:
    uint8_t left;
    uint8_t right;
    uint8_t up;
    uint8_t down;

    std::unique_ptr<RandomPositionGenerator> generator;
};
