#include "gtest/gtest.h"
#include "vector2f.h"
#include "player.h"
#include "enemy.h"
#include "movingEntity.h"

#include <iostream>

TEST (Enemy, enemyInitializesWithZeroEnemyEntities)
{
	Enemy test_entity;
	EXPECT_EQ(0,test_entity.getEnemiesCreated());
}

TEST (Enemy, numberOfEnemysIncrementedWhenNewEnemyCreated)
{
	Enemy test_entity;
	test_entity.incrementEnemiesCreated();
	test_entity.incrementEnemiesCreated();
	EXPECT_EQ(2,test_entity.getEnemiesCreated());
}

TEST (Enemy, enemyInflatesWhenCollidingWithBombButDoesNotDestroy)
{
	Enemy test_enemy;
	Player test_player;
	test_player.shooting(GameEvent::Press_Space);
	shared_ptr<MovingEntity> harpoon_ptr = make_shared<Harpoon>(Vector2f(0,0), Vector2f(0,0));
	test_enemy.collide(harpoon_ptr);
	EXPECT_TRUE(test_enemy.getInflateStatus());
	EXPECT_FALSE(test_enemy.checkIfDestroyed());
	test_player.shooting(GameEvent::Release_Space);
}

TEST (Enemy, enemyDeflatesIfLessThan2Seconds)
{
	Enemy test_enemy;
	Player test_player;
	test_player.shooting(GameEvent::Press_Space);
	shared_ptr<MovingEntity> harpoon_ptr = make_shared<Harpoon>(Vector2f(0,0), Vector2f(0,0));
	while (test_enemy.getTimeElapsed() <= 1.0f)
	{
		test_enemy.collide(harpoon_ptr);
		test_enemy.addTimeElapsed(0.1f);
	}
	test_player.shooting(GameEvent::Release_Space);
	test_enemy.collide(harpoon_ptr);
	EXPECT_TRUE(test_enemy.getDeflateStatus());
}

TEST (Enemy, enemyDestroysAfterCollidingFor2Seconds)
{
	Enemy test_enemy;
	Player test_player;
	test_player.shooting(GameEvent::Press_Space);
	shared_ptr<MovingEntity> harpoon_ptr = make_shared<Harpoon>(Vector2f(0,0), Vector2f(0,0));
	while (test_enemy.getTimeElapsed() <= 2.1f)
	{
		test_enemy.collide(harpoon_ptr);
		if(test_enemy.getTimeElapsed() >= 2.0f) break;
		EXPECT_FALSE(test_enemy.checkIfDestroyed());
		test_enemy.addTimeElapsed(0.1f);
	}
	EXPECT_TRUE(test_enemy.checkIfDestroyed());
	test_player.shooting(GameEvent::Release_Space);
}

TEST (Enemy, EnemyChasesPlayerWithinRadius)
{
	shared_ptr<Player> player_ptr = make_shared<Player>();
	shared_ptr<Enemy> test_enemy = make_shared<Enemy>(Vector2f(player_ptr->getPosition()._x + 50.f, player_ptr->getPosition()._y));
	Enemy::setEnemyTarget(player_ptr);
	Vector2f vector_test;
	auto distance = vector_test.vectorDistance(test_enemy->getPosition(), player_ptr->getPosition());
	float prev_distance;
	while (distance > 1.f)
	{
		prev_distance = distance;
		player_ptr->move(0.001f);
		test_enemy->move(0.001f);
		distance = vector_test.vectorDistance(test_enemy->getPosition(), player_ptr->getPosition());
		EXPECT_TRUE(distance < prev_distance);
	}
}