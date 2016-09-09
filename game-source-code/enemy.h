#ifndef ENEMY_H
#define ENEMY_H

#include "gameEvent.h"
#include "movingEntity.h"
#include "vector2f.h"
#include "player.h"
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
	static void setEnemyTarget(const shared_ptr<Entity>& enemy_target);
	void incrementEnemiesCreated() {_enemies_created++;};
	void collision();
	void harpoonHit();
	void followTarget(float changeInTime);
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
	Vector2f _targetRange = Vector2f(90.f, 90.f);
	Vector2f _speed;
	static shared_ptr<Entity> _enemy_target;
};

#endif