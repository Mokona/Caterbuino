#pragma once

#include "position.h"

#include <cstdint>
#include <functional>
#include <vector>

struct Fruit {
    Position position;
    int life;

    static int max_life();
};

class FruitCollection {
public:
    FruitCollection();

    void update(int tick);
    void display();

    void add_fruit(const Position& position);
    void remove_fruit(const Position& position);
    void try_eat_fruit(const Position& position, std::function<void(const Fruit& fruit)> eat_cb) const;

private:
    std::vector<Fruit> fruits;
};
