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
	Period firstPeriod(5);
	std::cout << firstPeriod.getClockOutput() << std::endl;
	return 0;
}


