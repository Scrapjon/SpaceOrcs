#include "Game.h"

void Game::Update ()
{
	float delta_time = GetDeltaTime ();
	HandleInputs (delta_time);

	for (std::weak_ptr<Entity> entity : m_entity_manager.GetEntities ()) {
		entity.lock ()->Update (delta_time);
	}

	Draw ();

	m_entity_manager.CleanUpEntities ();
}

void Game::HandleInputs (float delta_time)
{
	if (IsKeyDown (KEY_RIGHT)) {
		m_player->location.x += 10 * delta_time;
	}
	else if (IsKeyDown (KEY_LEFT)) {
		m_player->location.x -= 10 * delta_time;
	}

	if (IsKeyDown (KEY_UP)) {
		m_player->location.y += 10 * delta_time;
	}
	else if (IsKeyDown (KEY_DOWN)) {
		m_player->location.y -= 10 * delta_time;
	}

	if (IsKeyDown (KEY_LEFT_SHIFT)) {
		camera.zoom += 0.1 * delta_time;
		std::cout << camera.zoom << "\n";
	}
	else if (IsKeyDown (KEY_LEFT_CONTROL)) {
		camera.zoom -= 0.1 * delta_time;
		std::cout << camera.zoom << "\n";
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

	for (std::weak_ptr<Entity> entity : m_entity_manager.GetEntities ()) {
		entity.lock ()->Draw ();
	}

	EndMode2D ();

	EndDrawing ();
}