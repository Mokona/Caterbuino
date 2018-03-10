#pragma once

#include <cstdint>

class FruitCollection;
class GameSpace;
class Snake;

class FruitGenerator {
public:
    void update(int tick, FruitCollection& collection, GameSpace& space, Snake& snake);

private:
    uint8_t tickAccumulator = 0;
};
