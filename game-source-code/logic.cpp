#include "logic.h"

Logic::Logic():
	_interface(),
	_entities(),
	_player(std::make_shared<Player>())
	{
		Entity::setMapBounds(Vector2f(800, 600));
		_entities.addEntity(_player);
		_moving_entities.push_back(_player);
		
		srand(time(0));
		
		startGame();
	}
	
void Logic::startGame()
{
	Timer clock;
	clock.beginTimer();
	auto time_since_last_update = 0.f;
	auto time_per_frame = 1.0f/_fps;
	
	while(_running)
	{
		if(_paused)
		{
			clock.resetTimer();
			gameInput();
			renderGame();
			clock.beginTimer();
		}
		else
		{
			time_since_last_update += clock.resetTimer();
			clock.beginTimer();
			
			while(time_since_last_update > time_per_frame && !_paused)
			{
				updateGame(time_per_frame);
				time_since_last_update -= time_per_frame;
			}
			renderGame();
		}
	}
}

void Logic::updateGame(float changeInTime)
{
	gameInput();
	
	createObjects();
	
	for(auto moving_entity : _moving_entities)
	{
		moving_entity->move(changeInTime);
	}
	
	if(_player->checkIfDestroyed())
	{
		lose();
	}
}

void Logic::renderGame()
{
	std::list<CharacterEntity> characters = _entities.characterList();
	_interface.renderGame(characters);
}

void Logic::createObjects()
{
	
}

void Logic::gameInput()
{
	_interface.processEvents();
	std::list<GameEvent> events_since_last_poll = _interface.convertEvents();
	for(auto event : events_since_last_poll)
	{
		switch(event)
		{
			case GameEvent::Press_W:
			case GameEvent::Press_A:
			case GameEvent::Press_S:
			case GameEvent::Press_D:
			case GameEvent::Release_W:
			case GameEvent::Release_A:
			case GameEvent::Release_S:
			case GameEvent::Release_D:
				_player->movement(event);
				break;
			case GameEvent::Press_P:
				pause();
				_interface.pauseGame();
				break;
			case GameEvent::Press_Esc:
			case GameEvent::Closed_Window:
				endGame();
				break;
			default:
				break;
		}
	}
}

void Logic::pause()
{
	_paused = !_paused;
}

void Logic::win()
{
	_interface.winGame();
	pause();
}
	
void Logic::lose()
{
	_interface.loseGame();
	pause();
}

void Logic::endGame()
{
	_interface.closeWindow();
	_running = false;
}