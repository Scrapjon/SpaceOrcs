#pragma once

#include "Entities/Ship.h"

class Player : public Ship {
public:
	Player () : Ship ()
	{
	}
	~Player () = default;
	virtual void Update (float delta_time) override;
	virtual void Draw () override;
};