#include "harpoon.h"

Harpoon::Harpoon(const Vector2f& position, const Vector2f& velocity_unit_direction):
	MovingEntity(EntityList::Harpoon, position, velocity_unit_direction * _harpoon_speed)
	{}
	
void Harpoon::collide(const shared_ptr<Entity>& collider)
{
	switch(collider->getEntityKey())
	{
		case EntityList::Ground:
			destroy();
			break;
		case EntityList::Enemy:
			destroy();
			break;
		default:
			break;
	}
}
	
list<Vector2f> Harpoon::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _harpoon_width, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _harpoon_width, top_left._y - _harpoon_height));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _harpoon_height));
	return hitbox_coords;
}

void Harpoon::move(float changeInTime)
{
	setPosition(getSpeed()._x * changeInTime, getSpeed()._y * changeInTime);
	_elapsed_distance += Vector2f(getSpeed()._x * changeInTime, getSpeed()._y * changeInTime);
	if(getPosition()._x == getMapBounds()._x || getPosition()._x == 0.f || getPosition()._y == getMapBounds()._y || getPosition()._y == 0.f || _elapsed_distance._x <= -64 || _elapsed_distance._x >= 64 || _elapsed_distance._y <= -64 || _elapsed_distance._y >= 64)
	{
		destroy();
	}
}
