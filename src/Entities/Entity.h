#pragma once

#include "OrcMath.h"
#include <concepts>
#include <type_traits>

class Entity {
public:
	Entity () = default;
	Vector2D location{ 0, 0 };

	virtual void Tick (float delta_time)
	{
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

private:
	bool m_pending_kill = false;
};