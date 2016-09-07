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

void Entity::setCentre()
{
	_position._x = _positionBounds._x / 2;
	_position._y = _positionBounds._y / 2;
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

float Entity::positionGeneration(float positionBounds, float entitySize) const
{
	auto tmp = static_cast<int>(positionBounds - entitySize); //assuming height == width
	auto rand_num = rand()%tmp;
	return static_cast<float>(rand_num);
}

Vector2f Entity::_positionBounds = Vector2f(1000, 800);