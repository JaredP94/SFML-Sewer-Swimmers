#ifndef ENEMY_H
#define ENEMY_H

#include "direction.h"
#include "entityList.h"
#include "entityContainer.h"
#include "gameEvent.h"
#include "movingEntity.h"
#include "vector2f.h"
#include <list>
#include <memory>
#include <iostream>

using std::list;
using std::shared_ptr;

class Enemy: public MovingEntity
{
public:
	Enemy();
	Vector2f positionChange();
	void movement(GameEvent event);
//	void directionChange(Direction direction);
	bool faceUp() const;
	bool faceDown() const;
	bool faceLeft() const;
	bool faceRight() const;
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	bool _up = false;
	bool _down = false;
	bool _left = false;
	bool _right = false;
	static const auto _playerHeight = 32;
	static const auto _playerWidth = 32;
	static constexpr const auto _playerSpeed = 50.0;
	Vector2f _positionChange;
	int _lives = 5;
};

#endif