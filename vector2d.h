#pragma once

template <typename T>
struct Vector2D {
    T x;
    T y;

    using value_type = T;
};

template <typename T1, typename T2>
Vector2D<T1> operator+(const Vector2D<T1>& a, const Vector2D<T2>& b)
{
    return Vector2D<T1>{
        a.x + b.x,
        a.y + b.y
    };
}

template <typename T1, typename T2>
bool operator==(const Vector2D<T1>& a, const Vector2D<T2>& b)
{
    return a.x == b.x && a.y == b.y;
}

template <typename T1, typename T2>
bool operator!=(const Vector2D<T1>& a, const Vector2D<T2>& b)
{
    return !(a == b);
}
