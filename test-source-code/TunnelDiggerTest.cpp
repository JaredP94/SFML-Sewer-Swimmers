#include "gtest/gtest.h"
#include "tunnelDigger.h"
#include "enemy.h"
#include "harpoon.h"
#include "player.h"
#include "ground.h"

#include <iostream>

using std::shared_ptr;
using std::make_shared;

TEST (TunnelDigger, tunnelDiggerInitializesWithGivenPosition)
{
	TunnelDigger test_entity(100.f,50.f);
	EXPECT_EQ (100.f, test_entity.getPosition()._x);
	EXPECT_EQ (50.f, test_entity.getPosition()._y);
}

TEST (TunnelDigger, numberOfTunnelDiggersIncrementWhenInitialized)
{
	TunnelDigger test_entity(100.f,50.f);
	EXPECT_EQ(1,test_entity.getDiggerQuantity());
}

TEST (TunnelDigger, tunnelDiggerDestroysWhenHittingUpperMapBound)
{
	TunnelDigger test_entity(100.f,201.f);
	float time = 0.1f;
	test_entity.directionChange(Direction::Up);
	test_entity.move(time);
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}

TEST (TunnelDigger, tunnelDiggerDestroysWhenHittingLowerBound)
{
	TunnelDigger test_entity(100.f,799.f);
	float time = 0.1f;
	test_entity.directionChange(Direction::Down);
	test_entity.move(time);
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}

TEST (TunnelDigger, tunnelDiggerDestroysWhenHittingLeftBound)
{
	TunnelDigger test_entity(1.f,300.f);
	float time = 0.1f;
	test_entity.directionChange(Direction::Left);
	test_entity.move(time);
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}

TEST (TunnelDigger, tunnelDiggerDestroysWhenHittingRightBound)
{
	TunnelDigger test_entity(999.f,300.f);
	float time = 0.1f;
	test_entity.directionChange(Direction::Right);
	test_entity.move(time);
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}

TEST (TunnelDigger, tunnelDiggerDestroysAfterSetDistance)
{
	TunnelDigger test_entity(500.f,350.f);
	float time = 3.21f;
	test_entity.move(time);
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}