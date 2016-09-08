#include "enemy.h"

Enemy::Enemy():
	MovingEntity{EntityList::Enemy, Vector2f(positionGeneration(getMapBounds()._x, _enemyWidth), positionGeneration(getMapBounds()._y - 192, _enemyHeight) + 192), Vector2f(_enemySpeed, _enemySpeed)}
	{
		directionAssignment();
	}

Enemy::Enemy(const Vector2f& position):
	MovingEntity{EntityList::Enemy, Vector2f(position._x, position._y), Vector2f(_enemySpeed, _enemySpeed)}
	{
		directionAssignment();
	}
	
Enemy::~Enemy()
{
	_enemy_destroyed++;
}

void Enemy::move(float changeInTime)
{
	Vector2f velocity_unit_direction;
	if(getDirection() == Direction::Up)
	{
		velocity_unit_direction = Vector2f(0,-1);
	}
	else if(getDirection() == Direction::Down)
	{
		velocity_unit_direction = Vector2f(0,1);
	}
	else if(getDirection() == Direction::Left)
	{
		velocity_unit_direction = Vector2f(-1,0);
	}
	else
	{
		velocity_unit_direction = Vector2f(1,0);
	}
	setPosition(getSpeed()._x * changeInTime * velocity_unit_direction._x, getSpeed()._y * changeInTime * velocity_unit_direction._y);
	if(getPosition()._x >= getMapBounds()._x - _enemyWidth|| getPosition()._x == 0.f || getPosition()._y >= getMapBounds()._y - _enemyHeight || getPosition()._y <= 150.f)
	{
		Collision();
	}
}

list<Vector2f> Enemy::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _enemyWidth, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _enemyWidth, top_left._y - _enemyHeight));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _enemyHeight));
	return hitbox_coords;
}

void Enemy::collide(const shared_ptr<Entity>& collider)
{
	switch(collider->getEntityKey())
	{
		case EntityList::Ground:
			Collision();
			break;
		case EntityList::Harpoon:
			destroy();
		default:
			break;
	}
}

void Enemy::Collision()
{
	if(getDirection() == Direction::Up)
	{
		setPosition(0,2);
		directionChange(Direction::Left);
	}
	else if(getDirection() == Direction::Down)
	{
		setPosition(0,-2);
		directionChange(Direction::Right);
	}
	else if(getDirection() == Direction::Left)
	{
		setPosition(2,0);
		directionChange(Direction::Down);
	}
	else
	{
		setPosition(-2,0);
		directionChange(Direction::Up);
	}
}

int Enemy::_enemy_destroyed = 0;

int Enemy::_enemies_created = 0;