#pragma once

#include "vector2d.h"

#include <cstdint>

namespace Direction {
    const Vector2D<int8_t> UP_MOVEMENT = { 0, -1 };
    const Vector2D<int8_t> DOWN_MOVEMENT = { 0, 1 };
    const Vector2D<int8_t> LEFT_MOVEMENT = { -1, 0 };
    const Vector2D<int8_t> RIGHT_MOVEMENT = { 1, 0 };
}
