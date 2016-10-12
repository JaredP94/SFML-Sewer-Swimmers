#include "gtest/gtest.h"
#include "vector2f.h"
#include "enemy.h"
#include "harpoon.h"
#include "player.h"
#include "ground.h"

#include <iostream>

using std::shared_ptr;
using std::make_shared;

TEST (Harpoon, bombDestroysWhenCollidingWithEnemy)
{
	Harpoon test_bomb(Vector2f(0,0), Vector2f(0,0));
	shared_ptr<MovingEntity> enemy_ptr = make_shared<Enemy>();
	test_bomb.collide(enemy_ptr);
	EXPECT_TRUE(test_bomb.checkIfDestroyed());
}

TEST (Harpoon, bombDestroysWhenCollidingWithGround)
{
	Harpoon test_bomb(Vector2f(0,0), Vector2f(0,0));
	shared_ptr<Entity> ground_ptr = make_shared<Ground>(100.f,32.f);
	test_bomb.collide(ground_ptr);
	EXPECT_TRUE(test_bomb.checkIfDestroyed());
}

TEST (Harpoon, bombDestroysWhenHittingUpperMapBound)
{
	Harpoon test_bomb(Vector2f(10.f,-0.1f), Vector2f(0,0));
	float time = 0.1f;
	test_bomb.move(time);
	EXPECT_TRUE(test_bomb.checkIfDestroyed());
}

TEST (Harpoon, bombDestroysWhenHittingUpperLowerBound)
{
	Harpoon test_bomb(Vector2f(10.f,800.f), Vector2f(0,0));
	float time = 0.1f;
	test_bomb.move(time);
	EXPECT_TRUE(test_bomb.checkIfDestroyed());
}

TEST (Harpoon, bombDestroysWhenHittingUpperLeftBound)
{
	Harpoon test_bomb(Vector2f(-0.1f,10.f), Vector2f(0,0));
	float time = 0.1f;
	test_bomb.move(time);
	EXPECT_TRUE(test_bomb.checkIfDestroyed());
}

TEST (Harpoon, bombDestroysWhenHittingRightBound)
{
	Harpoon test_bomb(Vector2f(1000.f,10.f), Vector2f(1.f,0.f));
	float time = 0.1f;
	test_bomb.move(time);
	EXPECT_TRUE(test_bomb.checkIfDestroyed());
}

TEST (Harpoon, bombDestroysAfterSetDistance)
{
	Harpoon test_bomb(Vector2f(485.f,385.f), Vector2f(1.f,0.f));
	float time = 0.515f;
	test_bomb.move(time);
	EXPECT_TRUE(test_bomb.checkIfDestroyed());
}

TEST (Harpoon, bombNotDestroyedWithinMovingLimits)
{
	Harpoon test_bomb(Vector2f(485.f,385.f), Vector2f(1.f,0.f));
	float time = 0.514f;
	test_bomb.move(time);
	EXPECT_FALSE(test_bomb.checkIfDestroyed());
}