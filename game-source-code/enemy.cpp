#include "enemy.h"

Enemy::Enemy():
	MovingEntity{EntityList::Enemy, Vector2f(positionGeneration(getMapBounds()._x), positionGeneration(getMapBounds()._y)), Vector2f(_enemySpeed, _enemySpeed)}
	{
		_enemy_quantity++;
	}
	
Enemy::~Enemy()
{
	_enemy_quantity--;
}

/*void Player::directionChange(Direction direction)
{
	switch(static_cast<int>(direction))
	{
		case 0:
			_up = true;
			_down = false;
			_left = false;
			_right = false;
		case 1:
			_up = false;
			_down = false;
			_left = true;
			_right = false;
		case 2:
			_up = false;
			_down = true;
			_left = false;
			_right = false;
		case 3:
			_up = false;
			_down = false;
			_left = false;
			_right = true;
		default:
			break; //shouldn't get here
	}
}*/

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
		_speed = Vector2f(positionGeneration(getMapBounds()._x) - getPosition()._x, positionGeneration(getMapBounds()._y) - getPosition()._y).unitVector();
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
			break;
		case EntityList::Harpoon:
			destroy();
		default:
			break;
	}
}

float Enemy::positionGeneration(float positionBounds) const
{
	auto tmp = static_cast<int>(positionBounds - _enemyHeight); //assuming height == width
	auto rand_num = rand()%tmp;
	return static_cast<float>(rand_num);
}

int Enemy::_enemy_quantity = 0;