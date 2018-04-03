#include "fruitcollection.h"

#include "data.h"
#include "drawhelper.h"

#include <Gamebuino-Meta.h>

namespace {
    const int INITIAL_FRUIT_LIFE = 2000;
}

int Fruit::max_life()
{
    return INITIAL_FRUIT_LIFE;
}

FruitCollection::FruitCollection()
{
    const Position nullPosition{ 0, 0 };
    for (auto& fruit : fruits) {
        fruit.position = nullPosition;
        fruit.life = 0;
    }
}

void FruitCollection::display()
{
    const auto caterpillar = getCaterpillarData();
    Image spritesheet(caterpillar);
    spritesheet.setFrame(0);

    const Position nullPosition{ 0, 0 };
    for (const auto& fruit : fruits) {
        if (fruit.position != nullPosition) {
            drawImageOnGrid(fruit.position, spritesheet);
        }
    }
}

void FruitCollection::update(int tick)
{
    for (auto& fruit : fruits) {
        fruit.life -= tick;
        if (fruit.life <= 0) {
            const Position nullPosition{ 0, 0 };
            fruit.position = nullPosition;
            fruit.life = 0;
        }
    }
}

void FruitCollection::add_fruit(const Position& position)
{
    const Position nullPosition{ 0, 0 };
    for (auto& fruit : fruits) {
        if (fruit.position == nullPosition) {
            fruit.position = position;
            fruit.life = INITIAL_FRUIT_LIFE;
            break;
        }
    }
}

void FruitCollection::remove_fruit(const Position& position)
{
    for (auto& fruit : fruits) {
        if (fruit.position == position) {
            const Position nullPosition{ 0, 0 };
            fruit.position = nullPosition;
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
