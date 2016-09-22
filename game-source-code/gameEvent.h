#ifndef GAME_EVENT_H
#define GAME_EVENT_H

/**
* GameEvent strongly typed enum class - used to enumerate list of game events.
* Used to separate Logic and Interface classes by passing polled Interface events to game events in the game's logic.
*/
enum class GameEvent
{
	Press_Esc,
	Closed_Window,
	Press_P,
	Press_W,
	Press_A,
	Press_S,
	Press_D,
	Press_Enter,
	Press_Space,
	Release_Space,
	Release_W,
	Release_A,
	Release_S,
	Release_D,
};

#endif