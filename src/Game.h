#pragma once

#include "Audio/AudioEngine.h"
#include "Entities/Ship.h"
#include "EntityManager.h"
#include "OrcMath.h"
#include <iostream>
#include <memory>
#include <raylib.h>
#include <thread>
#include <vector>

#define GAME_TITLE "Space Orcs: Orcs from Space"

class Game {

private:
	Game ()
	{
		InitWindow (800, 800, GAME_TITLE);
		SetTargetFPS (m_fps);
		m_entity_manager.SpawnEntity<Ship> ();
	}

	~Game ()
	{
	}

	float		  m_fps			   = 60;
	bool		  m_should_quit	   = false;
	EntityManager m_entity_manager = {};

public:
	static Camera2D camera;

	Game (const Game &)			   = delete;
	Game &operator= (const Game &) = delete;

	static Game &getInstance ()
	{
		static Game instance;
		return instance;
	}

	inline bool ShouldQuit () const
	{
		return m_should_quit;
	}

	inline float GetDeltaTime () const
	{
		return GetFrameTime ();
	}

	void Tick ();

	void HandleInputs (float delta_time);

	void Draw ();
};
