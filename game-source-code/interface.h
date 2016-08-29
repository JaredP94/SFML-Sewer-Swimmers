#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>
#include "assetManager.h"
#include "characterEntity.h"
#include "entityList.h"
#include "gameEvent.h"
#include "vector2f.h"
#include <iostream>
#include <list>

using std::list;

class Interface
{
public:
	Interface();
	void renderGame(list<CharacterEntity>& list_of_characters);
	list<GameEvent> convertEvents();
	void closeWindow();
	void processEvents();
	sf::Vector2f convertVectorType(Vector2f orig_vec);
	void pauseGame();
	void winGame();
	void loseGame();
	
private:
	void loadTextures(list<CharacterEntity>& list_of_characters);
	void drawSprite(const sf::Sprite& texture);
	void drawText(std::string displayText, float textSize, const Vector2f& textPos);
	
	list<GameEvent> _events;
	sf::RenderWindow _game_window;
	sf::View _player_lives;
	AssetManager<sf::Texture, EntityList> _assets;
	sf::Sprite _ground;
	sf::Font _game_text;
	
	bool _paused = false;
	bool _win = false;
	bool _lose = false;
	
	
	
};

#endif