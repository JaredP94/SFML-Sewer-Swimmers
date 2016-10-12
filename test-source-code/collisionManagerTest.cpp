#include "gtest/gtest.h"
#include "entityContainer.h"
#include "player.h"
#include "collisionManager.h"
#include "enemy.h"

#include <iostream>

using std::make_shared;
using std::shared_ptr;

TEST (CollisionManager, detectsCollisionBetweenTwoEntities)
{
	EntityContainer test_entity;
	vector<shared_ptr<MovingEntity>> test_moving_entity;
	shared_ptr<Player> player_ptr = make_shared<Player>();
	player_ptr->setPosition(-85, -85);
	shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>(Vector2f(400.f,300.f));
	
	test_entity.addEntity(player_ptr);
	test_entity.addEntity(enemy_ptr);
	test_moving_entity.push_back(player_ptr);
	test_moving_entity.push_back(enemy_ptr);
	
	CollisionManager test_collisions(test_entity.start_pos(),test_entity.end_pos(),test_moving_entity.begin(),test_moving_entity.end());
	EXPECT_EQ(4,player_ptr->getNumberOfLives());
}