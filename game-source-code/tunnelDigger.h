#ifndef TUNNELDIGGER_H
#define TUNNELDIGGER_H

#include "movingEntity.h"
#include "vector2f.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;

/**
* TunnelDigger class - represents the TunnelDigger objects in the game.
* Inherits from MovingEntity class.
*/
class TunnelDigger: public MovingEntity
{
public:
	/**
	* Constructor. Calls the MovingEntity constructor explicitly and creates a TunnelDigger object at a specific position on the map. Increases number of TunnelDigger objects which exist in the game. Assigns a random direction to the TunnelDigger object.
	* @param x is a float which contains the horizontal creation coordinates.
	* @param y is a flaot which contains the vertical creation coordinates.
	*/
	TunnelDigger(float x, float y);
	/**
	* Constructor. Calls the MovingEntity constructor explicitly and creates a TunnelDigger object at a specific position on the map. Increases number of TunnelDigger objects which exist in the game. Assigns a random direction to the TunnelDigger object.
	* @param position is a const reference to a Vector2f which contains the creation coordinates.
	*/
	TunnelDigger(const Vector2f& position);
	/**
	* Destructor. Decreases number of TunnelDigger objects which exist in the game.
	*/
	~TunnelDigger();
	static int getDiggerQuantity() {return _digger_quantity;};
	/**
	* Inherited from MovingEntity.
	* Moves TunnelDigger object in current direction.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	virtual void move(float changeInTime) override;
	/**
	* Inherited from MovingEntity.
	* Creates square hitbox around TunnelDigger object through point assignments.
	* @return list of Vector2f containing hitbox points of TunnelDigger object.
	*/
	virtual list<Vector2f> hitboxPoints() override;
	/**
	* Inherited from MovingEntity.
	* No collision rules currently exist between TunnelDigger objects and other Entity objects.
	* @param collider is a shared pointer to Entity object which the TunnelDigger object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	static int _digger_quantity;
	float _elapsed_time_since_update = 1.0f;
	Vector2f _elapsed_distance = Vector2f(0, 0);
	static const auto _diggerHeight = 30;
	static const auto _diggerWidth = 30;
	static constexpr const auto _diggerSpeed = 50.0;
};

#endif