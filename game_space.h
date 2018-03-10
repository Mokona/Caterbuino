#pragma once

#include "position.h"

#include <cstdint>

class GameSpace {
  public:
    GameSpace(uint8_t left, uint8_t up, uint8_t right, uint8_t down);
    bool contains(const Position & position) const;

  private:
    uint8_t left;
    uint8_t right;
    uint8_t up;
    uint8_t down;
};

