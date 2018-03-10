#pragma once

#include "position.h"

class DisplayCollector {
  public:
    void begin();
    void push(const Position & position);

  private:
    bool head;
};

