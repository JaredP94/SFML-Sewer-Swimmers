#ifndef PLAYER_H
#define PLAYER_H

#include "entityList.h"
#include "entityContainer.h"
#include "gameEvent.h"
#include "harpoon.h"
#include "shootingMovingEntity.h"
#include "vector2f.h"
#include "player.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;
using std::make_shared;

class Player: public ShootingMovingEntity
{
public:
	Player();
	void movement(GameEvent event);
	void shooting(GameEvent event);
	Vector2f positionChange();
	int getNumberOfLives();
	static bool isShooting() {return _shooting;};
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	virtual shared_ptr<MovingEntity> shoot(float changeInTime) override;
	
private:
	bool _moving = false;
	static bool _shooting;
	static const auto _playerHeight = 30;
	static const auto _playerWidth = 30;
	static constexpr const auto _playerSpeed = 100.0f;
	int _lives = 5;
	Vector2f _positionChange;
};

#endif