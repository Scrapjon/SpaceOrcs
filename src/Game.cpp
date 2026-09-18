#include "Game.h"

void Game::Tick ()
{
	float delta_time = GetDeltaTime();
	HandleInputs (delta_time);

	for (std::weak_ptr<Entity> entity : m_entity_manager.GetEntities()) {
		entity.lock()->Tick(delta_time);
	}

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

	for (std::weak_ptr<Entity> entity : m_entity_manager.GetEntities()) {
		entity.lock()->Draw();
	}

	EndMode2D ();

	EndDrawing ();
}