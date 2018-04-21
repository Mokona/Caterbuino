#include "score.h"

#include <Gamebuino-Meta.h>

namespace {
    int16_t MAX_SCORE = 9999;
}

Score& Score::operator+=(int16_t change)
{
    value += change;
    value = min(value, MAX_SCORE);

    return *this;
}

void Score::display()
{
    gb.display.setColor(Color::lightgreen);
    gb.display.setFontSize(1);
    gb.display.setCursor(1, 58);
    gb.display.print("SCORE:");
    gb.display.print(value);
}
