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

	/*
		I would like a more efficient way to do this without creating a copy each time I call this 
		but it's the only way to enforce weak_ptr by default

		Probably would be worth even making it shared by default however I want the EntityManager to be the source of truth for 
		lifetimes, while still allowing for locking so that functions can extend the lifetime until they are done with the object.

	*/
	std::vector<std::weak_ptr<Entity>> GetEntities() const { 
		std::vector<std::weak_ptr<Entity>> weak_entities;
		weak_entities.reserve(m_entities.size());
		for (std::weak_ptr<Entity> weak_entity : m_entities) {
			weak_entities.push_back(weak_entity);
		}

		return weak_entities;
	}

	/* 	TODO: think of a better name
		Also maybe rethink having this as a threaded thing. Could probably be more of a performance hit having it this way 
		with a mutex than having it just on the main thread.
	*/
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
		std::cout << "Ending garbage collection...\n";
		m_gc_thread.join ();
		std::cout << "Garbage collection ended!\n";
	}

private:
	std::vector<std::shared_ptr<Entity>> m_entities	  = {};
	volatile bool						 m_gc_running = false;
	std::thread							 m_gc_thread;
};