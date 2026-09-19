#include "Entities/Player.h"
#include "Game.h"
#include <cassert>

#define COMPARE_VARS(X, Y) std::cout << #X ": " << (X) << ", " #Y ": " << (Y) << "\n"

void Player::Update (float delta_time)
{
	Ship::Update (delta_time);
	COMPARE_VARS (location, GetWorldToScreen2D (location, Game::GetInstance ().camera));
}

void Player::Draw ()
{
	// Camera2D &camera = Game::GetInstance ().camera;
	//  camera.target	 = GetWorldToScreen2D (location, camera);
	Ship::Draw ();
}
