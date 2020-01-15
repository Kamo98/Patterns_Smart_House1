#pragma once
#include <thread>
#include "Hub.h"

class Timer
{
private:
	bool launched;
	Hub *hub;
public:

	Timer(Hub *_hub);
	~Timer();
	void run();
	void stop();
};

