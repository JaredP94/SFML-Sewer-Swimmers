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
	Enemy(const Vector2f& position);
	~Enemy();
	Vector2f positionChange();
	static int getEnemyDestroyed() {return _enemy_destroyed;};
	static int getEnemiesCreated() {return _enemies_created;};
	void incrementEnemiesCreated() {_enemies_created++;};
	void Collision();
	bool faceUp() const;
	bool faceDown() const;
	bool faceLeft() const;
	bool faceRight() const;
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	static int _enemy_destroyed;
	static int _enemies_created;
	float _elapsed_time_since_update = 1.0f;
	static const auto _enemyHeight = 28;
	static const auto _enemyWidth = 28;
	static constexpr const auto _enemySpeed = 50.0;
	Vector2f _speed;
};

#endif