#ifndef MOVING_ENTITY_H
#define MOVING_ENTITY_H

#include "entity.h"
#include "entityList.h"
#include "vector2f.h"
#include <list>

using std::list;

class MovingEntity: public Entity
{
public:
	MovingEntity(EntityList entityKey, Vector2f position, Vector2f speed);
	virtual void move(float changeInTime) = 0;
	virtual list<Vector2f> hitboxPoints() = 0;
	virtual void collide(const shared_ptr<Entity>& collider) override = 0;
	Vector2f getSpeed() const;
	
private:
	Vector2f _speed;
	
};

#endif