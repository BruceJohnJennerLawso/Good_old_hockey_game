// preseason.cpp ///////////////////////////////////////////////////////////////
// lets test the code before it ever hits the arduino side by //////////////////
// running it in a simple C++ program //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include "game.h"

#ifdef PRESEASON

#include <iostream>

int main()
{	
	Game goodOldHockey(5);
	
	goodOldHockey.startClock();
	while(!goodOldHockey.gameFinished())
	{	if(!goodOldHockey.clockIsRunning())
		{	goodOldHockey.startClock();
		}
		goodOldHockey.Update(0.9);
		if(goodOldHockey.getCurrentPeriod() == 4)
		{	goodOldHockey.Update(10.1);
			goodOldHockey.Goal(home);
			// the home team wins...
		}
	}	
	goodOldHockey.printClockOutput();
	return 0;
}

#endif
