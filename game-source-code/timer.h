#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
public:
	Timer();
	void beginTimer();
	float resetTimer();
	
private:
	float getProcessTime();
	float _initialTime = 0.f;
	
};

#endif