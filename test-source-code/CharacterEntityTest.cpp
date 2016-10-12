#include "entity.h"
#include "player.h"
#include "entityList.h"
#include "vector2f.h"
#include "gtest/gtest.h"
#include "characterEntity.h"

#include <iostream>

TEST (CharachterEntity, CharacterFunctionCorrectlyReturnsId)
{	
	Player test_entity;
	EXPECT_EQ(EntityList::Player, test_entity.character().getEntityKey());
}

TEST (CharachterEntity, CharacterFunctionCorrectlyReturnsDefaultPosition)
{	
	Player test_entity;
	EXPECT_EQ(Vector2f(485.f,385.f), test_entity.character().getPosition());
}
