#include "logic.h"

Logic::Logic():
	_interface(),
	_entities(),
	_player(std::make_shared<Player>())
	{
		Entity::setMapBounds(Vector2f(_screen_width, _screen_height));
		_entities.addEntity(_player);
		_moving_entities.push_back(_player);
		_shooting_entities.push_back(_player);
		
		createObjects();
		
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
		if(_splashscreen)
		{
			clock.resetTimer();
			gameInput();
			splashscreen();
			clock.beginTimer();
		}
		else if(_paused)
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
	
	for(auto moving_entity : _moving_entities)
	{
		moving_entity->move(changeInTime);
	}
	
	collisions();
	
	for(auto shooting_entity : _shooting_entities)
	{
		shared_ptr<MovingEntity> moving_entity_ptr = shooting_entity->shoot(changeInTime);
		if(moving_entity_ptr)
		{
			_entities.addEntity(moving_entity_ptr);
			_moving_entities.push_back(moving_entity_ptr);
		}
	}
	
	if(_player->checkIfDestroyed())
	{
		lose();
	}
	
	if(Enemy::getEnemyQuantity() == 0)
	{
		win();
	}
}

void Logic::renderGame()
{
	std::vector<CharacterEntity> characters = _entities.characterList();
	_interface.renderGame(characters);
}

void Logic::createObjects()
{
	for(auto i = 0; i < 5; i++)
	{
		shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>();
		_entities.addEntity(enemy_ptr);
		_moving_entities.push_back(enemy_ptr);
	}
	
	for(auto i = 0; i < _screen_width / 32; i++)
	{
		for(auto j = 6; j < _screen_height / 32; j++)
		{
			std::shared_ptr<Ground> ground_ptr = std::make_shared<Ground>(i * 32, j * 32);
			_entities.addEntity(ground_ptr);
		}
	}
}

void Logic::gameInput()
{
	_interface.processEvents();
	list<GameEvent> new_instructions = _interface.interfaceInstructions();
	for(auto event : new_instructions)
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
			case GameEvent::Press_Space:
				_splashscreen = false;
			case GameEvent::Press_E:
			case GameEvent::Release_E:
				_player->shooting(event);
				break;
			default:
				break;
		}
	}
}

void Logic::collisions()
{
	CollisionManager entityCollisions(_entities.start_pos(), _entities.end_pos(), _moving_entities.begin(), _moving_entities.end());
	
	for(auto iterator = _entities.start_pos(); iterator != _entities.end_pos();)
	{
		if((*iterator)->checkIfDestroyed())
		{
			iterator = _entities.removeEntity(iterator);
		}
		else
		{
			iterator++;
		}
	}
	
	for(auto iterator = std::begin(_moving_entities); iterator != std::end(_moving_entities);)
	{
		if((*iterator)->checkIfDestroyed())
		{
			iterator = _moving_entities.erase(iterator);
		}
		else
		{
			iterator++;
		}
	}
	
	for(auto iterator = std::begin(_shooting_entities); iterator != std::end(_shooting_entities);)
	{
		if((*iterator)->checkIfDestroyed())
		{
			iterator = _shooting_entities.erase(iterator);
		}
		else
		{
			iterator++;
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

void Logic::splashscreen()
{
	_interface.renderSplash();
}