#include "display.h"

#include "data.h"

#include <Gamebuino-Meta.h>

void DisplayCollector::begin()
{
    head = true;
}

namespace {
    const Vector2D<int8_t> UP_MOVEMENT = { 0, -1 };
    const Vector2D<int8_t> DOWN_MOVEMENT = { 0, 1 };
    const Vector2D<int8_t> LEFT_MOVEMENT = { -1, 0 };
    const Vector2D<int8_t> RIGHT_MOVEMENT = { 1, 0 };
}

void DisplayCollector::push(const Position& position)
{
    const auto caterpillar = getCaterpillarData();

    const uint8_t width = 8;
    const uint8_t height = 8;
    const auto corrected_x = position.x * width;
    const auto corrected_y = position.y * height;

    //gb.display.setColor(Color::white);
    //gb.display.fillRoundRect(corrected_x, corrected_y, width, height, 2);

    int frame = 2;

    if (head) {
        if (direction == RIGHT_MOVEMENT) {
            frame = 3;
        } else if (direction == DOWN_MOVEMENT) {
            frame = 4;
        } else if (direction == LEFT_MOVEMENT) {
            frame = 5;
        } else if (direction == UP_MOVEMENT) {
            frame = 6;
        }
    }

    Image spritesheet(caterpillar);
    spritesheet.setFrame(frame);
    gb.display.drawImage(corrected_x, corrected_y, spritesheet);

    if (head) {
        head = false;
    } else {
        frame = 0;
    }
}

void DisplayCollector::head_direction(const Vector2D<int8_t> direction)
{
    this->direction = direction;
}