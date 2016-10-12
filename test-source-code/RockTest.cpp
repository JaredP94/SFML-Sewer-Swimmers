#include "gtest/gtest.h"
#include "rock.h"
#include "player.h"
#include "enemy.h"
#include "ground.h"
#include "harpoon.h"
#include "vector2f.h"

#include <iostream>

using std::shared_ptr;
using std::make_shared;

TEST (Rock, rockInitializesAtGivenPosition)
{
	Rock test_rock(100,50);
	EXPECT_EQ(100, test_rock.getPosition()._x);
	EXPECT_EQ(50, test_rock.getPosition()._y);
}

TEST (Rock, rockDestroysWhenCollidingWithLowerMapBound)
{
	Rock test_rock(100,400);
	while(test_rock.getElapsedDistance()._y < test_rock.getMapBounds()._y - 400 - 28)
	{
		EXPECT_FALSE(test_rock.checkIfDestroyed());
		test_rock.move(0.1f);
	}
	EXPECT_TRUE(test_rock.checkIfDestroyed());
}

TEST (Rock, rockStopsMovingWhenCollidingWithGround)
{
	Rock test_rock(100,400);
	shared_ptr<Entity> ground_ptr = make_shared<Ground>(100,400);
	Rock::setGroundDestroyed();
	Rock::setGroundDestroyed();
	test_rock.collide(ground_ptr);
	EXPECT_FALSE(test_rock.getMovingStatus());
}

TEST (Rock, rockStopsMomentarilyWhenCollidingWithPlayer)
{
	Rock test_rock(100,400);
	shared_ptr<Entity> player_ptr = make_shared<Player>();
	test_rock.collide(player_ptr);
	EXPECT_FALSE(test_rock.getMovingStatus());
}

TEST (Rock, rockStartsShortlyAfterCollidingWithPlayer)
{
	Rock test_rock(100,400);
	shared_ptr<Entity> harpoon_ptr = make_shared<Harpoon>(Vector2f(100.f,400.f),Vector2f(0.f,1.f));
	shared_ptr<Entity> player_ptr = make_shared<Player>();
	test_rock.collide(player_ptr);
	player_ptr->setPosition(100,100);
	while(test_rock.getTimeElapsed() < 1.6)
	{
		EXPECT_FALSE(test_rock.getMovingStatus());
		test_rock.move(0.1f);
	}
		test_rock.collide(harpoon_ptr);
		test_rock.move(0.1f);
	EXPECT_TRUE(test_rock.getMovingStatus());
}

TEST (Rock, playerLosesLifeWhenCollidingWithFallingRock)
{
	shared_ptr<Rock> rock_ptr =make_shared<Rock>(100,400);
	shared_ptr<Entity> harpoon_ptr = make_shared<Harpoon>(Vector2f(100.f,400.f),Vector2f(0.f,1.f));
	shared_ptr<Player> player_ptr = make_shared<Player>();
	rock_ptr->collide(player_ptr);
	player_ptr->setPosition(100,100);
	while(rock_ptr->getTimeElapsed() < 1.6)
	{
		rock_ptr->move(0.1f);
	}
		rock_ptr->collide(harpoon_ptr);
		rock_ptr->move(0.1f);
		rock_ptr->collide(player_ptr);
		player_ptr->collide(rock_ptr);
	EXPECT_EQ(4,player_ptr->getNumberOfLives());
}

TEST (Rock, enemyDestroysWhenCollidingWithFallingRock)
{
	shared_ptr<Rock> rock_ptr =make_shared<Rock>(100,400);
	shared_ptr<Entity> harpoon_ptr = make_shared<Harpoon>(Vector2f(100.f,400.f),Vector2f(0.f,1.f));
	shared_ptr<Player> player_ptr = make_shared<Player>();
	shared_ptr<Entity> enemy_ptr = make_shared<Enemy>(Vector2f(100.f,405.f));
	rock_ptr->collide(player_ptr);
	player_ptr->setPosition(100,100);
	while(rock_ptr->getTimeElapsed() < 1.6)
	{
		rock_ptr->move(0.1f);
	}
		rock_ptr->collide(harpoon_ptr);
		rock_ptr->move(0.1f);
		rock_ptr->collide(player_ptr);
		enemy_ptr->collide(rock_ptr);
	EXPECT_TRUE(enemy_ptr->checkIfDestroyed());
}

TEST (Rock, adds250PointsWhenRockDestroysEnemy)
{
	shared_ptr<Rock> rock_ptr =make_shared<Rock>(100,400);
	shared_ptr<Entity> harpoon_ptr = make_shared<Harpoon>(Vector2f(100.f,400.f),Vector2f(0.f,1.f));
	shared_ptr<Player> player_ptr = make_shared<Player>();
	shared_ptr<Entity> enemy_ptr = make_shared<Enemy>(Vector2f(100.f,405.f));
	rock_ptr->collide(player_ptr);
	player_ptr->setPosition(100,100);
	while(rock_ptr->getTimeElapsed() < 1.6)
	{
		rock_ptr->move(0.1f);
	}
		rock_ptr->collide(harpoon_ptr);
		rock_ptr->move(0.1f);
		rock_ptr->collide(player_ptr);
		enemy_ptr->collide(rock_ptr);
	EXPECT_EQ(500,player_ptr->getScore());
}