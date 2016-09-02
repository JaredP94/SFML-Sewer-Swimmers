#ifndef PLAYER_H
#define PLAYER_H

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

class Player: public MovingEntity
{
public:
	Player();
	void movement(GameEvent event);
	Vector2f positionChange();
//	void directionChange(Direction direction);
	bool faceUp() const;
	bool faceDown() const;
	bool faceLeft() const;
	bool faceRight() const;
	int getNumberOfLives();
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
	int _lives = 5;
	Vector2f _positionChange;
};

#endif