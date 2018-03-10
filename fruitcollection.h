#pragma once

#include "position.h"

#include <array>
#include <cstdint>
#include <functional>

class FruitCollection {
public:
    FruitCollection();

    void add_fruit(const Position& position);
    void remove_fruit(const Position& position);
    void display();
    void try_eat_fruit(const Position& position, std::function<void(const Position& position)> eat_cb) const;

private:
    std::array<Position, 16> fruits;
};
