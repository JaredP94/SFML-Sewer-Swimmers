#ifndef GROUND_H
#define GROUND_H

#include "entityList.h"
#include "Entity.h"
#include "vector2f.h"
#include "movingEntity.h"
#include "rock.h"
#include "player.h"
#include "tunnelDigger.h"
#include <memory>
#include <ctime>
#include <cmath>

using std::shared_ptr;
using std::make_shared;

/**
* Ground class - represents the Ground tiles.
* Inherits from Entity class.
*/
class Ground: public Entity
{
public:
	/**
	* Constructor. Calls the Entity constructor explicitly and creates Ground object at a specific position.
	* @param x is a float containing horizontal creation coordinates.
	* @param y is a float containing vertical creation coordinates.
	*/
	Ground(float x, float y);
	/**
	* Inherited from Entity.
	* Creates square hitbox around Ground object through point assignments.
	* @return list of Vector2f containing hitbox points of Ground object.
	*/
	virtual list<Vector2f> hitboxPoints() override;
	/**
	* Inherited from Entity.
	* Ground object will be destroyed if collision occurs with a Player object.
	* @param collider is a shared pointer to Entity object which the Ground object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	static const auto _groundHeight = 32;
	static const auto _groundWidth = 32;
};

#endif