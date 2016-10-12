#include "gtest/gtest.h"
#include "vector2f.h"
#include "enemy.h"
#include "harpoon.h"
#include "player.h"
#include "ground.h"

#include <iostream>

using std::shared_ptr;
using std::make_shared;

TEST (Harpoon, harpoonDestroysWhenCollidingWithEnemy)
{
	Harpoon test_harpoon(Vector2f(0,0), Vector2f(0,0));
	shared_ptr<MovingEntity> enemy_ptr = make_shared<Enemy>();
	test_harpoon.collide(enemy_ptr);
	EXPECT_TRUE(test_harpoon.checkIfDestroyed());
}

TEST (Harpoon, harpoonDestroysWhenCollidingWithGround)
{
	Harpoon test_harpoon(Vector2f(0,0), Vector2f(0,0));
	shared_ptr<Entity> ground_ptr = make_shared<Ground>(100.f,32.f);
	test_harpoon.collide(ground_ptr);
	EXPECT_TRUE(test_harpoon.checkIfDestroyed());
}

TEST (Harpoon, harpoonDestroysWhenHittingUpperMapBound)
{
	Harpoon test_harpoon(Vector2f(10.f,-0.1f), Vector2f(0,0));
	float time = 0.1f;
	test_harpoon.move(time);
	EXPECT_TRUE(test_harpoon.checkIfDestroyed());
}

TEST (Harpoon, harpoonDestroysWhenHittingLowerBound)
{
	Harpoon test_harpoon(Vector2f(10.f,800.f), Vector2f(0,0));
	float time = 0.1f;
	test_harpoon.move(time);
	EXPECT_TRUE(test_harpoon.checkIfDestroyed());
}

TEST (Harpoon, harpoonDestroysWhenHittingUpperLeftBound)
{
	Harpoon test_harpoon(Vector2f(-0.1f,10.f), Vector2f(0,0));
	float time = 0.1f;
	test_harpoon.move(time);
	EXPECT_TRUE(test_harpoon.checkIfDestroyed());
}

TEST (Harpoon, harpoonDestroysWhenHittingRightBound)
{
	Harpoon test_harpoon(Vector2f(1000.f,10.f), Vector2f(1.f,0.f));
	float time = 0.1f;
	test_harpoon.move(time);
	EXPECT_TRUE(test_harpoon.checkIfDestroyed());
}

TEST (Harpoon, harpoonDestroysAfterSetDistance)
{
	Harpoon test_harpoon(Vector2f(485.f,385.f), Vector2f(1.f,0.f));
	float time = 0.515f;
	test_harpoon.move(time);
	EXPECT_TRUE(test_harpoon.checkIfDestroyed());
}

TEST (Harpoon, harpoonNotDestroyedWithinMovingLimits)
{
	Harpoon test_harpoon(Vector2f(485.f,385.f), Vector2f(1.f,0.f));
	float time = 0.514f;
	test_harpoon.move(time);
	EXPECT_FALSE(test_harpoon.checkIfDestroyed());
}