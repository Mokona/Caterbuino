#include "fruitcollection.h"

#include <Gamebuino-Meta.h>

FruitCollection::FruitCollection()
{
    const Position nullPosition{ 0, 0 };
    for (auto& fruit_position : fruits) {
        fruit_position = nullPosition;
    }
}

void FruitCollection::display()
{
    const uint8_t width = 8;
    const uint8_t height = 8;
    const uint8_t shift_w = 2;
    const uint8_t shift_h = 2;

    for (const auto& position : fruits) {
        const auto corrected_x = position.x * width + shift_w;
        const auto corrected_y = position.y * height + shift_h;

        gb.display.setColor(Color::red);
        gb.display.fillRect(corrected_x, corrected_y, width / 2, height / 2);
    }
}

void FruitCollection::add_fruit(const Position& position)
{
    const Position nullPosition{ 0, 0 };
    for (auto& fruit_position : fruits) {
        if (fruit_position == nullPosition) {
            fruit_position = position;
            break;
        }
    }
}