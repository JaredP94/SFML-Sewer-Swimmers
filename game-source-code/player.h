#ifndef PLAYER_H
#define PLAYER_H

#include "direction.h"
#include "entityList.h"
#include "entityContainer.h"
#include "gameEvent.h"
#include "harpoon.h"
#include "shootingMovingEntity.h"
#include "vector2f.h"
#include <list>
#include <memory>
#include <iostream>

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
	void directionChange(Direction direction);
	bool faceUp() const;
	bool faceDown() const;
	bool faceLeft() const;
	bool faceRight() const;
	int getNumberOfLives();
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	virtual shared_ptr<MovingEntity> shoot(float changeInTime) override;
	
private:
	bool _up = false;
	bool _down = false;
	bool _left = false;
	bool _right = false;
	bool _moving = false;
	bool _launch_harpoon = false;
	Direction _facing;
	static const auto _playerHeight = 30;
	static const auto _playerWidth = 30;
	static constexpr const auto _playerSpeed = 100.0f;
	int _lives = 5;
	Vector2f _positionChange;
};

#endif