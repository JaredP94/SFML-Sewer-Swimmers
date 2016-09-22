#ifndef ROCK_H
#define ROCK_H

#include "movingEntity.h"
#include "vector2f.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;

/**
* Rock class - represents the Rock objects in the game.
* Inherits from MovingEntity class.
*/
class Rock: public MovingEntity
{
public:
	/**
	* Constructor. Calls the MovingEntity constructor explicitly and creates a Rock object at a specific position on the map.
	* @param x is a float which contains the horizontal creation coordinates.
	* @param y is a flaot which contains the vertical creation coordinates.
	*/
	Rock(float x, float y);
	/**
	* Static function. Returns amount of Ground objects that have been destroyed by Rock object.
	* @return int containing number of Ground objects destroyed.
	*/
	static int getGroundDestroyed() {return _groundDestroyed;};
	/**
	* Static function. Increases number of Ground objects that have been destroyed by Rock object.
	*/
	static void setGroundDestroyed() {_groundDestroyed++;};
	/**
	* Inherited from MovingEntity.
	* Moves Rock object in current direction.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	virtual void move(float changeInTime) override;
	/**
	* Inherited from MovingEntity.
	* Creates square hitbox around Rock object through point assignments.
	* @return list of Vector2f containing hitbox points of Rock object.
	*/
	virtual list<Vector2f> hitboxPoints() override;
	/**
	* Inherited from MovingEntity.
	* Rock object will be destroyed if collision occurs with a Ground object if Rock object is falling.
	* @param collider is a shared pointer to Entity object which the Rock object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	bool _timer = false;
	float _elapsed_time_since_update = 1.0f;
	Vector2f _elapsed_distance = Vector2f(0, 0);
	static int _groundDestroyed;
	static const auto _rockHeight = 28;
	static const auto _rockWidth = 28;
	static constexpr const auto _rockSpeed = 50.0;
};

#endif