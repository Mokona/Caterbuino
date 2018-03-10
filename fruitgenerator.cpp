#include "fruitgenerator.h"

#include "fruitcollection.h"
#include "game_space.h"
#include "snake.h"

namespace {
    const uint8_t tickCountForGeneration = 30;

    void generate_fruit(FruitCollection& collection, GameSpace& space, Snake& snake)
    {
        const auto& position = space.random_position();

        if (!snake.is_at(position)) {
            collection.add_fruit(position);
        }
    }
}

void FruitGenerator::update(int tick, FruitCollection& collection, GameSpace& space, Snake& snake)
{
    tickAccumulator += tick;

    if (tickAccumulator > tickCountForGeneration) {
        generate_fruit(collection, space, snake);
        tickAccumulator = 0;
    }
}
