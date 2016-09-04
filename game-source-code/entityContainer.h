#ifndef ENTITY_CONTAINER_H
#define ENTITY_CONTAINER_H

#include "characterEntity.h"
#include "entity.h"
#include <list>
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using entityIterator = vector<shared_ptr<Entity>>::iterator;

class EntityContainer
{
public:
	entityIterator start_pos();
	entityIterator end_pos();
	void addEntity(shared_ptr<Entity> entityPointer);
	entityIterator removeEntity(entityIterator entity);
	int amountOfEntities() const;
	vector<CharacterEntity> characterList();
	
private:
	vector<shared_ptr<Entity>> _listOfEntities;
};

#endif