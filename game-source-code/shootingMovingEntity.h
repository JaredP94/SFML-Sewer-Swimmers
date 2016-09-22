#ifndef SHOOTINGMOVINGENTITY_H
#define SHOOTINGMOVINGENTITY_H

#include "movingEntity.h"
#include "entityList.h"
#include "vector2f.h"

/**
* ShootingMovingEntity class - creates extension of MovingEntity class to add shooting functionality to MovingEntity objects.
* Inherits from Entity class.
*/
class ShootingMovingEntity: public MovingEntity
{
public:
/**
	* Constructor. Calls the MovingEntity constructor explicitly.
	* @param entityKey is a scoped enumeration containing the identity ID of the Entity. Used to correctly assign textures to Entity objects during rendering.
	* @param position is a Vector2f containing the coordinates of the ShootingMovingEntity object position of creation.
	* @param speed is a Vector2f which contains the speed at which the ShootingMovingEntity object will move around the map.
	*/
	ShootingMovingEntity(EntityList entityID, Vector2f position, Vector2f speed);
	/**
	* Allows for MovingEntity to shoot projectiles.
	* Not implemented in this class, meant to be overriden in derived classes.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	* @return shared_ptr to MovingEntity containing the projectile that is shot.
	*/
	virtual shared_ptr<MovingEntity> shoot(float changeInTime) = 0;
	/**
	* Inherited from MovingEntity. Pure virtual function.
	* Not implemented in this class, meant to be overriden in derived classes.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	virtual void move(float changeInTime) override = 0;
	/**
	* Inherited from MovingEntity. Pure virtual function.
	* Creates square hitbox around ShootingMovingEntity object through point assignments.
	* @return list of Vector2f containing hitbox points of ShootingMovingEntity object.
	*/
	virtual list<Vector2f> hitboxPoints() override = 0;
	/**
	* Inherited from MovingEntity. Pure virtual function.
	* ShootingMovingEntity object will be destroyed if collision occurs with specific Entity objects in derived classes.
	* @param collider is a shared pointer to Entity object which the ShootingMovingEntity object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override = 0;
};

#endif