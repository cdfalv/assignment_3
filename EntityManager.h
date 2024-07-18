#pragma once

#include "Entity.h"

#include <map>
#include <memory>
#include <vector>

typedef std::vector<std::shared_ptr<Entity>>	EntityVec;
typedef std::map<std::string, EntityVec>		EntityMap; // map from entity tag to vecrors


class EntityManager
{
private:
	EntityVec m_entities;
	EntityVec m_entitiesToAdd;		// queue of entities to be added duting next update
	EntityMap m_entitiesMap;		// map from entity tag to vectors
	uint64_t  m_totalEntities = 0;  // total entities created

	void removeDeadEntites(EntityVec& vec);

public:
	EntityManager();
	const EntityVec& getEntities();
	const EntityVec& getEntities(const std::string& tag);


	std::shared_ptr<Entity> addEntity(const std::string& tag);
	void update();
};

