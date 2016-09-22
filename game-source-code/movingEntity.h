#ifndef MOVING_ENTITY_H
#define MOVING_ENTITY_H

#include "direction.h"
#include "entity.h"
#include "entityList.h"
#include "vector2f.h"
#include <list>
#include <ctime>

using std::list;

/**
* MovingEntity class - creates extension of Entity class to add moving functionality to Entity objects.
* Inherits from Entity class.
*/
class MovingEntity: public Entity
{
public:
	/**
	* Constructor. Calls the Entity constructor explicitly and caters for object speed as a new parameter.
	* @param entityKey is a scoped enumeration containing the identity ID of the Entity. Used to correctly assign textures to Entity objects during rendering.
	* @param position is a Vector2f containing the coordinates of the MovingEntity object position of creation.
	* @param speed is a Vector2f which contains the speed at which the MovingEntity object will move around the map.
	*/
	MovingEntity(EntityList entityKey, Vector2f position, Vector2f speed);
	/**
	* Allows for Entity movement to take place.
	* Not implemented in this class, meant to be overriden in derived classes.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	virtual void move(float changeInTime) = 0;
	/**
	* Inherited from Entity.
	* Creates square hitbox around MovingEntity object through point assignments.
	* @return list of Vector2f containing hitbox points of MovingEntity object.
	*/
	virtual list<Vector2f> hitboxPoints() override = 0;
	/**
	* Inherited from Entity.
	* MovingEntity object will be destroyed if collision occurs with specific Entity objects in derived classes.
	* @param collider is a shared pointer to Entity object which the MovingEntity object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override = 0;
	/**
	* Returns speed of the MovingEntity object.
	* @return Vector2f containing speed of MovingEntity object.
	*/
	Vector2f getSpeed() const;
	/**
	* Assigns specific direction to MovingEntity object based on entered direction.
	* @param direction is an enum of the strongly typed enum class Direction.
	*/
	void directionChange(Direction direction);
	/**
	* Assigns randomised direction to MovingEntity object.
	* Selects one of four possible directions from strongly typed enum class Direction.
	*/
	void directionAssignment();
	/**
	* Returns current direction of MovingEntity object.
	* @return Direction which is a direction from the strongly typed enum class Direction.
	*/
	Direction getDirection();
	
private:
	Vector2f _speed;
	Direction _facing;
	
};

#endif