#ifndef LOGIC_H
#define LOGIC_H

#include "collisionManager.h"
#include "enemy.h"
#include "entityContainer.h"
#include "entityList.h"
#include "FileReader.h"
#include "gameEvent.h"
#include "ground.h"
#include "interface.h"
#include "player.h"
#include "timer.h"
#include "rock.h"
#include "tunnelDigger.h"
#include "vector2f.h"
#include <list>
#include <memory>
#include <ctime>
#include <vector>
#include <iostream>

using std::list;
using std::vector;

/**
* Logic class - manages how game is run.
* Contains link between SFML and game in order to render game.
*/
class Logic
{
public:
	/**
	* Constructor. Configures game setup and then proceeds to run game automatically.
	*/
	Logic();
	
private:
	/**
	* Initiates game loop which runs game.
	*/
	void startGame();
	/**
	* Updates all relevant objects after a time interval.
	* @param changeInTime is a float contained time elapsed since last update.
	*/
	void updateGame(float changeInTime);
	/**
	* Calls to Interface to display the splash screen whilst showing a countdown timer.
	* @param time is a float containing amount of time left until game is ready.
	*/
	void splashscreen(float time);
	/**
	* Calls Interface to render all objects of the game.
	*/
	void renderGame();
	/**
	* Creates Enemy objects for the game.
	*/
	void createEnemies();
	/**
	* Creates TunnelDigger objects for the game.
	*/
	void createTunnels();
	/**
	* Creates Ground objects for the game.
	*/
	void createGround();
	/**
	* Creates Rock objects for the game.
	*/
	void createRocks();
	/**
	* Notifies Interface to poll for user input and pass them to the Logic class.
	*/
	void gameInput();
	/**
	* Checks for any object collisions and removes objects which are destroyed.
	*/
	void collisions();
	/**
	* Pauses current game state so that no activity takes place.
	*/
	void pause();
	/**
	* Sets winning status to true.
	*/
	void win();
	/**
	* Sets losing status to true.
	*/
	void lose();
	/**
	* Stops all game activity and closes the game window.
	*/
	void endGame();
	/**
	* Returns a vector of integers containing relavent game information to be displayed.
	* @return vector of int type containing relavent game information to be displayed.
	*/
	vector<int>& updateStats();
	
	Interface _interface;
	EntityContainer _entities;
	FileReader _score_history;
	vector<shared_ptr<MovingEntity>> _moving_entities;
	vector<shared_ptr<ShootingMovingEntity>> _shooting_entities;
	shared_ptr<Player> _player;
	vector<int> _stats;
	vector<Vector2f> _coords;
	
	bool _running = true;
	bool _paused = false;
	bool _splashscreen = true;
	static constexpr const auto _fps = 30.f;
	static constexpr const auto _screen_width = 1000.f;
	static constexpr const auto _screen_height = 800.f;
};

#endif