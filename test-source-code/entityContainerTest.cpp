#include "gtest/gtest.h"
#include "entityContainer.h"
#include "player.h"
#include "enemy.h"
#include "ground.h"

#include <iostream>

using std::make_shared;
using std::shared_ptr;

TEST(EntityContainer, canAddPlayerEntityUsingAddEntityFunctionality)
{
	EntityContainer test_entity;
	shared_ptr<Player>player_ptr = make_shared<Player>();
	test_entity.addEntity(player_ptr);
	EXPECT_EQ(1,test_entity.amountOfEntities());
}

TEST(EntityContainer, canAddEnemyEntityUsingAddEntityFunctionality)
{
	EntityContainer test_entity;
	shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>();
	test_entity.addEntity(enemy_ptr);
	EXPECT_EQ(1,test_entity.amountOfEntities());
}

TEST(EntityContainer, canAddGroundEntityUsingAddEntityFunctionality)
{
	EntityContainer test_entity;
	shared_ptr<Ground> ground_ptr = make_shared<Ground>(32.f,32.f);
	test_entity.addEntity(ground_ptr);
	EXPECT_EQ(1,test_entity.amountOfEntities());
}

TEST(EntityContainer, canAddMultipleEntitiesUsingAddEntityFunctionality)
{
	EntityContainer test_entity;
	shared_ptr<Player> player_ptr = make_shared<Player>();
	shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>();
	test_entity.addEntity(player_ptr);
	test_entity.addEntity(enemy_ptr);
	EXPECT_EQ(2,test_entity.amountOfEntities());
}

TEST(EntityContainer, canDeleteFirstEntityUsingRemoveEntityFunctionality)
{
	EntityContainer test_entity;
	shared_ptr<Player> player_ptr = make_shared<Player>();
	shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>();
	test_entity.addEntity(player_ptr);
	test_entity.addEntity(enemy_ptr);
	test_entity.removeEntity(test_entity.start_pos());
	EXPECT_EQ(1,test_entity.amountOfEntities());
}

TEST(EntityContainer, canDeleteLastEntityUsingRemoveEntityFunctionality)
{
	EntityContainer test_entity;
	shared_ptr<Player> player_ptr= make_shared<Player>();
	shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>();
	test_entity.addEntity(player_ptr);
	test_entity.addEntity(enemy_ptr);
	test_entity.removeEntity(test_entity.end_pos());
	EXPECT_EQ(1,test_entity.amountOfEntities());
}

TEST(EntityContainer, canDeleteAnEntityAtRandomPositionUsingRemoveEntityFunctionality)
{
	EntityContainer test_entity;
	shared_ptr<Player> player_ptr = make_shared<Player>();
	shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>();
	shared_ptr<Ground> ground_ptr = make_shared<Ground>(100.f,100.f);
	test_entity.addEntity(player_ptr);
	test_entity.addEntity(enemy_ptr);
	test_entity.addEntity(ground_ptr);
	test_entity.removeEntity(test_entity.start_pos() + 1);
	
	EXPECT_EQ(2,test_entity.amountOfEntities());
}