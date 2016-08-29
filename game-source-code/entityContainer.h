#ifndef ENTITY_CONTAINER_H
#define ENTITY_CONTAINER_H

#include "characterEntity.h"
#include "entity.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;
using entityIterator = list<shared_ptr<Entity>>::iterator;

class EntityContainer
{
public:
	entityIterator start_pos();
	entityIterator end_pos();
	void addEntity(shared_ptr<Entity> entityPointer);
	entityIterator removeEntity(entityIterator entity);
	int amountOfEntities() const;
	list<CharacterEntity> characterList();
	
private:
	list<shared_ptr<Entity>> _listOfEntities;
};

#endif