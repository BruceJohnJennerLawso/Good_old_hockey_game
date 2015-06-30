// clock.cpp ///////////////////////////////////////////////////////////////////
// The timeclock object for the table hockey game, /////////////////////////////
// interfaces with the adafruit lcd libraries //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"

#include "clock.h"

#ifdef PRESEASON

#include <iostream>
void print(String output)
{	
	std::cout << output << std::endl;
}

void print(String output, int constructor_arg, String fin)
{	
	std::cout << output << constructor_arg << fin << std::endl;
}

#else
void print(String output)
{	
}

void print(String output, int constructor_arg, String fin)
{
}

#endif




bool Flip(bool input)
{	if(input == true)
	{	return false;
	}
	else
	{	return true;
	}
}


bool Equal(score team1, score team2)
{	if(team1 == team2)
	{	return true;
	}
	return false;
}


// Period class ////////////////////////////////////////////////////////////////

Period::Period()
{
	Time = -1;
	// flag that something is wrong since we are constructed without
	// sufficient arguments using the default constructor
	homeScore = 0;
	awayScore = 0;
	clockRunning = false;
	periodStarted = false;
	periodEnded = false;
}

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
	periodStarted = false;
	periodEnded = false;
}

Period::Period(int period_minutes)
{
	Time = period_minutes*60;
	homeScore = 0;
	awayScore = 0;
	clockRunning = false;
	periodStarted = false;
	periodEnded = false;
}


Period Period::operator= (const Period p)
{	Time = p.Time;
	clockRunning = p.clockRunning;
	
	homeScore = p.homeScore;
	awayScore = p.awayScore;
	periodEnded = p.periodEnded;
	
	return (*this);		
}

void Period::setPeriodTime(seconds new_time)
{	Time = new_time;
}

void Period::Update(seconds deltat)
{	if(clockRunning == true)
	{
		Time -= deltat;
		if(Time < 0)
		{	
			print("period has ended");
			Time = 0;
			// no negative times
			clockRunning = Flip(clockRunning);
			this->endPeriod();
			// stop the clock at zero and set the state
		}
	}
}


seconds Period::getPeriodTime()
{
	return Time;
}

bool Period::periodOver()
{	return periodEnded;
}

void Period::endPeriod()
{	periodEnded = true;
}

bool Period::isPeriodStarted()
{	return periodStarted;
}

score Period::getHomeScore()
{	return homeScore;
}

score Period::getAwayScore()
{	return awayScore;
}

void Period::Faceoff()
{
	this->startClock();
}

void Period::Goal(player scoredBy)
{	
	this->stopClock();
	if(scoredBy == away)
	{	awayScore += 1;
	}
	else if(scoredBy == home)
	{	homeScore += 1;
	}
}

void Period::stopClock()
{	
	if(clockRunning == true)
	{	clockRunning = Flip(clockRunning);
	}
}

bool Period::clockIsRunning()
{	return clockRunning;
}

void Period::startClock()
{		
	if(periodEnded == false)
	{	if(clockRunning == false)
		{
			clockRunning = Flip(clockRunning);
		}	
	}
	else
	{	//std::cout << "Unable to resume period, is over" << std::endl;
	}
}

String Period::getClockOutput()
{
	
	int minutes = 0;
		
	int timeval = Time;
		
	if(timeval >= 60)
	{	while(timeval>= 60)
		{	minutes += 1;
			timeval -= 60;
		}
	}
	#ifdef PRESEASON
		// ahh, we need something to test here
		
		std::string output = std::to_string(minutes);
		output.append(":");
		if(timeval < 10)
		{	// tack on leading 0 so it looks right
			output.append("0");
		}
		output.append(std::to_string(timeval));
		return output;
	#else
		// real deal here running on the arduino, so we need to properly
		// use the arduino string type provided for us
		String output = "";
		output.concat(minutes);
		output.concat(":");
		if(timeval < 10)
		{	// tack on leading 0 so it looks right
			output.concat("0");
		}
		output.concat(timeval);
		return output;
		// there we go
	#endif
	
}

Period::~Period()
{
}
