#include "enemy.h"

Enemy::Enemy():
	MovingEntity{EntityList::Enemy, Vector2f(positionGeneration(getMapBounds()._x, _enemyWidth), positionGeneration(getMapBounds()._y - 192, _enemyHeight) + 192), Vector2f(_enemySpeed, _enemySpeed)}
	{}

Enemy::Enemy(const Vector2f& position):
	MovingEntity{EntityList::Enemy, Vector2f(position._x, position._y), Vector2f(_enemySpeed, _enemySpeed)}
	{}
	
Enemy::~Enemy()
{
	_enemy_destroyed++;
}

bool Enemy::faceUp() const
{
	return _up;
}

bool Enemy::faceDown() const
{
	return _down;
}

bool Enemy::faceLeft() const
{
	return _left;
}

bool Enemy::faceRight() const
{
	return _right;
}

void Enemy::move(float changeInTime)
{
	_elapsed_time_since_update += changeInTime;
	if(_elapsed_time_since_update >= 1.0f)
	{
		_speed = Vector2f(positionGeneration(getMapBounds()._x, _enemyWidth) - getPosition()._x, positionGeneration(getMapBounds()._y, _enemyHeight) - getPosition()._y).unitVector();
		_elapsed_time_since_update = 0.f;
	}
	setPosition(getSpeed()._x * changeInTime * _speed._x, getSpeed()._y * changeInTime * _speed._y);
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
		case EntityList::Player:
			break;
		case EntityList::Ground:
			groundCollision();
			break;
		case EntityList::Harpoon:
			destroy();
		default:
			break;
	}
}

void Enemy::groundCollision()
{
	setPosition(0,0);
}

int Enemy::_enemy_destroyed = 0;

int Enemy::_enemies_created = 0;