#ifndef ENEMY_H
#define ENEMY_H

#include "gameEvent.h"
#include "movingEntity.h"
#include "vector2f.h"
#include "player.h"
#include "rock.h"
#include <list>
#include <memory>
#include <iostream>
#include <ctime>
#include <cmath>

using std::list;
using std::shared_ptr;

/**
* Enemy class - represents the enemy ghosts.
* Inherits from MovingEntity class.
*/
class Enemy: public MovingEntity
{
public:
	/**
	* Default constructor. Calls the MovingEntity constructor explicitly. Creates enemy in random position. Assigns the enemy with a random direction. Increases amount of enemies created.
	*/
	Enemy();
	/**
	* Constructor. Calls the MovingEntity constructor explicitly. Creates enemy in specific position. Increases amount of enemies created.
	* @param position is a const reference to a Vector2f with holds the coordinates for enemy creation.
	*/
	Enemy(const Vector2f& position);
	/**
	* Destructor. Increases number of enemies destroyed.
	*/
	~Enemy();
	/**
	* Static function. Returns number of Enemy objects that have been destroyed.
	* @return int containing number of Enemy objects destroyed.
	*/
	static int getEnemyDestroyed() {return _enemy_destroyed;};
	/**
	* Static function. Returns number of Enemy objects that have been created.
	* @return int containing number of Enemy objects created.
	*/
	static int getEnemiesCreated() {return _enemies_created;};
	/**
	* Static function. Sets target which all Enemy objects will chase when within range.
	*/
	static void setEnemyTarget(const shared_ptr<Entity>& enemy_target);
	/**
	* Function which handles collision between Enemy object and Ground or Rock object.
	*/
	void collision();
	/**
	* Function which handles collision between Enemy object and Harpoon object.
	* Enemy object will be destroyed if hit by harpoon for 2 seconds.
	*/
	void harpoonHit();
	/**
	* Function which makes Enemy object chase target when it is within range.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	void followTarget(float changeInTime);
	/**
	* Inherited from MovingEntity.
	* Moves Enemy object in current direction.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	virtual void move(float changeInTime) override;
	/**
	* Inherited from MovingEntity.
	* Creates square hitbox around Enemy object through point assignments.
	* @return list of Vector2f containing hitbox points of Enemy object.
	*/
	virtual list<Vector2f> hitboxPoints() override;
	/**
	* Inherited from MovingEntity.
	* Enemy object will be destroyed if collision occurs with a falling rock or a harpoon for 2 seconds.
	* @param collider is a shared pointer to Entity object which the Enemy object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	static int _enemy_destroyed;
	static int _enemies_created;
	float _elapsed_time_since_update = 1.0f;
	static const auto _enemyHeight = 28;
	static const auto _enemyWidth = 28;
	static constexpr const auto _enemySpeed = 50.0;
	Vector2f _targetRange = Vector2f(90.f, 90.f);
	static shared_ptr<Entity> _enemy_target;
};

#endif