#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>
#include "assetManager.h"
#include "characterEntity.h"
#include "entityList.h"
#include "gameEvent.h"
#include "vector2f.h"
#include <list>
#include <vector>

using std::list;
using std::vector;

class Interface
{
public:
	Interface();
	void renderGame(vector<CharacterEntity>& list_of_characters);
	list<GameEvent> interfaceInstructions();
	void closeWindow();
	void processEvents();
	sf::Vector2f createSFMLVector(Vector2f orig_vec);
	void pauseGame();
	void winGame();
	void loseGame();
	void renderSplash();
	
private:
	void loadTextures(vector<CharacterEntity>& list_of_characters);
	void drawSprite(const sf::Sprite& texture);
	void drawText(std::string displayText, float textSize, const Vector2f& textPos);
	
	list<GameEvent> _game_instructions;
	sf::RenderWindow _window;
	sf::View _player_lives;
	AssetManager<sf::Texture, EntityList> _assets;
	sf::Font _text;
	
	bool _paused = false;
	bool _win = false;
	bool _lose = false;
	
	
	
};

#endif