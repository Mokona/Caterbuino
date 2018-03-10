#include "game_space.h"

GameSpace::GameSpace(uint8_t left, uint8_t up, uint8_t right, uint8_t down)
  : left(left), right(right), up(up), down(down)
{

}

bool GameSpace::contains(const Position & position) const
{
  return position.x >= left &&
         position.x < right &&
         position.y >= up &&
         position.y < down;
}

