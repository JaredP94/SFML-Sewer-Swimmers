#ifndef ENEMY_H
#define ENEMY_H

#include "gameEvent.h"
#include "movingEntity.h"
#include "vector2f.h"
#include <list>
#include <memory>
#include <iostream>
#include <ctime>
#include <cmath>

using std::list;
using std::shared_ptr;

class Enemy: public MovingEntity
{
public:
	Enemy();
	~Enemy();
	Vector2f positionChange();
	static int getEnemyQuantity() {return _enemy_quantity;};
//	void directionChange(Direction direction);
	bool faceUp() const;
	bool faceDown() const;
	bool faceLeft() const;
	bool faceRight() const;
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
protected:
	float positionGeneration(float positionBounds) const;
	
private:
	bool _up = false;
	bool _down = false;
	bool _left = false;
	bool _right = false;
	static int _enemy_quantity;
	float _elapsed_time_since_update = 1.0f;
	static const auto _enemyHeight = 30;
	static const auto _enemyWidth = 30;
	static constexpr const auto _enemySpeed = 50.0;
	Vector2f _speed;
};

#endif