#include "characterEntity.h"

CharacterEntity::CharacterEntity(EntityList entityKey, const Vector2f& position):
	_entityKey{entityKey},
	_position{position}
	{}

EntityList CharacterEntity::getEntityKey() const
{
	return _entityKey;
}

Vector2f CharacterEntity::getPosition() const
{
	return _position;
}