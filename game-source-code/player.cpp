#include "player.h"

Player::Player():
	ShootingMovingEntity{EntityList::Player, Vector2f(getMapBounds()._x/2 - _playerWidth/2, getMapBounds()._y/2 - _playerHeight/2), Vector2f(_playerSpeed, _playerSpeed)},
	_positionChange{0, 0}
	{}

void Player::movement(GameEvent event)
{
	switch(event)
	{
		case GameEvent::Press_W:
			_up = true;
			directionChange(Direction::Up);
			break;
		case GameEvent::Press_A:
			_left = true;
			directionChange(Direction::Left);
			break;
		case GameEvent::Press_S:
			_down = true;
			directionChange(Direction::Down);
			break;
		case GameEvent::Press_D:
			_right = true;
			directionChange(Direction::Right);
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

Vector2f Player::positionChange()
{
	Vector2f new_position = _positionChange;
	_positionChange = Vector2f(0, 0);
	return new_position;
}

void Player::directionChange(Direction direction)
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

bool Player::faceUp() const
{
	return _up;
}

bool Player::faceDown() const
{
	return _down;
}

bool Player::faceLeft() const
{
	return _left;
}

bool Player::faceRight() const
{
	return _right;
}

int Player::getNumberOfLives()
{
	return _lives;
}

void Player::move(float changeInTime)
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
	}
	_positionChange = getPosition() - past_pos;
}

list<Vector2f> Player::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _playerWidth, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _playerWidth, top_left._y - _playerHeight));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _playerHeight));
	return hitbox_coords;
}

void Player::collide(const shared_ptr<Entity>& collider)
{
	switch(collider->getEntityKey())
	{
		case EntityList::Enemy:
			_lives--;
			std::cout << _lives << std::endl;
			this->setPosition(getMapBounds()._x/2 - _playerWidth/2, getMapBounds()._y/2 - _playerHeight/2);
			if(_lives == 0)
			{
				destroy();
			}
			break;
		case EntityList::Ground:
			break;
		default:
			break;
	}
}

void Player::shooting(GameEvent event)
{
	switch(event)
	{
		case GameEvent::Press_E:
			_launch_harpoon = true;
			break;
		case GameEvent::Release_E:
			_launch_harpoon = false;
			break;
		default:
			break;
	}
}

shared_ptr<MovingEntity> Player::shoot(float changeInTime)
{
	if(_launch_harpoon)
	{
		_launch_harpoon = false;
		Vector2f velocity_unit_direction;
		if(_facing == Direction::Up)
		{
			velocity_unit_direction = Vector2f(0,-1);
		}
		else if(_facing == Direction::Down)
		{
			velocity_unit_direction = Vector2f(0,1);
		}
		else if(_facing == Direction::Left)
		{
			velocity_unit_direction = Vector2f(-1,0);
		}
		else
		{
			velocity_unit_direction = Vector2f(1,0);
		}
		return make_shared<Harpoon> (getPosition(), velocity_unit_direction);
	}
	return shared_ptr<MovingEntity> (nullptr);
}
