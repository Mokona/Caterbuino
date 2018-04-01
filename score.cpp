#include "score.h"

#include <Gamebuino-Meta.h>

Score& Score::operator+=(int16_t change)
{
    value += change;

    return *this;
}

void Score::display()
{
    gb.display.setColor(Color::white);
    gb.display.setFontSize(1);
    gb.display.setCursor(1, 58);
    gb.display.print("SCORE:");
    gb.display.print(value);
}