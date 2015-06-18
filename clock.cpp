// clock.cpp ///////////////////////////////////////////////////////////////////
// The timeclock object for the table hockey game, /////////////////////////////
// interfaces with the adafruit lcd libraries //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"

#include "clock.hpp"

bool Flip(bool input)
{	if(input == true)
	{	return false;
	}
	else
	{	return true;
	}
}


// Period class ///////////////////////////////////////////////////////////////

Period::Period(time init_time, int period_minutes)
{	if(init_time < (period_minutes*60))
	{	Time = init_time;
	}
	else
	{	Time = (period_minutes*60);
		// lets sanity/sanitize check here and not let the user screw
		// up things
	}
	homeScore = 0;
	awayScore = 0;
	clockRunning = false;
}

Period::Period(int period_minutes)
{
	Time = period_minutes*60;
	homeScore = 0;
	awayScore = 0;
	clockRunning = false;
}

void Period::Update(time deltat)
{	if(clockRunning == true)
	{
		Time -= deltat;
		if(Time < 0)
		{	Time = 0;
			// no negative times
			clockRunning = Flip(clockRunning);
			// stop the clock at zero and set the state
		}
	}
}


time Period::getPeriodTime()
{
	return Time;
}

bool Period::periodOver()
{	if(Time <= 0)
	{	return true;
	}
	return false;
}

void Period::stopClock()
{	
	if(clockRunning == true)
	{	clockRunning = Flip(clockRunning);
	}
}

void Period::startClock()
{	
	if(clockRunning == false)
	{
		clockRunning = Flip(clockRunning);
	}
}

String Period::getClockOutput()
{
	
}
