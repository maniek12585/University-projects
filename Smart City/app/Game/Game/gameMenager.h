#pragma once
#include "SDL.h"

class gameMenager
{
	bool isRunning;
public:

	bool getIsRunning() {return isRunning;}
	void setIsRunning(bool var) {isRunning = var; }
	
	gameMenager() 
	{
		isRunning = false;
	}
	~gameMenager()
	{
		
	}
};


