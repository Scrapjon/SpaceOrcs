#pragma once
#include "Entities/Entity.h"
#include "OrcMath.h"
#include <type_traits>

class Ship : public Entity {
public:
	Ship (float width = 100.f, float height = 100.f) : Entity ()
	{
		SetBounds (width, height);
	}
	~Ship () = default;
	virtual void Update (float delta_time) override;

	virtual void Draw () override;
};