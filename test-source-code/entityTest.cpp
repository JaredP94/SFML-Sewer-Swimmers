#include "entity.h"
#include "player.h"
#include "entityList.h"
#include "vector2f.h"
#include "gtest/gtest.h"
#include "characterEntity.h"

#include <iostream>

TEST (entity, CharacterFunctionCorrectlyReturnsId)
{	
	Player test_entity;
	EXPECT_EQ(EntityList::Player, test_entity.character().getEntityKey());
}

TEST (entity, CharacterFunctionCorrectlyReturnsDefaultPosition)
{	
	Player test_entity;
	EXPECT_EQ(Vector2f(485.f,385.f), test_entity.character().getPosition());
}

TEST (entity, SetCenterFunctionCorrectlyCentersEntity)
{	
	Player test_entity;
	test_entity.setCentre();
	EXPECT_EQ(Vector2f(500.f,400.f), test_entity.character().getPosition());
}

TEST (entity, SetPositionFunctionCorrectlyMovesEntity)
{	
	Player test_entity;
	test_entity.setPosition(100.f,100.f);
	EXPECT_EQ(Vector2f(585.f,485.f), test_entity.character().getPosition());
}

TEST (entity, getEntityKeyFunctionCorrectlyReturnsEntityKey)
{
	Player test_entity;
	EXPECT_EQ(EntityList::Player, test_entity.getEntityKey());
}

TEST (entity, getMapBoundsReturnsCorrectDefaultValue)
{
	Player test_entity;
	EXPECT_EQ(Vector2f(1000.f,800.f), test_entity.getMapBounds());
}

TEST (entity, setMapBoundsFunctionCorrectlySetsMapBounds)
{
	Player test_entity;
	Entity::setMapBounds(Vector2f(500.f,400.f));
	EXPECT_EQ(Vector2f(500.f,400.f),test_entity.getMapBounds());
}

TEST (entity, EntityInitializedWithDestroyedStatusEqualToFalse)
{
	Player test_entity;
	EXPECT_FALSE(test_entity.checkIfDestroyed());
}

TEST (entity, destroyFunctionIntializesDestroyedStatusToTrue)
{
	Player test_entity;
	test_entity.destroy();
	EXPECT_TRUE(test_entity.checkIfDestroyed());
}