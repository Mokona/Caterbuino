#include "fruitcollection.h"

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
    const uint8_t width = 8;
    const uint8_t height = 8;
    const uint8_t shift_w = 2;
    const uint8_t shift_h = 2;

    const Position nullPosition{ 0, 0 };
    for (const auto& fruit : fruits) {
        if (fruit.position != nullPosition) {
            const auto corrected_x = fruit.position.x * width + shift_w;
            const auto corrected_y = fruit.position.y * height + shift_h;

            gb.display.setColor(Color::red);
            gb.display.fillRect(corrected_x, corrected_y, width / 2, height / 2);
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
