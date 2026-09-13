#pragma once
#include "Entities/Entity.h"
#include <chrono>
#include <concepts>
#include <iostream>
#include <memory>
#include <thread>
#include <type_traits>
#include <vector>

template <typename T>
concept EntityType = std::is_base_of_v<Entity, T>;

class EntityManager {
public:
	EntityManager ()
	{
		StartGarbageCollection ();
	}

	~EntityManager ()
	{
		EndGarbageCollection ();
	}

	template <EntityType E, typename... Args>
	std::shared_ptr<E> SpawnEntity (Args &&...args)
	{
		std::shared_ptr<E> new_entity = std::make_shared<E> (std::forward<Args> (args)...);
		m_entities.push_back (new_entity);
		return new_entity;
	}

	// TODO: think of a better name
	void CleanUpEntities ()
	{
		std::erase_if (m_entities, [] (const std::shared_ptr<Entity> &entity) {
			return entity->IsPendingKill ();
		});
	}

	// Again, terrible name. do better!
	void StartGarbageCollection ()
	{
		m_gc_running = true;
		m_gc_thread	 = std::thread (
			[this] () {
				while (m_gc_running) {
					CleanUpEntities ();
					std::cout << "Tick" << "\n";
					std::this_thread::sleep_for (std::chrono::seconds (1));
				}
			});
	}

	void EndGarbageCollection ()
	{
		m_gc_running = false;
		m_gc_thread.join ();
	}

private:
	std::vector<std::shared_ptr<Entity>> m_entities	  = {};
	volatile bool						 m_gc_running = false;
	std::thread							 m_gc_thread;
};