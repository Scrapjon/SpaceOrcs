#pragma once
#include "Entities/Entity.h"
#include <concepts>
#include <iostream>
#include <list>
#include <memory>
#include <type_traits>

template <typename T>
concept EntityType = std::is_base_of_v<Entity, T>;

class EntityManager {
public:
	template <EntityType E, typename... Args>
	std::shared_ptr<Entity> SpawnEntity (Args &&...args)
	{
		std::shared_ptr<Entity> new_entity = std::make_unique<E> (std::forward<Args> (args)...);
		m_entities.push_back (new_entity);
		return new_entity;
	}

	// TODO: think of a better name, also maybe use a std::list instead bc std::erase can get expensive (I believe this is already O(n^2), yeesh)
	void CleanUpEntities ()
	{

		using Iterator = decltype (m_entities)::iterator;

		for (Iterator it = m_entities.begin (); it != m_entities.end ();) {
			std::weak_ptr<Entity> entity = *it;

			if (entity.expired ()) {
				it = m_entities.erase (it);
				continue;
			}

			if (entity.lock ()->IsPendingKill ()) {
				it = m_entities.erase (it);
				continue;
			}
			++it;
		}
	}

private:
	std::list<std::shared_ptr<Entity>> m_entities = {};
};