// game.cpp ////////////////////////////////////////////////////////////////////
// Game object that contains a dynamic list of periods /////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include "game.hpp"
#include <iostream>
// Game Class /////////////////////////////////////////////////////////////////



Game::Game(int period_minutes): 

periodLength(((seconds)period_minutes)*60), numberOfPeriods(3), gameOver(false),
currentPeriod(1)
{	std::cout << "Constructing Game::Game(" << period_minutes << ")";
	std::cout << std::endl;
	// ah dammit, no new in avr-gcc
	
	// or on second thought apparently it does...
	periods = new Period[3]
	{
		{	(period_minutes)
		},
		{	(period_minutes)
		},
		{	(period_minutes)
		}
		
	};
	std::cout << "finished constructing Game::Game" << std::endl;
}

int Game::getNumberOfPeriods()
{	return numberOfPeriods;
}

String Game::getClockOutput()
{	return periods[currentPeriod -1].getClockOutput();
}

bool Game::inOvertime()
{	if(currentPeriod > 3)
	{	return true;
	}
	return false;
}

void Game::Update(seconds deltat)
{	std::cout << "running Game::Update(" << deltat << ")" << std::endl;
	if(periods[currentPeriod].periodOver())
	{	
		while(periods[currentPeriod].periodOver())
		{	
			if(currentPeriod < numberOfPeriods)
			{	currentPeriod++;
			}
			else
			{	// we hit the end of the last period, so either one team
				// won and the game is over, or we are tied, heading
				// into overtime (or another overtime)
				
				// if we are heading into overtime, the array of periods
				// needs to be resized to fit the new overtime period
				// while taking on the old data from the previous ones
				
				// so our first order of business is something like
				// check if the sum of the two scores is equal
				if(Equal(getHomeScore(), getAwayScore()))
				{	// time to head to (more) overtime(s)
					numberOfPeriods++;
					if(this->newOvertime())
					{	currentPeriod++;
					}
					else
					{	// dunno what to do
					}
				}
				else
				{	// game is over, everybody go home now
					
				}
				
			}
		}
	}
	else
	{	periods[currentPeriod -1].Update(deltat);
	}
}

bool Game::newOvertime()
{	
	std::cout << "Creating new overtime period" << std::endl;
	Period * newPeriods;
	
	newPeriods = new Period[numberOfPeriods];
	for(int cy = 0; cy < numberOfPeriods; ++cy)
	{	newPeriods[cy] = periods[cy];
	}
	newPeriods[numberOfPeriods].setPeriodTime(periodLength);
	
	periods = newPeriods;
	// uhh, I think this should work...
	return true;
}


void Game::startClock()
{	
	periods[currentPeriod -1].startClock();
}

void Game::Goal(player scoredBy)
{
}

score Game::getHomeScore()
{	score output = 0;
	for(int cy = 0; cy <= numberOfPeriods; ++cy)
	{	
		output += periods[cy].getHomeScore();
	}
	return output;
}

score Game::getAwayScore()
{	score output = 0;
	for(int cy = 0; cy <= numberOfPeriods; ++cy)
	{	
		output += periods[cy].getAwayScore();
	}
	return output;
}

bool Game::gameFinished()
{
	
	gameOver = Flip(gameOver);
}

void Game::gameIsOver()
{
}

Game::~Game()
{
}

