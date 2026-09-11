#pragma once

#include <cmath>
#include <raylib.h>


struct Vector2D : Vector2 {

    constexpr Vector2D(float x, float y) : Vector2(x, y) {}
    constexpr Vector2D(float flat) : Vector2(flat, flat) {}
    constexpr Vector2D(Vector2 other) : Vector2(other) {}

    constexpr Vector2D operator+(Vector2D rhs) const { return Vector2D(x + rhs.x, y + rhs.y); }
    constexpr Vector2D operator-(Vector2D rhs) const { return Vector2D(x - rhs.x, y - rhs.y); }
    constexpr Vector2D operator*(Vector2D rhs) const { return Vector2D(x * rhs.x, y * rhs.y); }
    constexpr Vector2D operator/(Vector2D rhs) const { return Vector2D(x / rhs.x, y / rhs.y); }

    constexpr Vector2D operator+(float rhs) const { return Vector2D(x + rhs, y + rhs); }
    constexpr Vector2D operator-(float rhs) const { return Vector2D(x - rhs, y - rhs); }
    constexpr Vector2D operator*(float rhs) const { return Vector2D(x * rhs, y * rhs); }
    constexpr Vector2D operator/(float rhs) const { return Vector2D(x / rhs, y / rhs); }

    constexpr inline float Dot(const Vector2D& rhs) { return x * rhs.x + y * rhs.y; }
    constexpr inline float SquaredLength() { return x * x + y * y; }
    constexpr inline float Length() { return sqrtf(SquaredLength()); }

};

