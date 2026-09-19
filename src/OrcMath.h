#pragma once

#include <cmath>
#include <iostream>
#include <raylib.h>

struct Vector2D {

	float x{}, y{};
	constexpr Vector2D () : x (0), y (0)
	{
	}
	constexpr Vector2D (float x, float y) : x (x), y (y)
	{
	}
	constexpr Vector2D (float flat) : x (flat), y (flat)
	{
	}
	constexpr Vector2D (Vector2 vec) : x (vec.x), y (vec.y)
	{
	}

	constexpr Vector2D operator+ (Vector2D rhs) const
	{
		return Vector2D (x + rhs.x, y + rhs.y);
	}
	constexpr Vector2D operator- (Vector2D rhs) const
	{
		return Vector2D (x - rhs.x, y - rhs.y);
	}
	constexpr Vector2D operator* (Vector2D rhs) const
	{
		return Vector2D (x * rhs.x, y * rhs.y);
	}
	constexpr Vector2D operator/ (Vector2D rhs) const
	{
		return Vector2D (x / rhs.x, y / rhs.y);
	}

	constexpr Vector2D operator+ (float rhs) const
	{
		return Vector2D (x + rhs, y + rhs);
	}
	constexpr Vector2D operator- (float rhs) const
	{
		return Vector2D (x - rhs, y - rhs);
	}
	constexpr Vector2D operator* (float rhs) const
	{
		return Vector2D (x * rhs, y * rhs);
	}
	constexpr Vector2D operator/ (float rhs) const
	{
		return Vector2D (x / rhs, y / rhs);
	}

	constexpr bool operator== (Vector2D rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	constexpr operator Vector2 ()
	{
		return Vector2{ x, y };
	}

	constexpr inline float Dot (const Vector2D &rhs)
	{
		return x * rhs.x + y * rhs.y;
	}
	constexpr inline float SquaredLength ()
	{
		return x * x + y * y;
	}
	constexpr inline float Length ()
	{
		return sqrtf (SquaredLength ());
	}
};

std::ostream &operator<< (std::ostream &stream, const Vector2D &vector);