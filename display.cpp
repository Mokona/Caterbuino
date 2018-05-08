#include "display.h"

#include "data_caterpillar.h"
#include "directions.h"
#include "drawhelper.h"

#include "gamebuino_fix.h"

DisplayCollector::DisplayCollector()
    : spritesheet(new Gamebuino_Meta::Image(getCaterpillarData()))
{
}

DisplayCollector::~DisplayCollector()
{
}

void DisplayCollector::begin()
{
    head = true;
}

void DisplayCollector::push(const Position& position)
{
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

    spritesheet->setFrame(frame);

    drawImageOnGrid(position, *spritesheet);

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