#include "entityContainer.h"

entityIterator EntityContainer::start_pos()
{
	return _listOfEntities.begin();
}

entityIterator EntityContainer::end_pos()
{
	return _listOfEntities.end();
}

void EntityContainer::addEntity(shared_ptr<Entity> entityPointer)
{
	if(entityPointer)
	{
		_listOfEntities.push_back(entityPointer);
	}
}

entityIterator EntityContainer::removeEntity(entityIterator entity)
{
	return _listOfEntities.erase(entity);
}

int EntityContainer::amountOfEntities() const
{
	return _listOfEntities.size();
}

vector<CharacterEntity> EntityContainer::characterList()
{
	vector<CharacterEntity> list_of_characters;
	for(auto entityPointer : _listOfEntities)
	{
		list_of_characters.push_back(entityPointer->character());
	}
	return list_of_characters;
}