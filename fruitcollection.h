#pragma once

#include "position.h"

#include <cstdint>
#include <functional>
#include <memory>
#include <vector>

namespace Gamebuino_Meta {
    class Image;
}

struct Fruit {
    Position position;
    int life;

    static int max_life();
};

class FruitCollection {
public:
    FruitCollection();
    ~FruitCollection();

    void update(int tick);
    void display();

    void add_fruit(const Position& position);
    void remove_fruit(const Position& position);
    void try_eat_fruit(const Position& position, std::function<void(const Fruit& fruit)> eat_cb) const;

private:
    std::unique_ptr<Gamebuino_Meta::Image> spritesheet;
    std::vector<Fruit> fruits;
};
