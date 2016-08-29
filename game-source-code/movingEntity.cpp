#include "movingEntity.h"

MovingEntity::MovingEntity(EntityList entityKey, Vector2f position, Vector2f speed):
	Entity{entityKey, position},
	_speed{speed}
	{}

Vector2f MovingEntity::getSpeed() const
{
	return _speed;
}