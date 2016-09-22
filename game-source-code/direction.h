#ifndef DIRECTION_H
#define DIRECTION_H

/**
* Direction strongly typed enum class - used to enumerate list of Entity directions.
* For example used to manage the movement of MovingEntity and ShootingMovingEntity objects.
*/
enum class Direction{
	Up=0, 
	Left, 
	Down, 
	Right
};

#endif