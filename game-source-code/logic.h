#ifndef LOGIC_H
#define LOGIC_H

#include "entityContainer.h"
#include "entityList.h"
#include "gameEvent.h"
#include "Interface.h"
#include "player.h"
#include "timer.h"
#include "vector2f.h"
#include <list>
#include <memory>
#include <ctime>

using std::list;

class Logic
{
public:
	Logic();
	
private:
	void startGame();
	void updateGame(float changeInTime);
	void renderGame();
	void createObjects();
	void gameInput();
	void pause();
	void win();
	void lose();
	void endGame();
	
	Interface _interface;
	EntityContainer _entities;
	list<shared_ptr<MovingEntity>> _moving_entities;
	shared_ptr<Player> _player;
	
	bool _running = true;
	bool _paused = false;
	static constexpr const auto _fps = 60.f;
};

#endif