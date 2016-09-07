#include "movingEntity.h"

MovingEntity::MovingEntity(EntityList entityKey, Vector2f position, Vector2f speed):
	Entity{entityKey, position},
	_speed{speed}
	{}

Vector2f MovingEntity::getSpeed() const
{
	return _speed;
}

void MovingEntity::directionChange(Direction direction)
{
	switch(static_cast<int>(direction))
	{
		case 0:
			_facing = Direction::Up;
			break;
		case 1:
			_facing = Direction::Left;
			break;
		case 2:
			_facing = Direction::Down;
			break;
		case 3:
			_facing = Direction::Right;
			break;
		default:
			break; //shouldn't get here
	}
}

Direction MovingEntity::getDirection()
{
	return _facing;
}