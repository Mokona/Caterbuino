#include "lightanimation.h"

#include <Gamebuino-Meta.h>

LightAnimation::LightAnimation()
{
    gb.lights.fill(BLACK);
}

void LightAnimation::update()
{
    if (step > 0) {
        step--;
        gb.lights.fill(BLACK);
        gb.lights.drawPixel(0, step - 1, GREEN);
        gb.lights.drawPixel(1, step - 1, GREEN);
    }
}

void LightAnimation::go()
{
    step = 4;
}
