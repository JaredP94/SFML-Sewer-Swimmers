#include "gtest/gtest.h"
#include "vector2f.h"
#include "player.h"
#include "enemy.h"
#include "ground.h"
#include "rock.h"

#include <iostream>

TEST (Ground, groundTileInitializesAtCorrectPositionWithCorrectSize)
{	
	Ground test_entity(100.f,32.f);
	EXPECT_EQ(100.f, test_entity.getPosition()._x);
	EXPECT_EQ(32.f, test_entity.getPosition()._y);
}

TEST (Ground, groundTileDestroysWhenCollidingWithPlayer)
{
	Ground test_entity(100.f,100.f);
	shared_ptr<Entity> player_ptr = make_shared<Player>();
	test_entity.collide(player_ptr);
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}

TEST (Ground, groundTileDestroysWhenCollidingWithRock)
{
	Ground test_entity(100.f,100.f);
	shared_ptr<Entity> rock_ptr = make_shared<Rock>(50.f,50.f);
	test_entity.collide(rock_ptr);
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}