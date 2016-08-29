#include "entity.h"

Entity::Entity(EntityList entityKey, Vector2f position):
	_entityKey{entityKey},
	_position{position}
	{}
	
CharacterEntity Entity::character() const
{
	return CharacterEntity(_entityKey, _position);
}
	
void Entity::setMapBounds(const Vector2f& maxBounds)
{
	_positionBounds = maxBounds;
}
	
Vector2f Entity::getMapBounds()
{
	return _positionBounds;
}
	
Vector2f Entity::getPosition() const
{
	return _position;
}
	
EntityList Entity::getEntityKey() const
{
	return _entityKey;
}
	
bool Entity::checkIfDestroyed() const
{
	return _destroyed;
}
	
void Entity::destroy()
{
	_destroyed = true;
}

void Entity::setPosition(const Vector2f& positionChange)
{
	if(_position._x + positionChange._x > _positionBounds._x || _position._x + positionChange._x < 0.0 || _position._y + positionChange._y > _positionBounds._y || _position._y + positionChange._y < 0.0)
	{
		if(_position._x + positionChange._x > _positionBounds._x || _position._x + positionChange._x < 0.0)
		{
			_position._y += positionChange._y;
			if(_position._x + positionChange._x >= _positionBounds._x)
			{
				_position._x += _positionBounds._x - _position._x;
			}
			else{
				_position._x += 0.0 - _position._x;
			}
		}
		if(_position._y + positionChange._y > _positionBounds._y || _position._y + positionChange._y < 0.0)
		{
			_position._y += positionChange._y;
			if(_position._y + positionChange._y >= _positionBounds._y)
			{
				_position._y += _positionBounds._y - _position._y;
			}
			else
			{
				_position._y += 0.0 - _position._y;
			}
		}
	}
	else
	{
		_position += positionChange;
	}
}

void Entity::setPosition(float x, float y)
{
	Vector2f temp_position(x,y);
	setPosition(temp_position);
}

Vector2f Entity::_positionBounds = Vector2f(800, 600);