#include "display.h"

#include "data.h"
#include "directions.h"
#include "drawhelper.h"

#include <Gamebuino-Meta.h>

void DisplayCollector::begin()
{
    head = true;
}

void DisplayCollector::push(const Position& position)
{
    const auto caterpillar = getCaterpillarData();

    int frame = 2;

    if (head) {
        using namespace Direction;

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

    drawImageOnGrid(position, spritesheet);

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