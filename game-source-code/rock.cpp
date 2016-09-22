#include "rock.h"

Rock::Rock(float x, float y):
	MovingEntity{EntityList::Rock, Vector2f(x, y), Vector2f(_rockSpeed, _rockSpeed)}
	{}

void Rock::move(float changeInTime)
{
	Vector2f velocity_unit_direction;
	if(_timer) this->addTimeElapsed(changeInTime);
	if(!_timer) this->resetTimeElapsed();
	if(getMovingStatus())
	{
		velocity_unit_direction = Vector2f(0,1);
	}
	else
	{
		velocity_unit_direction = Vector2f(0,0);
	}
	setPosition(getSpeed()._x * changeInTime * velocity_unit_direction._x, getSpeed()._y * changeInTime * velocity_unit_direction._y);
	_elapsed_distance += Vector2f(getSpeed()._x * changeInTime, getSpeed()._y * changeInTime);
	if(getPosition()._y >= getMapBounds()._y - _rockHeight)
	{
		destroy();
	}
}

list<Vector2f> Rock::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _rockWidth, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _rockWidth, top_left._y - _rockHeight));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _rockHeight));
	return hitbox_coords;
}

void Rock::collide(const shared_ptr<Entity>& collider)
{
	switch(collider->character().getEntityKey())
	{
		case EntityList::Ground:
			if(_groundDestroyed >= 2) 
			{
				setMovingStatus(false);
				if(this->getTimeElapsed() >= 1.5) destroy();
				_timer = false;
				setPosition(0,-1.75);
			}
			break;
		case EntityList::Player:
			setMovingStatus(false);
			_timer = true;
			break;
		default:
				if(!_timer || getTimeElapsed() >= 1.5) setMovingStatus(true);
				else setMovingStatus(false);
			break;
	}
}

int Rock::_groundDestroyed = 0;