#ifndef PLAYER_H
#define PLAYER_H

#include "entityList.h"
#include "entityContainer.h"
#include "gameEvent.h"
#include "harpoon.h"
#include "shootingMovingEntity.h"
#include "vector2f.h"
#include "rock.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;
using std::make_shared;

/**
* Player class - represents the Player turtle.
* Inherits from ShootingMovingEntity class.
*/
class Player: public ShootingMovingEntity
{
public:
	/**
	* Default constructor. Calls the ShootingMovingEntity constructor explicitly. Creates Player object in the middle of the map.
	*/
	Player();
	/**
	* Manages Player movement based on user input which is polled as a GameEvent event.
	* @param event is an enum of the strongly typed enum class GameEvent.
	*/
	void movement(GameEvent event);
	/**
	* Manages Player shooting based on user input which is polled as a GameEvent event.
	* @param event is an enum of the strongly typed enum class GameEvent.
	*/
	void shooting(GameEvent event);
	/**
	* Returns the displacement of the Player object.
	* @return Vector2f containing displacement of Player object.
	*/
	Vector2f positionChange();
	/**
	* Returns number of lives that Player object has.
	* @return int containing number of player lives.
	*/
	int getNumberOfLives();
	/**
	* Static function. Returns game score.
	* @return int containing game score.
	*/
	static int getScore() {return _score;};
	/**
	* Static function. Adds a specified amount to the current game score.
	* @param score is an int containing the value by which the game socre is to be increased.
	*/
	static void addScore(int score);
	/**
	* Stops Player object movement when a collision occurs with another Entity object.
	*/
	void collision();
	/**
	* Stops Player object movement when a collision occurs with a falling Rock object.
	*/
	void rockCollision();
	/**
	* Decreases Player object's number of lives.
	*/
	void loseLife();
	/**
	* Static function. Returns shooting status of Player object.
	* @return bool containing shooting status of Player object.
	*/
	static bool isShooting() {return _shooting;};
	/**
	* Inherited from ShootingMovingEntity.
	* Moves Player object in current direction.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	*/
	virtual void move(float changeInTime) override;
	/**
	* Inherited from ShootingMovingEntity.
	* Creates square hitbox around Player object through point assignments.
	* @return list of Vector2f containing hitbox points of Player object.
	*/
	virtual list<Vector2f> hitboxPoints() override;
	/**
	* Inherited from ShootingMovingEntity.
	* Player object will be destroyed if collision occurs with a falling rock or an Enemy object.
	* @param collider is a shared pointer to Entity object which the Player object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) override;
	/**
	* Inherited from ShootingMovingEntity.
	* Returns a shared pointer to projectile that Player object shoots.
	* @param changeInTime is a float containing the time elapsed since the last movement took place.
	* @return shared_ptr to projectile that was shot.
	*/
	virtual shared_ptr<MovingEntity> shoot(float changeInTime) override;
	
private:
	static bool _shooting;
	static const auto _playerHeight = 30;
	static const auto _playerWidth = 30;
	static constexpr const auto _playerSpeed = 100.0f;
	int _lives = 5;
	static int _score;
	Vector2f _positionChange;
};

#endif