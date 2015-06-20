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

Period::Period(seconds init_time, int period_minutes)
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

void Period::Update(seconds deltat)
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


seconds Period::getPeriodTime()
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
	#ifdef PRESEASON
		// ahh, we need something to test here
		
		int minutes = 0;
		
		int timeval = Time;
		
		if(timeval >= 60)
		{	while(timeval>= 60)
			{	minutes += 1;
				timeval -= 60;
			}
		}
		std::string output = std::to_string(minutes);
		output.append(":");
		if(timeval < 10)
		{	// tack on leading 0 so it looks right
			output.append("0");
		}
		output.append(std::to_string(timeval));
		return output;
	#elif
		// real deal here running on the arduino, so we need to properly
		// use the arduino string type provided for us
		
	#endif
	
}

Period::~Period()
{
}


// Game Class /////////////////////////////////////////////////////////////////



Game::Game(int period_minutes): periodLength(period_minutes)
{
	periods = new Period[3]
	{ 
		{	(period_minutes)
		},
		{	(period_minutes)
		},
		{	(period_minutes)
		}
	};
}

void Game::Update(seconds deltat)
{	
}

void Game::Goal(player scoredBy)
{
}

Game::~Game()
{
}

