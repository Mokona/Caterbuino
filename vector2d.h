#pragma once

template <typename T>
struct Vector2D {
    T x;
    T y;

    using value_type = T;
};

template <typename T1, typename T2>
auto operator+(T1&& a, T2&& b)
{
    return T1{
        a.x + b.x,
        a.y + b.y
    };
}