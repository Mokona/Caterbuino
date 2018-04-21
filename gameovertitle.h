#pragma once

#include <cstdint>
#include <vector>

class GameOverTitle {
public:
    GameOverTitle();
    void update();
    void display();

private:
    uint8_t y_coordinate = 0;
    std::vector<int8_t> charShifts;
    bool changeUp = true;
    bool speedCount;
};
