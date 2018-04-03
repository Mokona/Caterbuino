#include "drawhelper.h"

namespace {
    const uint8_t width = 8;
    const uint8_t height = 8;
}

void drawImageOnGrid(const Position& position, Image& image)
{
    const auto corrected_x = position.x * width;
    const auto corrected_y = position.y * height;

    gb.display.drawImage(corrected_x, corrected_y, image);
}
