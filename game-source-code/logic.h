#ifndef LOGIC_H
#define LOGIC_H

#include "collisionManager.h"
#include "enemy.h"
#include "entityContainer.h"
#include "entityList.h"
#include "gameEvent.h"
#include "ground.h"
#include "Interface.h"
#include "player.h"
#include "timer.h"
#include "vector2f.h"
#include <list>
#include <memory>
#include <ctime>
#include <vector>
#include <iostream>

using std::list;
using std::vector;

class Logic
{
public:
	Logic();
	
private:
	void startGame();
	void updateGame(float changeInTime);
	void splashscreen();
	void renderGame();
	void createObjects();
	void gameInput();
	void collisions();
	void pause();
	void win();
	void lose();
	void endGame();
	vector<int>& updateStats();
	
	Interface _interface;
	EntityContainer _entities;
	vector<shared_ptr<MovingEntity>> _moving_entities;
	vector<shared_ptr<ShootingMovingEntity>> _shooting_entities;
	shared_ptr<Player> _player;
	vector<int> _stats;
	
	bool _running = true;
	bool _paused = false;
	bool _splashscreen = true;
	static constexpr const auto _fps = 30.f;
	static constexpr const auto _screen_width = 1000.f;
	static constexpr const auto _screen_height = 800.f;
};

#endif