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
		Enemy::setEnemyTarget(_player);
		
		srand(time(0));
		createGround();
		createTunnels();
		createRocks();
		startGame();
	}
	
void Logic::startGame()
{
	Timer clock;
	clock.beginTimer();
	auto time_since_last_update = 0.f;
	auto time_per_frame = 1.0f/_fps;
	
	_interface.playMusic();
	
	while(_running)
	{
		if(_splashscreen || clock.timeElapsed() < 6)
		{
			clock.resetTimer();
			gameInput();
			splashscreen(6.f - clock.timeElapsed());
			time_since_last_update += clock.resetTimer();
			clock.beginTimer();
			while(time_since_last_update > time_per_frame && !_paused)
			{
				updateGame(time_per_frame);
				time_since_last_update -= time_per_frame;
			}
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
			createEnemies();
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
	
	if(Enemy::getEnemyDestroyed() == 5)
	{
		win();
	}
	
	updateStats();
}

void Logic::renderGame()
{
	std::vector<CharacterEntity> characters = _entities.characterList();
	_interface.renderGame(characters, _entities, updateStats());
}

void Logic::createEnemies()
{
	while(Enemy::getEnemiesCreated() < 5)
	{
		for(unsigned int i=0; i != _coords.size(); i++)
		{
			auto pos = _coords.at(i);
			shared_ptr<Enemy> enemy_ptr = make_shared<Enemy>(pos);
			_entities.addEntity(enemy_ptr);
			_moving_entities.push_back(enemy_ptr);
			enemy_ptr->incrementEnemiesCreated();
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
			case GameEvent::Press_Enter:
				_splashscreen = false;
			case GameEvent::Press_Space:
			case GameEvent::Release_Space:
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
		/*if((*iterator)->getInflateStatus())
		{
			_interface.inflateAnimation((*iterator)->getTimeElapsed(), (*iterator)->getPosition());
		}
		if((*iterator)->getDeflateStatus())
		{
			_interface.deflateAnimation((*iterator)->getTimeElapsed(), (*iterator)->getPosition());
		}*/
		if((*iterator)->checkIfDestroyed())
		{
			if((*iterator)->character().getEntityKey() == EntityList::TunnelDigger)
			{
				_coords.push_back((*iterator)->getPosition());
			}
			iterator = _entities.removeEntity(iterator);
//			_interface.renderExplosion(pos);
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

void Logic::splashscreen(float time)
{
	if(time <= 0)
	{
		time = 0;
	}
	_interface.renderSplash((int) time);
}

vector<int>& Logic::updateStats()
{
	_stats.clear();
	_stats = {_player->getNumberOfLives()};
	return _stats;
}

void Logic::createTunnels()
{
	auto pos_counter = 1;
	while(TunnelDigger::getDiggerQuantity() < 4)
	{
		shared_ptr<TunnelDigger> digger_ptr = make_shared<TunnelDigger>(Vector2f(pos_counter * 200, (pos_counter * 100) + 150));
		_entities.addEntity(digger_ptr);
		_moving_entities.push_back(digger_ptr);
		pos_counter++;
	}
	shared_ptr<TunnelDigger> digger_ptr = make_shared<TunnelDigger>(_player->getPosition());
	_entities.addEntity(digger_ptr);
	_moving_entities.push_back(digger_ptr);
}

void Logic::createGround()
{
	for(auto i = 0; i < _screen_width / 32; i++)
	{
		for(auto j = 6; j < _screen_height / 32; j++)
		{
			std::shared_ptr<Ground> ground_ptr = std::make_shared<Ground>(i * 32, j * 32);
			_entities.addEntity(ground_ptr);
		}
	}
}

void Logic::createRocks()
{
	std::shared_ptr<Rock> rock_ptr = std::make_shared<Rock> (129.f, 479.f);
	_entities.addEntity(rock_ptr);
	_moving_entities.push_back(rock_ptr);
	std::shared_ptr<Rock> rock_ptr2 = std::make_shared<Rock> (801.f, 479.f);
	_entities.addEntity(rock_ptr2);
	_moving_entities.push_back(rock_ptr2);
}