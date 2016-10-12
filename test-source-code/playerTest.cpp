#include "gtest/gtest.h"
#include "vector2f.h"
#include "player.h"
#include "enemy.h"

#include <iostream>

TEST (Player, positionsPlayerEntityInTheCentreOfTheScreen)
{
	Player test_entity;
	EXPECT_EQ(Vector2f(485.f,385.f),test_entity.getPosition());
}

TEST (Player, canMoveUpUsingUserInput)
{
	Player test_entity;
	float _time_elapsed = 0.1f;
	test_entity.movement(GameEvent::Press_W);
	test_entity.move(_time_elapsed);
	EXPECT_EQ(Vector2f(485.f, 385.f - 10.f), test_entity.getPosition());
}

TEST (Player, canMoveDownUsingUserInput)
{
	Player test_entity;
	float _time_elapsed = 0.1f;
	test_entity.movement(GameEvent::Press_S);
	test_entity.move(_time_elapsed);
	EXPECT_EQ(Vector2f(485, 385 + 10), test_entity.getPosition());
}

TEST (Player, canMoveRightUsingUserInput)
{
	Player test_entity;
	float _time_elapsed = 0.1f;
	test_entity.movement(GameEvent::Press_D); 
	test_entity.move(_time_elapsed);
	EXPECT_EQ(Vector2f(485 + 10, 385), test_entity.getPosition());
}

TEST (Player, canMoveLeftUsingUserInput)
{
	Player test_entity;
	float _time_elapsed = 0.1f;
	test_entity.movement(GameEvent::Press_A);
	test_entity.move(_time_elapsed);
	EXPECT_EQ(Vector2f(485 - 10, 385), test_entity.getPosition());
}

TEST (Player, playerContainsShootingStatus)
{
	Player test_entity;
	float time_elapsed = 0.1f;
	test_entity.shooting(GameEvent::Press_Space);
	shared_ptr<Entity> harpoon_ptr = test_entity.shoot(time_elapsed);
	EXPECT_TRUE(test_entity.isShooting());
}

TEST (Player, playerHasBombShootingCapabilities)
{
	Player test_entity;
	float time_elapsed = 0.1f;
	test_entity.shooting(GameEvent::Press_Space);
	shared_ptr<Entity> harpoon_ptr = test_entity.shoot(time_elapsed);
	EXPECT_EQ(harpoon_ptr->character().getEntityKey(),EntityList::Harpoon);
}

TEST (Player, bombInitializesAtPlayerPosition)
{
	Player test_entity;
	float time_elapsed = 0.1f;
	test_entity.shooting(GameEvent::Press_Space);
	shared_ptr<Entity> harpoon_ptr = test_entity.shoot(time_elapsed);
	EXPECT_EQ(harpoon_ptr->getPosition(),test_entity.getPosition());
}

TEST (Player, playerCannotMoveWhileShooting)
{
	Player test_entity;
	test_entity.shooting(GameEvent::Press_Space);
	EXPECT_FALSE(test_entity.getMovingStatus());
}

TEST (Player, playerInitializesWithFivelives)
{
	Player test_entity;
	EXPECT_EQ(5,test_entity.getNumberOfLives());
}

TEST (Player, playerLosesLivesAfterCollidingWithEnemy)
{
	Player test_entity;
	shared_ptr<Entity> enemy_ptr = make_shared<Enemy>();
	test_entity.collide(enemy_ptr);
	EXPECT_EQ(4,test_entity.getNumberOfLives());
}

TEST (Player, playerGetsDestroyedWhenAllLivesLost)
{
	Player test_entity;
	shared_ptr<Entity> enemy_ptr = make_shared<Enemy>();
	int lives = test_entity.getNumberOfLives();
	while (lives != 0)
	{
		test_entity.collide(enemy_ptr);
		lives = test_entity.getNumberOfLives();
	}
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}

TEST (Player, playerBoundedByRightMapBorder)
{
	Player test_entity;
	float time_elapsed = 0.1f;
	test_entity.setMapBounds(Vector2f(1000.f,800.f));
	test_entity.movement(GameEvent::Press_D);
	Vector2f test_position = test_entity.getPosition();
	test_entity.move(time_elapsed);
	while (test_position != test_entity.getPosition())
	{
		test_position = test_entity.getPosition();
		test_entity.move(time_elapsed);
		EXPECT_TRUE (test_entity.getPosition()._x <= test_entity.getMapBounds()._x);
	}
}

TEST (Player, playerBoundedByLeftMapBorder)
{
	Player test_entity;
	float time_elapsed = 0.1f;
	test_entity.setMapBounds(Vector2f(1000.f,800.f));
	test_entity.movement(GameEvent::Press_D);
	Vector2f test_position = test_entity.getPosition();
	test_entity.move(time_elapsed);
	while (test_position != test_entity.getPosition())
	{
		test_position = test_entity.getPosition();
		test_entity.move(time_elapsed);
		EXPECT_TRUE (test_entity.getPosition()._x <= 0.f);
	}
}

TEST (Player, playerBoundedByUpperMapBorder)
{
	Player test_entity;
	float time_elapsed = 0.1f;
	test_entity.setMapBounds(Vector2f(1000.f,800.f));
	test_entity.movement(GameEvent::Press_W);
	Vector2f test_position = test_entity.getPosition();
	test_entity.move(time_elapsed);
	while (test_position != test_entity.getPosition())
	{
		test_position = test_entity.getPosition();
		test_entity.move(time_elapsed);
		EXPECT_TRUE (test_entity.getPosition()._y <= 0.f);
	}
}

TEST (Player, playerBoundedByLowerMapBorder)
{
	Player test_entity;
	float time_elapsed = 0.1f;
	test_entity.setMapBounds(Vector2f(1000.f,800.f));
	test_entity.movement(GameEvent::Press_S);
	Vector2f test_position = test_entity.getPosition();
	test_entity.move(time_elapsed);
	while (test_position != test_entity.getPosition())
	{
		test_position = test_entity.getPosition();
		test_entity.move(time_elapsed);
		EXPECT_TRUE(test_entity.getPosition()._x <= test_entity.getMapBounds()._y);
	}
}

TEST (Player, canAddPointsToScore)
{
	Player test_entity;
	test_entity.addScore(100);
	EXPECT_EQ(900,test_entity.getScore());
}