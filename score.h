#pragma once

#include <cstdint>

class Score {
public:
    Score& operator+=(int16_t value);

    void display();

private:
    uint16_t value = 0;
};

template <typename T>
Score& operator+=(Score& score, T value)
{
    return score += static_cast<int16_t>(value);
}