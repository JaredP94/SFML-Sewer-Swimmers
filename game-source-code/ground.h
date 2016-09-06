#ifndef GROUND_H
#define GROUND_H

#include "entityList.h"
#include "Entity.h"
#include "vector2f.h"
#include "movingEntity.h"
#include <memory>
#include <ctime>
#include <cmath>

using std::shared_ptr;
using std::make_shared;

class Ground: public Entity
{
public:
	Ground(float x, float y);
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
protected:
	float positionGeneration(float positionBounds) const;
	
private:
	static const auto _groundHeight = 32;
	static const auto _groundWidth = 32;
};

#endif