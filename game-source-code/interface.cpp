#include "interface.h"
	
Interface::Interface():
	_window(sf::VideoMode(800, 600), "Dig Dug"),
	_assets()//,
//	_ground()
{
	_assets.loadAsset(EntityList::Player,"img1.png");
	_assets.loadAsset(EntityList::Enemy,"img1.png");
	_assets.loadAsset(EntityList::Ground,"dirt.png");
	_assets.loadAsset(EntityList::Splash, "img.png");
	_text.loadFromFile("sansation.ttf");
	
//	_assets.getAsset(EntityList::Ground).setRepeated(true);
//	_ground.setTexture(_assets.getAsset(EntityList::Ground));
//	_ground.setTextureRect(sf::IntRect(0, 0, 800, 400));
//	_ground.move(0,200);
}

void Interface::renderGame(vector<CharacterEntity>& list_of_characters)
{
	_window.clear(sf::Color::Blue);
	//_window.draw(_ground);
	loadTextures(list_of_characters);
	if(_paused)
	{
		drawText("Game Paused", 50.f, Vector2f(200, 150));
	}
	if(_win)
	{
		drawText("You win!", 50.f, Vector2f(200, 150));
	}
	if(_lose)
	{
		drawText("You lose!", 50.f, Vector2f(200, 150));
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
	_splashscreen.loadFromFile("img1.png", sf::IntRect(0,0,800,600));
	sf::Sprite _splashy;
	_splashy.setTexture(_splashscreen);
	_window.draw(_splashy);
	drawText("Dig Dug Version 1.0", 30, Vector2f(50, 20));
	drawText("Press Space Bar to Play", 30, Vector2f(50, 55));
	_window.display();
}