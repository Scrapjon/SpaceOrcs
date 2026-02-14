#pragma once

#include <raylib.h>
#include "Ship.h"

class OrcShip : public Ship {
public:
	OrcShip(Vector2 location) : Ship(location) {};
};