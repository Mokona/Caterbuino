#pragma once

#include "position.h"

#include <array>
#include <cstdint>

class FruitCollection {
public:
    FruitCollection();

    void add_fruit(const Position& position);
    void display();

private:
    std::array<Position, 16> fruits;
};
