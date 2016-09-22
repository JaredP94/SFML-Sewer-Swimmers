#ifndef TIMER_H
#define TIMER_H

#include <ctime>

/**
* Timer class - manages all time based events, allowing time changes to be used by game functions.
*/
class Timer
{
public:
	/**
	* Constructor. Creates a Timer object.
	*/
	Timer();
	/**
	* Begins counting of the Timer object.
	*/
	void beginTimer();
	/**
	* Sets the timer to zero and returns the time elapsed.
	* @return float containing time elapsed until timer was reset.
	*/
	float resetTimer();
	/**
	* Returns time elapsed since timer bagan without resetting timer.
	* @return float containing time elapsed since timer started.
	*/
	float timeElapsed();
	
private:
	/**
	* Returns time since Timer object was created.
	* @return float containing time elapsed since Time object was created.
	*/
	float getProcessTime();
	float _initialTime = 0.f;
	
};

#endif