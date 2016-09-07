#include "timer.h"

Timer::Timer()
{}

void Timer::beginTimer()
{
	_initialTime = getProcessTime();
}

float Timer::resetTimer()
{
	auto elapsedTime = getProcessTime() - _initialTime;
	return elapsedTime;
}

float Timer::timeElapsed()
{
	return getProcessTime();
}
	
float Timer::getProcessTime()
{
	clock_t currentTime = clock();
	return static_cast<float>(currentTime)/CLOCKS_PER_SEC;
}