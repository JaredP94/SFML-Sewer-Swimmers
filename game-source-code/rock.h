#ifndef ROCK_H
#define ROCK_H

#include "movingEntity.h"
#include "vector2f.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;

class Rock: public MovingEntity
{
public:
	Rock(float x, float y);
	Vector2f positionChange();
	static int getGroundDestroyed() {return _groundDestroyed;};
	static void setGroundDestroyed() {_groundDestroyed++;};
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	bool _moving = true;
	float _elapsed_time_since_update = 1.0f;
	Vector2f _elapsed_distance = Vector2f(0, 0);
	static int _groundDestroyed;
	static const auto _rockHeight = 28;
	static const auto _rockWidth = 28;
	static constexpr const auto _rockSpeed = 10.0;
	Vector2f _speed;
};

#endif