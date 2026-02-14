#pragma once
#include <raylib.h>
#include <math.h>

class Ship {
public:
	int moveSpeed = 10;
	Vector2 location;

	Ship(Vector2 location) : location(location) {};

	void Draw() {
		DrawRectangle(location.x, location.y, 100, 100, RED);
	}
	
	void Move(const Vector2 direction) {

		if (direction.x > 0) {
			location.x -= moveSpeed;
		}
		else if (direction.x < 0) {

		}
		if (direction.y > 0) {

		}
		else if (direction.y < 0) {

		}

	}
};