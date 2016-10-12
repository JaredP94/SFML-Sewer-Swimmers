#ifndef HARPOON_H
#define HARPOON_H

#include "movingEntity.h"
#include "vector2f.h"
#include <memory>

using std::shared_ptr;

/**
* Harpoon class - represents the Player object's weapon.
* Inherits from MovingEntity class.
*/
class Harpoon: public MovingEntity
{
public:
	/**
	* Constructor. Calls the MovingEntity constructor explicitly and creates a Harpoon object at a specific position which moves in a specific direction. Increases number of Harpoon objects launched.
	* @param position is a const reference to a Vector2f which contains the coordinates for Harpoon object creation.
	* @param velocity_unit_direction is a const reference to a Vector2f which contains the direction in which the Harpoon object should travel.
	*/
	Harpoon(const Vector2f& position, const Vector2f& velocity_unit_direction);
	/**
	* Destructor. Decreases the number of Harpoon objects launched.
	*/
	~Harpoon();
	/**
	* Inherited from MovingEntity.
	* Moves Harpoon object in current direction.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	virtual void move(float changeInTime) override;
	/**
	* Inherited from MovingEntity.
	* Creates square hitbox around Harpoon object through point assignments.
	* @return list of Vector2f containing hitbox points of Harpoon object.
	*/
	virtual list<Vector2f> hitboxPoints() override;
	/**
	* Inherited from MovingEntity.
	* Harpoon object will be destroyed if collision occurs with a Rock object or Enemy object.
	* @param collider is a shared pointer to Entity object which the Harpoon object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override;
	/**
	* Static function. Returns status of whether harpoon currently exists in the game.
	* @return bool containing status of whether harpoon currently exists in game.
	*/
	static bool getHarpoonStatus() {return _harpoon_launched;};
	
private:
	float _elapsed_time_since_update = 1.0f;
	Vector2f _elapsed_distance = Vector2f(0, 0);
	static bool _harpoon_launched;
	static constexpr const auto _harpoon_width = 32.f;
	static constexpr const auto _harpoon_height = 32.f;
	static constexpr const auto _harpoon_speed = 175.f;
	
};

#endif