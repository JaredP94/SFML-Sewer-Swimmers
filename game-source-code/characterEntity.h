#ifndef CHARACTER_ENTITY_H
#define CHARACTER_ENTITY_H

#include "entityList.h"
#include "vector2f.h"

class CharacterEntity
{
public:
	CharacterEntity(EntityList entityKey, const Vector2f& position);
	EntityList getEntityKey() const;
	Vector2f getPosition() const;
	
private:
	EntityList _entityKey;
	Vector2f _position;
	
};

#endif