#include "gtest/gtest.h"
#include "vector2f.h"
#include "player.h"
#include "enemy.h"
#include "rock.h"
#include "movingEntity.h"

#include <iostream>

TEST(Enemy, enemyInitializesAtGivenPosition)
{
	Enemy test_entity(Vector2f(100.f,50.f));
	EXPECT_EQ(100.f,test_entity.getPosition()._x);
	EXPECT_EQ(50.f,test_entity.getPosition()._y);
}

TEST (Enemy, enemyInitializesWithZeroEnemyEntities)
{
	//Note: Due to enemy creation elsewhere in the testing structure, getEnemiesCreated does not return 0
	Enemy test_entity;
	EXPECT_EQ(6,test_entity.getEnemiesCreated());
}

TEST (Enemy, numberOfEnemysIncrementedWhenNewEnemyCreated)
{
	//Note: Due to enemy creation elsewhere in the testing structure, getEnemiesCreated does not return 1 and 2
	Enemy test_entity;
	EXPECT_EQ(7,test_entity.getEnemiesCreated());
	Enemy test_entity2;
	EXPECT_EQ(8,test_entity.getEnemiesCreated());
}

TEST (Enemy, enemyInflatesWhenCollidingWithHarpoonButDoesNotDestroy)
{
	Enemy test_enemy;
	Player test_player;
	test_player.shooting(GameEvent::Press_Space);
	shared_ptr<MovingEntity> harpoon_ptr = make_shared<Harpoon>(Vector2f(50.f,50.f), Vector2f(0,0));
	test_enemy.collide(harpoon_ptr);
	EXPECT_TRUE(test_enemy.getInflateStatus());
	EXPECT_FALSE(test_enemy.checkIfDestroyed());
	test_player.shooting(GameEvent::Release_Space);
}

TEST (Enemy, enemyDeflatesIfCollisionLastsLessThan2Seconds)
{
	Enemy test_enemy;
	Player test_player;
	test_player.shooting(GameEvent::Press_Space);
	shared_ptr<MovingEntity> harpoon_ptr = make_shared<Harpoon>(Vector2f(50.f,50.f), Vector2f(0,0));
	while (test_enemy.getTimeElapsed() <= 1.0f)
	{
		test_enemy.collide(harpoon_ptr);
		test_enemy.addTimeElapsed(0.1f);
	}
	test_player.shooting(GameEvent::Release_Space);
	test_enemy.collide(harpoon_ptr);
	EXPECT_TRUE(test_enemy.getDeflateStatus());
}

TEST (Enemy, enemyDestroysAfterCollisionOccursFor2Seconds)
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

TEST (Enemy, scoreIncreasesAfterEnemyIsDestroyedByHarpoon)
{
	//Note: Due to point scoring operations occuring elsewhere in the testing structure, score starting value is not 0
	Enemy test_enemy;
	Player test_player;
	EXPECT_EQ(675,test_player.getScore());
	test_player.shooting(GameEvent::Press_Space);
	shared_ptr<MovingEntity> harpoon_ptr = make_shared<Harpoon>(Vector2f(0,0), Vector2f(0,0));
	while (test_enemy.getTimeElapsed() <= 2.1f)
	{
		test_enemy.collide(harpoon_ptr);
		if(test_enemy.getTimeElapsed() >= 2.0f) break;
		test_enemy.addTimeElapsed(0.1f);
	}
	EXPECT_EQ(800,test_player.getScore());
	test_player.shooting(GameEvent::Release_Space);
}

TEST (Enemy, enemyChasesPlayerWithinDefinedRadius)
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

