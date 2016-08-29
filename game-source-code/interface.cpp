#include "interface.h"
	
Interface::Interface():
	_game_window(sf::VideoMode(800, 600), "Dig Dug"),
	_assets(),
	_ground()
{
	_assets.loadAsset(EntityList::Player,"img.png");
	_assets.loadAsset(EntityList::Ground,"dirt.png");
	_game_text.loadFromFile("sansation.ttf");
	
	_assets.get(EntityList::Ground).setRepeated(true);
	_ground.setTexture(_assets.get(EntityList::Ground));
	_ground.setTextureRect(sf::IntRect(0, 200, 800, 600));
}

void Interface::renderGame(list<CharacterEntity>& list_of_characters)
{
	_game_window.clear();
	_game_window.draw(_ground);
	loadTextures(list_of_characters);
	if(_paused)
	{
		drawText("Game Paused", 50.f, Vector2f(200, 150));
	}
	if(_win)
	{
		drawText("You win!", 50.f, Vector2f(200, 150));
		drawText("Press Esc to exit", 100.f, Vector2f(200, 150));
	}
	if(_lose)
	{
		drawText("You lose!", 50.f, Vector2f(200, 150));
		drawText("Press Esc to exit", 100.f, Vector2f(200, 150));
	}
	_game_window.display();
}

list<GameEvent> Interface::convertEvents()
{
	return _events;
}

void Interface::closeWindow()
{
	_game_window.close();
}

void Interface::processEvents()
{
	_events.clear();
	sf::Event event;
	while(_game_window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::KeyPressed:
				switch(event.key.code)
				{
					case sf::Keyboard::W:
						_events.push_back(GameEvent::Press_W);
						break;
					case sf::Keyboard::S:
						_events.push_back(GameEvent::Press_S);
						break;
					case sf::Keyboard::A:
						_events.push_back(GameEvent::Press_A);
						break;
					case sf::Keyboard::D:
						_events.push_back(GameEvent::Press_D);
						break;
					case sf::Keyboard::P:
						_events.push_back(GameEvent::Press_P);
						break;
					case sf::Keyboard::Escape:
						_events.push_back(GameEvent::Press_Esc);
						break;
					default:
						break;
				}
				break;
			case sf::Event::KeyReleased:
				switch(event.key.code)
				{
					case sf::Keyboard::W:
						_events.push_back(GameEvent::Release_W);
						break;
					case sf::Keyboard::S:
						_events.push_back(GameEvent::Release_S);
						break;
					case sf::Keyboard::A:
						_events.push_back(GameEvent::Release_A);
						break;
					case sf::Keyboard::D:
						_events.push_back(GameEvent::Release_D);
						break;
					default:
						break;
				}
				break;
			case sf::Event::Closed:
				_events.push_back(GameEvent::Closed_Window);
				break;
			default:
				break;
		}
	}
}

sf::Vector2f Interface::convertVectorType(Vector2f orig_vec)
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
	
void Interface::loadTextures(list<CharacterEntity>& list_of_characters)
{
	for(auto character : list_of_characters)
	{
		sf::Sprite charcater_sprite;
		charcater_sprite.setTexture(_assets.get(character.getEntityKey()));
		charcater_sprite.setPosition(convertVectorType(character.getPosition()));
		drawSprite(charcater_sprite);
	}
}

void Interface::drawSprite(const sf::Sprite& texture)
{
	_game_window.draw(texture);
}
	
void Interface::drawText(std::string displayText, float textSize, const Vector2f& textPos)
{
	sf::Text text;
	text.setFont(_game_text);
	text.setString(displayText);
	text.setCharacterSize(textSize);
	text.setColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold);
	text.setPosition(convertVectorType(textPos));
	_game_window.draw(text);
}