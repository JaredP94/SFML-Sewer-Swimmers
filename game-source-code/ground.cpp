#include "ground.h"

Ground::Ground(float x, float y):
	Entity{EntityList::Ground, Vector2f(x, y)}
	{};

list<Vector2f> Ground::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _groundWidth, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _groundWidth, top_left._y - _groundHeight));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _groundHeight));
	return hitbox_coords;
}

void Ground::collide(const shared_ptr<Entity>& collider)
{
	switch(collider->character().getEntityKey())
	{
		case EntityList::Player:
			destroy();
			Player::addScore(25);
			break;
		case EntityList::TunnelDigger:
			destroy();
			break;
		case EntityList::Rock:
			if(Rock::getGroundDestroyed() <= 2)
			{
				destroy();
				Rock::setGroundDestroyed();
			}
			break;
		default:
			break;
	}
}
