#ifndef CHARACTER_ENTITY_H
#define CHARACTER_ENTITY_H

#include "entityList.h"
#include "vector2f.h"

/** 
* CharacterEntity class - visual representation of an Entity object.
* Used to separate Logic from Interface by giving the Interface only the necessary information for an Entity object to be rendered
*/
class CharacterEntity
{
public:
	/**
	* Constructor.
	* @param entityKey is the Entity identifier which categorises the required texture of the CharacterEntity which is to be rendered by the Interface.
	* @param position is a Vector2f which stores the coordinates of the CharacterEntity which is to be rendered by the Interface. Assumes positive values are entered.
	*/
	CharacterEntity(EntityList entityKey, const Vector2f& position);
	/**
	* Returns the identifier of the character.
	* @return an EntityList identifier for the character.
	*/
	EntityList getEntityKey() const;
	/**
	* Returns the coordinates of the character.
	* @return a Vector2f containing character coordinates. Should be positive values.
	*/
	Vector2f getPosition() const;
	
private:
	EntityList _entityKey;
	Vector2f _position;
	
};

#endif