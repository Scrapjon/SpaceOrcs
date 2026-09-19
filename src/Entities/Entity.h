#pragma once

#include "OrcMath.h"
#include <concepts>
#include <type_traits>

class Entity {
public:
	Entity (Vector2D location = { 0, 0 }) : location (location)
	{
	}

	Vector2D location{ 0, 0 };

	virtual void Update (float delta_time)
	{
		UpdateBounds ();
	}

	virtual void Draw () = 0;

	void Despawn ()
	{
		m_pending_kill = true;
	}

	inline bool IsPendingKill () const
	{
		return m_pending_kill;
	}

	void SetBounds (const float width, const float height);

	void UpdateBounds ();

	inline Rectangle GetBounds ()
	{
		return m_bounds;
	}

private:
	bool	  m_pending_kill = false;
	Rectangle m_bounds;
};