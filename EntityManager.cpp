#include "EntityManager.h"

#include <algorithm>

EntityManager::EntityManager()
{
}

void EntityManager::update()
{
	for (auto& e : m_entitiesToAdd)
	{
		m_entities.push_back(e);
		m_entitiesMap[e->m_tag].push_back(e);
	}

	m_entitiesToAdd.clear();

	removeDeadEntites(m_entities);

	for (auto& [tag, entityVec] : m_entitiesMap)
	{
		removeDeadEntites(entityVec);
	}

}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
	m_entitiesToAdd.push_back(entity);
	return entity;
}

void EntityManager::removeDeadEntites(EntityVec& vec)
{
	auto n_end = std::remove_if(begin(vec), end(vec),
		[](std::shared_ptr<Entity>& e)
		{
			return (!e->isActive());
		}
	);

	vec.erase(n_end, end(vec));
}

const EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag)
{
	return m_entitiesMap[tag];
}


