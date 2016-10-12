#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "assetManager.h"
#include "characterEntity.h"
#include "EntityContainer.h"
#include "entityList.h"
#include "gameEvent.h"
#include "vector2f.h"
#include <list>
#include <vector>

using std::list;
using std::vector;

/**
* Interface class - manages how game is rendered.
* Contains link between game logic and SFML to render logic of game.
*/
class Interface
{
public:
	/**
	* Constructor. Loads all required assets for game rendering and creates game window.
	*/
	Interface();
	/**
	* Renders all game objects and information to game window.
	* @param list_of_characters is a vector of CharacterEntity objects which are required to be rendered.
	* @param list_of_entities is an EntityContainer with Entity objects which are checked for inflate or deflate animation rendering.
	* @param stats is a reference to a vector of ints which contain game information which is required to be displayed to the user.
	*/
	void renderGame(vector<CharacterEntity>& list_of_characters, EntityContainer list_of_entities, vector<int>& stats);
	/**
	* Converts polled events from the Interface to GameEvent events for the Logic class.
	*/
	list<GameEvent> interfaceInstructions();
	/**
	* Closes the game window.
	*/
	void closeWindow();
	/**
	* Manages polling for user input since last processEvents() call was made.
	*/
	void processEvents();
	/**
	* Converts game Vector2f to sf::Vector2f for Interface functions.
	* @param orig_vec is a Vector2f which is required to be converted to sf::Vector2f.
	* @return sf::Vector2f containing converted vector.
	*/
	sf::Vector2f createSFMLVector(Vector2f orig_vec);
	/**
	* Manages rendering of game based on it's paused status.
	*/
	void pauseGame();
	/**
	* Manages rendering of game based on it's win status.
	*/
	void winGame();
	/**
	* Manages rendering of game based on it's lose status.
	*/
	void loseGame();
	/**
	* Renders the splash screen and displays a timer of countdown until game is ready to play.
	* @param time is an int containing the time remaining until the game is ready to play.
	*/
	void renderSplash(int time);
	/**
	* Renders the inflating animation of an Entity object.
	* @param time is a float containing the time elapsed since the inflate animation began.
	* @param position is a const reference to a Vector2f containing the Entity object's position for the animation to occur.
	*/
	void inflateAnimation(float time, const Vector2f& position);
	/**
	* Renders the deflating animation of an Entity object.
	* @param time is a float containing the time remaining before the deflation animation is complete.
	* @param position is a const reference to a Vector2f containing the Entity object's position for the animation to occur.
	*/
	void deflateAnimation(float time, const Vector2f& position);
	/**
	* Loads in music file to play game soundtrack whilst game play occurs.
	*/
	void playMusic();
	
private:
	/**
	* Creates and draws an sf::Sprite for each Entity that is required to be rendered.
	* @param list_of_characters is a vector of CharacterEntity object which are required to be rendered.
	*/
	void loadTextures(vector<CharacterEntity>& list_of_characters);
	/**
	* Draws sprites to be displayed on the game window.
	* @param texture is a const reference to an sf::Sprite containing the texture to be assigned and drawn.
	*/
	void drawSprite(const sf::Sprite& texture);
	/**
	* Renders text to be displayed on the game window.
	* @param displayText is a string containing the text to be displayed.
	* @param textSize is a float containing the size of the text to be displayed.
	* @param textPos is a const reference to a Vector2f containing the coordinates of where the text is to be displayed.
	*/
	void drawText(std::string displayText, float textSize, const Vector2f& textPos);
	/**
	* Renders game information to game window.
	*/
	void updateGameStats(vector<int>& stats);
	
	list<GameEvent> _game_instructions;
	sf::RenderWindow _window;
	AssetManager<sf::Texture, EntityList> _assets;
	sf::Font _text;
	sf::Music _music;
	sf::Texture _animation;
	sf::Sprite _render_animation;
	
	bool _paused = false;
	bool _win = false;
	bool _lose = false;
	
	
	
};

#endif