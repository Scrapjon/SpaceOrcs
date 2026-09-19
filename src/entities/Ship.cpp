#include "Entities/Ship.h"
#include "Game.h"

void Ship::Update (float delta_time)
{
	Entity::Update (delta_time);
}

void Ship::Draw ()
{
	Rectangle bounds = GetBounds ();
	auto [x, y]		 = GetWorldToScreen2D (Vector2D{ bounds.x, bounds.y }, Game::GetInstance ().camera);
	DrawRectangle (x, y, bounds.width, bounds.height, RED);
}
