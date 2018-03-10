#include <Gamebuino-Meta.h>

#include "profile.h"
#include "snake.h"
#include "display.h"
#include "game_space.h"

void setup() {
  gb.begin();
  gb.setFrameRate(25);
}

int clamp(int minimum, int maximum, int value)
{
  value = min(value, maximum);
  value = max(value, minimum);
  return value;
}

Snake snake;
DisplayCollector dsp;
GameSpace space(0, 0, 10, 7);

void loop()
{
  while (!gb.update());
  gb.display.clear();

  if (gb.buttons.timeHeld(BUTTON_UP) > 0) {
    snake.up();
  }
  if (gb.buttons.timeHeld(BUTTON_DOWN) > 0) {
    snake.down();
  }
  if (gb.buttons.timeHeld(BUTTON_LEFT) > 0) {
    snake.left();
  }
  if (gb.buttons.timeHeld(BUTTON_RIGHT) > 0) {
    snake.right();
  }

  dsp.begin();
  snake.update(1, space);
  snake.display(dsp);

  static bool displayProfile = true;
  if (gb.buttons.pressed(BUTTON_B)) {

    displayProfile = !displayProfile;
  }
  if(displayProfile) {
    displayProfileInfo();
  }
  
}

