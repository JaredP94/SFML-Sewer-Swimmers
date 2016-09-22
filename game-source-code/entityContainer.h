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

/**
* EntityContainer class - handles all Entity objects which are active in the game.
* Class stores a multitude of shared pointers to each of the Entity objects which are active in game. 
* Has the ability to modify the collosection of shared pointers.
*/
class EntityContainer
{
public:
	/**
	* Returns start position of vector of Entity objects.
	* @return entityIterator positioned at beginning of Entity objects vector.
	*/
	entityIterator start_pos();
	/**
	* Returns end position of vector of Entity objects.
	* @return entityIterator positioned at end of Entity objects vector.
	*/
	entityIterator end_pos();
	/**
	* Adds an addtional shared pointer to an Entity object to the vector of Entity objects.
	* @param entityPointer is the shared pointer to the Entity object which needs to be added.
	*/
	void addEntity(shared_ptr<Entity> entityPointer);
	/**
	* Removes shared pointer of a specific Entity object from the vector of Entity objects.
	* @param entity is an entityIterator which specifies the required Entity object required to be removed.
	* @return entityIterator which points to the position of the next Entity object in the vector of Entity objects.
	*/
	entityIterator removeEntity(entityIterator entity);
	/**
	* Returns amount of Entity objects in vector of Entity objects.
	* @return int containing number of existing Entity objects.
	*/
	int amountOfEntities() const;
	/**
	* Creates a vector of characterEntity objects from the vector of Entity objects for the Interface to render.
	* @return vector of CharacterEntity objects which are mapped to each existing Entity object.
	*/
	vector<CharacterEntity> characterList();
	
private:
	vector<shared_ptr<Entity>> _listOfEntities;
};

#endif