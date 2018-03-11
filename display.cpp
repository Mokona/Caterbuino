#include "display.h"

#include "data.h"

#include <Gamebuino-Meta.h>

void DisplayCollector::begin()
{
    head = true;
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

    int frame = head ? 1 : 0;

    Image spritesheet(caterpillar);
    spritesheet.setFrame(frame);
    gb.display.drawImage(corrected_x, corrected_y, spritesheet);

    if (head) {
        head = false;
    } else {
        frame = 0;
    }
}
