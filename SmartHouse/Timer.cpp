#include "Timer.h"



Timer::Timer(Hub *_hub)
{
	launched = true;
	hub = _hub;
}


Timer::~Timer()
{
}


void Timer::run()
{
	int curTime = 0;
	while (true) {
		if (!launched)
			return;

		printf("time = %d сек.\n", curTime);
		hub->OnTimerTick(curTime);
		curTime += 1;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

void Timer::stop()
{
	launched = false;
}
