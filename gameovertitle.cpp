#include "gameovertitle.h"

#include <Gamebuino-Meta.h>

#undef min
#undef max

#include <algorithm>
#include <cstring>

namespace {
    const int TARGET_Y_COORD = 8;
    const uint8_t SPEED_FOR_SHAKE = 3;
    const char GAME_OVER_TEXT[] = "GAME OVER";
}

GameOverTitle::GameOverTitle()
    : charShifts(strlen(GAME_OVER_TEXT))
    , speedCount(SPEED_FOR_SHAKE)
{
    std::fill(charShifts.begin(), charShifts.end(), 0);
}

void GameOverTitle::update()
{
    if (y_coordinate < TARGET_Y_COORD) {
        y_coordinate += 1;
    } else {
        speedCount -= 1;
        if (speedCount == 0) {
            speedCount = SPEED_FOR_SHAKE;

            const auto keepFirst = charShifts[0];
            std::rotate(charShifts.rbegin(), charShifts.rbegin() + 1, charShifts.rend());
            charShifts[0] = keepFirst;

            if (changeUp) {
                if (charShifts[0] > -1) {
                    charShifts[0] -= 1;
                } else {
                    changeUp = false;
                }
            } else {
                if (charShifts[0] < 1) {
                    charShifts[0] += 1;
                } else {
                    changeUp = true;
                }
            }
        }
    }
}

void GameOverTitle::display()
{
    gb.display.setColor(Color::lightgreen);
    gb.display.setFontSize(2);

    auto count = 0;

    for (const auto shift : charShifts) {
        const char c = GAME_OVER_TEXT[count];

        if (c != ' ' && c != '\0') {
            gb.display.setCursor(5 + 8 * count, y_coordinate + shift);
            gb.display.print(c);
        }
        count += 1;
    }
}
