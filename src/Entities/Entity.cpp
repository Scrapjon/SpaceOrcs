#include "Entities/Entity.h"
#include "Game.h"

void Entity::SetBounds (const float width, const float height)
{
	Vector2D top_left = {
		location.x + (width * 0.5f),
		location.y + (height * 0.5f)
	};

	m_bounds = Rectangle{ top_left.x, top_left.y, width, height };
}

void Entity::UpdateBounds ()
{
	SetBounds (m_bounds.width, m_bounds.height);
}
