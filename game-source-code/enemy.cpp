#include "enemy.h"

Enemy::Enemy():
	MovingEntity{EntityList::Enemy, Vector2f(50,50), Vector2f(_playerSpeed, _playerSpeed)},
	_positionChange{0, 0}
	{}

Vector2f Enemy::positionChange()
{
	Vector2f new_position = _positionChange;
	_positionChange = Vector2f(0, 0);
	return new_position;
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
	Vector2f past_pos = getPosition();
	auto distance = changeInTime * getSpeed();
	if(_up)
	{
		if(getPosition()._y - distance._y > 0)
		{
			setPosition(0.f, -distance._y);
		}
		else
		{
			setPosition(0.f, 0.f);
		}
//		directionChange(Direction::Up);
	}
	if(_down)
	{
		if(getPosition()._y + distance._y + _playerHeight< getMapBounds()._y)
		{
			setPosition(0.f, distance._y);
		}
		else
		{
			setPosition(0.f, getMapBounds()._y - _playerHeight - getPosition()._y);
		}
//		directionChange(Direction::Down);
	}
	if(_left)
	{
		if(getPosition()._x - distance._x > 0)
		{
			setPosition(-distance._x, 0.f);
		}
		else
		{
			setPosition(0.f, 0.f);
		}
//		directionChange(Direction::Left);
	}
	if(_right)
	{
		if(getPosition()._x + distance._x + _playerWidth < getMapBounds()._x)
		{
			setPosition(distance._x, 0.f);
		}
		else
		{
			setPosition(getMapBounds()._x - _playerWidth - getPosition()._x, 0.f);
		}
//		directionChange(Direction::Right);
	}
	_positionChange = getPosition() - past_pos;
}

void Enemy::movement(GameEvent event)
{
	switch(event)
	{
		case GameEvent::Press_W:
			_up = true;
			break;
		case GameEvent::Press_A:
			_left = true;
			break;
		case GameEvent::Press_S:
			_down = true;
			break;
		case GameEvent::Press_D:
			_right = true;
			break;
		case GameEvent::Release_W:
			_up = false;
			break;
		case GameEvent::Release_A:
			_left = false;
			break;
		case GameEvent::Release_S:
			_down = false;
			break;
		case GameEvent::Release_D:
			_right = false;
			break;
		default:
			break;
	}
}

list<Vector2f> Enemy::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _playerWidth, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _playerWidth, top_left._y - _playerHeight));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _playerHeight));
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
		default:
			break;
	}
}
