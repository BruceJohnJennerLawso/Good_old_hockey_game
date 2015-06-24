// preseason.cpp ///////////////////////////////////////////////////////////////
// lets test the code before it ever hits the arduino side by //////////////////
// running it in a simple C++ program //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include <iostream>
#include "game.hpp"

int main()
{	
	Game goodOldHockey(5);
	
	goodOldHockey.startClock();
	std::cout << sizeof(Period) << std::endl;
	while(!goodOldHockey.gameFinished())
	{	if(!goodOldHockey.clockIsRunning())
		{	goodOldHockey.startClock();
		}
		goodOldHockey.Update(0.9);
		//std::cout << goodOldHockey.clockIsRunning() << " " << " " << goodOldHockey.getClockOutput() << std::endl;
	}	
	
	std::cout << goodOldHockey.getNumberOfPeriods() << std::endl;	
	return 0;
}


