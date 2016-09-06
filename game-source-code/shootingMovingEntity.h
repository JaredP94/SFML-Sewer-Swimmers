#ifndef SHOOTINGMOVINGENTITY_H
#define SHOOTINGMOVINGENTITY_H

#include "movingEntity.h"
#include "entityList.h"
#include "vector2f.h"

class ShootingMovingEntity: public MovingEntity
{
public:
	ShootingMovingEntity(EntityList entityID, Vector2f position, Vector2f speed);
	virtual shared_ptr<MovingEntity> shoot(float changeInTime) = 0;
	virtual void move(float changeInTime) override = 0;
	virtual list<Vector2f> hitboxPoints() override = 0;
	virtual void collide(const shared_ptr<Entity>& collider) override = 0;
};

#endif