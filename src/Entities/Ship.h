#pragma once
#include "Entities/Entity.h"
#include "OrcMath.h"
#include <type_traits>

class Ship : public Entity {
public:
	virtual void Tick (float delta_time) override
	{
		Entity::Tick (delta_time);
	}

	virtual void Draw () override
	{
		DrawRectangle (location.x, location.y, 10, 10, RED);
	}
};