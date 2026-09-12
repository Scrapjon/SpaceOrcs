#include "Game.h"

Camera2D Game::camera = {};

void Game::Tick ()
{
	HandleInputs (GetDeltaTime ());
	Draw ();
}

void Game::HandleInputs (float delta_time)
{
	if (IsKeyDown (KEY_RIGHT)) {
		camera.target.x += 10 * delta_time;
	}
	else if (IsKeyDown (KEY_LEFT)) {
		camera.target.x -= 10 * delta_time;
	}

	if (IsKeyDown (KEY_UP)) {
		camera.target.y -= 10 * delta_time;
	}
	else if (IsKeyDown (KEY_DOWN)) {
		camera.target.y += 10 * delta_time;
	}

	if (IsKeyDown (KEY_LEFT_SHIFT)) {
		camera.zoom += 0.1 * delta_time;
	}
	else if (IsKeyDown (KEY_LEFT_CONTROL)) {
		camera.zoom -= 0.1 * delta_time;
	}

	if (IsKeyDown (KEY_ESCAPE)) {
		m_should_quit = true;
	}

	if (IsKeyDown (KEY_E)) {
		m_entity_manager.CleanUpEntities ();
	}
}

void Game::Draw ()
{
	BeginDrawing ();
	BeginMode2D (camera);

	ClearBackground (BLACK);

	EndMode2D ();

	EndDrawing ();
}