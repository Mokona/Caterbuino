#include "gameover.h"

#include <Gamebuino-Meta.h>

GameOver::GameOver()
{
}

void GameOver::update()
{
    gb.display.setColor(Color::white);
    gb.display.setCursor(1, 58);
    gb.display.print("GAME OVER");
}