#include "tunnelDigger.h"

TunnelDigger::TunnelDigger(float x, float y):
	MovingEntity{EntityList::TunnelDigger, Vector2f(x, y), Vector2f(_diggerSpeed, _diggerSpeed)}
	{
		_digger_quantity++;
		directionAssignment();
	}
	
TunnelDigger::TunnelDigger(const Vector2f& position):
	MovingEntity{EntityList::TunnelDigger, Vector2f(position._x, position._y), Vector2f(_diggerSpeed, _diggerSpeed)}
	{
		_digger_quantity++;
		directionAssignment();
	}
	
TunnelDigger::~TunnelDigger()
{
	_digger_quantity--;
}

void TunnelDigger::move(float changeInTime)
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
	_elapsed_distance += Vector2f(getSpeed()._x * changeInTime, getSpeed()._y * changeInTime);
	if(getPosition()._x == getMapBounds()._x || getPosition()._x == 0.f || getPosition()._y == getMapBounds()._y || getPosition()._y <= 200.f || _elapsed_distance._x <= -160 || _elapsed_distance._x >= 160 || _elapsed_distance._y <= -160 || _elapsed_distance._y >= 160)
	{
		destroy();
	}
}

list<Vector2f> TunnelDigger::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _diggerWidth, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _diggerWidth, top_left._y - _diggerHeight));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _diggerHeight));
	return hitbox_coords;
}

void TunnelDigger::collide(const shared_ptr<Entity>& collider)
{}

void TunnelDigger::directionAssignment()
{
	srand(time(0));
	unsigned int random = std::rand() % 5;
	switch(random)
	{
		case 1:
			directionChange(Direction::Up);
			break;
		case 2:
			directionChange(Direction::Left);
			break;
		case 3:
			directionChange(Direction::Down);
			break;
		case 4:
			directionChange(Direction::Right);
			break;
		default:
			break;
	}
}

int TunnelDigger::_digger_quantity = 0;