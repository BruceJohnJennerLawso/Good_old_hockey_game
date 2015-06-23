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
	
	while(!goodOldHockey.
	
	goodOldHockey.startClock();
	goodOldHockey.Update(301.0);
	goodOldHockey.startClock();	
	goodOldHockey.Update(301.0);	
	goodOldHockey.startClock();	
	goodOldHockey.Update(301.0);	
	
	std::cout << goodOldHockey.getNumberOfPeriods() << std::endl;	
	return 0;
}


