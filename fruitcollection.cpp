#include "fruitcollection.h"

#include "data_caterpillar.h"
#include "drawhelper.h"

#include "gamebuino_fix.h"

#include <algorithm>

namespace {
    const int INITIAL_FRUIT_LIFE = 225;
    const size_t MAXIMUM_FRUIT = 10;
}

int Fruit::max_life()
{
    return INITIAL_FRUIT_LIFE;
}

FruitCollection::FruitCollection()
    : spritesheet(new Gamebuino_Meta::Image(getCaterpillarData()))
{
    fruits.reserve(MAXIMUM_FRUIT);
}

FruitCollection::~FruitCollection()
{
}

void FruitCollection::display()
{
    spritesheet->setFrame(0);

    for (const auto& fruit : fruits) {
        if (fruit.life > 10 || (fruit.life & 1)) {
            drawImageOnGrid(fruit.position, *spritesheet);
        }
    }
}

void FruitCollection::update(int tick)
{
    for (auto& fruit : fruits) {
        fruit.life -= tick;
        if (fruit.life <= 0) {
            // Only removes one fruit at a time
            // Anyway, all fruits should have different lifetime as
            // they never appear at the same time.
            fruit = fruits.back();
            fruits.pop_back();
            break;
        }
    }
}

void FruitCollection::add_fruit(const Position& position)
{
    if (fruits.size() < fruits.capacity()) {
        const auto fruit_at_position = std::any_of(
            fruits.begin(), fruits.end(),
            [position](const Fruit& fruit) {
                return fruit.position == position;
            });

        if (!fruit_at_position) {
            fruits.push_back(Fruit{ position, INITIAL_FRUIT_LIFE });
        }
    }
}

void FruitCollection::remove_fruit(const Position& position)
{
    for (auto& fruit : fruits) {
        if (fruit.position == position) {
            fruit = fruits.back();
            fruits.pop_back();
            break;
        }
    }
}

void FruitCollection::try_eat_fruit(const Position& position, std::function<void(const Fruit& fruit)> eat_cb) const
{
    for (const auto& fruit : fruits) {
        if (fruit.position == position) {
            eat_cb(fruit);
        }
    }
}
