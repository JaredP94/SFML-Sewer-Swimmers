#include "player.h"

Player::Player():
	ShootingMovingEntity{EntityList::Player, Vector2f(getMapBounds()._x/2 - _playerWidth/2, getMapBounds()._y/2 - _playerHeight/2), Vector2f(_playerSpeed, _playerSpeed)},
	_positionChange{0, 0}
	{}

void Player::movement(GameEvent event)
{
	if(!_moving)
	{
		switch(event)
		{
			case GameEvent::Press_W:
				if(!_shooting) 
				{
					_moving = true;
					directionChange(Direction::Up);
				}
				break;
			case GameEvent::Press_A:
				if(!_shooting)
				{
					_moving = true;
					directionChange(Direction::Left);
				}
				break;
			case GameEvent::Press_S:
				if(!_shooting)
				{ 
					_moving = true;
					directionChange(Direction::Down);
				}
				break;
			case GameEvent::Press_D:
				if(!_shooting) 
				{
					_moving = true;
					directionChange(Direction::Right);
				}
				break;
			default:
				break;
		}
	}
	
	if(getDirection() == Direction::Up && event == GameEvent::Release_W)
	{
		_moving = false;
	}
	
	if(getDirection() == Direction::Down && event == GameEvent::Release_S)
	{
		_moving = false;
	}
	
	if(getDirection() == Direction::Left && event == GameEvent::Release_A)
	{
		_moving = false;
	}
	
	if(getDirection() == Direction::Right && event == GameEvent::Release_D)
	{
		_moving = false;
	}
}

Vector2f Player::positionChange()
{
	Vector2f new_position = _positionChange;
	_positionChange = Vector2f(0, 0);
	return new_position;
}

int Player::getNumberOfLives()
{
	return _lives;
}

void Player::move(float changeInTime)
{
	Vector2f past_pos = getPosition();
	auto distance = changeInTime * getSpeed();
	if(getDirection() == Direction::Up && _moving)
	{
		if(getPosition()._y - distance._y >= 150)
		{
			setPosition(0.f, -distance._y);
		}
		else
		{
			setPosition(0.f, 0.f);
		}
	}
	if(getDirection() == Direction::Down && _moving)
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
	if(getDirection() == Direction::Left && _moving)
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
	if(getDirection() == Direction::Right && _moving)
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
			this->setCentre();
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
		case GameEvent::Press_Space:
			_shooting = true;
			_moving = false;
			break;
		case GameEvent::Release_Space:
			_shooting = false;
			break;
		default:
			break;
	}
}

shared_ptr<MovingEntity> Player::shoot(float changeInTime)
{
	while(Harpoon::getHarpoonStatus() < 1 && _shooting)
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
		return make_shared<Harpoon> (getPosition(), velocity_unit_direction);
	}
	return shared_ptr<MovingEntity> (nullptr);
}

bool Player::_shooting = false;