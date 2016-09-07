#include "interface.h"
	
Interface::Interface():
	_window(sf::VideoMode(1000, 800), "Dig Dug"),
	_assets()
{
	_assets.loadAsset(EntityList::Player,"img1.png");
	_assets.loadAsset(EntityList::Enemy,"monster1.png");
	_assets.loadAsset(EntityList::Ground,"dirt.png");
	_assets.loadAsset(EntityList::Harpoon, "harpoon.png");
	_assets.loadAsset(EntityList::Num_Lives, "img1.png");
	_text.loadFromFile("sansation.ttf");
	_music.openFromFile("Arcade.ogg");
}

void Interface::renderGame(vector<CharacterEntity>& list_of_characters, vector<int>& stats)
{
	_window.clear(sf::Color::Blue);
	loadTextures(list_of_characters);
	updateGameStats(stats);
	if(_paused)
	{
		drawText("Game Paused", 50.f, Vector2f(300, 400));
	}
	if(_win)
	{
		drawText("You win!", 50.f, Vector2f(400, 400));
	}
	if(_lose)
	{
		drawText("You lose!", 50.f, Vector2f(400, 400));
	}
	_window.display();
}

list<GameEvent> Interface::interfaceInstructions()
{
	return _game_instructions;
}

void Interface::closeWindow()
{
	_window.close();
}

void Interface::processEvents()
{
	_game_instructions.clear();
	sf::Event event;
	while(_window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::KeyPressed:
				switch(event.key.code)
				{
					case sf::Keyboard::W:
						_game_instructions.push_back(GameEvent::Press_W);
						break;
					case sf::Keyboard::S:
						_game_instructions.push_back(GameEvent::Press_S);
						break;
					case sf::Keyboard::A:
						_game_instructions.push_back(GameEvent::Press_A);
						break;
					case sf::Keyboard::D:
						_game_instructions.push_back(GameEvent::Press_D);
						break;
					case sf::Keyboard::Return:
						_game_instructions.push_back(GameEvent::Press_Enter);
						break;
					case sf::Keyboard::P:
						_game_instructions.push_back(GameEvent::Press_P);
						break;
					case sf::Keyboard::Escape:
						_game_instructions.push_back(GameEvent::Press_Esc);
						break;
					case sf::Keyboard::Space:
						_game_instructions.push_back(GameEvent::Press_Space);
						break;
					default:
						break;
				}
				break;
			case sf::Event::KeyReleased:
				switch(event.key.code)
				{
					case sf::Keyboard::W:
						_game_instructions.push_back(GameEvent::Release_W);
						break;
					case sf::Keyboard::S:
						_game_instructions.push_back(GameEvent::Release_S);
						break;
					case sf::Keyboard::A:
						_game_instructions.push_back(GameEvent::Release_A);
						break;
					case sf::Keyboard::D:
						_game_instructions.push_back(GameEvent::Release_D);
						break;
					case sf::Keyboard::Space:
						_game_instructions.push_back(GameEvent::Release_Space);
						break;
					default:
						break;
				}
				break;
			case sf::Event::Closed:
				_game_instructions.push_back(GameEvent::Closed_Window);
				break;
			default:
				break;
		}
	}
}

sf::Vector2f Interface::createSFMLVector(Vector2f orig_vec)
{
	return sf::Vector2f(orig_vec._x, orig_vec._y);
}

void Interface::pauseGame()
{
	_paused = !_paused;
}

void Interface::winGame()
{
	_win = true;
}

void Interface::loseGame()
{
	_lose = true;
}
	
void Interface::loadTextures(vector<CharacterEntity>& list_of_characters)
{
	for(auto character : list_of_characters)
	{
		sf::Sprite charcater_sprite;
		charcater_sprite.setTexture(_assets.getAsset(character.getEntityKey()));
		charcater_sprite.setPosition(createSFMLVector(character.getPosition()));
		drawSprite(charcater_sprite);
	}
}

void Interface::drawSprite(const sf::Sprite& texture)
{
	_window.draw(texture);
}
	
void Interface::drawText(std::string displayText, float textSize, const Vector2f& textPos)
{
	sf::Text text;
	text.setFont(_text);
	text.setString(displayText);
	text.setCharacterSize(textSize);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition(createSFMLVector(textPos));
	_window.draw(text);
}

void Interface::renderSplash()
{
	sf::Texture _splashscreen;
	_splashscreen.loadFromFile("start.png", sf::IntRect(0,0,1000,800));
	sf::Sprite _splashy;
	_splashy.setTexture(_splashscreen);
	_window.draw(_splashy);
	drawText("Dig Dug Version 1.0", 30, Vector2f(50, 20));
	drawText("Press Enter to Play", 30, Vector2f(50, 55));
	_window.display();
}

void Interface::playMusic()
{
	_music.play();
}

void Interface::updateGameStats(vector<int>& stats)
{
	Vector2f sprite_location(0,5);
	auto num_lives = stats.at(0);
	for(auto index = 0; index < num_lives; index++)
	{
		sf::Sprite _stat_sprite;
		_stat_sprite.setTexture(_assets.getAsset(EntityList::Num_Lives));
		_stat_sprite.setPosition(createSFMLVector(sprite_location));
		sprite_location += Vector2f(32,0);
		_window.draw(_stat_sprite);
	}
}

/*void Interface::renderExplosion()
{
	sf::Texture _explosionTexture;
	_explosionTexture.loadFromFile("explosion.png");
	sf::Sprite _explosion(_explosionTexture);
	_explosion.setPosition(200,200);
	for(auto i = 0; i < 16; i++)
	{
		_explosion.setTextureRect(sf::IntRect(i * 32,0,32,32));
		_window.draw(_explosion);
		_window.display();
	}
}*/