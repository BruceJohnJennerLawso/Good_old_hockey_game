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


#include <exception>


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

int Game::getCurrentPeriod()
{	return currentPeriod;
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
{	//std::cout << "running Game::Update(" << deltat << ")" << std::endl;
	if(!periods[currentPeriod -1].periodOver())
	{	periods[currentPeriod -1].Update(deltat);
	}
	else
	{	
		while(periods[currentPeriod - 1].periodOver())
		{	std::cout << "Current period # " << currentPeriod << " finished" << std::endl;
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
					this->gameFinished();
					break;
				}
				
			}
		}
	}
}

bool Game::newOvertime()
{	
	std::cout << "Creating new overtime period" << std::endl;
	
	try
	{	std::cout << "starting creation of new overtime (new Period[] next)" << std::endl;
		Period * newPeriods;
		newPeriods = new Period[numberOfPeriods];
		
		std::cout << "create overtime with " << numberOfPeriods << " periods so far" << std::endl;
		
		for(int cy = 0; cy < numberOfPeriods; ++cy)
		{	newPeriods[cy] = periods[cy];
		}
		newPeriods[numberOfPeriods].setPeriodTime(periodLength);
		periods = newPeriods;
		// uhh, I think this should work...
	}
	catch(std::exception& e)
	{	std::cout << e.what() << std::endl;
	}
	
	std::cout << "Successfully created new overtime period" << std::endl;
	return true;
}


void Game::startClock()
{	
	periods[currentPeriod -1].startClock();
}

bool Game::clockIsRunning()
{	
	return periods[currentPeriod-1].clockIsRunning();
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
{	return gameOver;
}

void Game::gameIsOver()
{	if(currentPeriod > 3)
	{	// in overtime, goal was scored, but the program dont know to close
		// just yet, cause usually the period isnt over by the usual way of
		// the clock running out
		periods[currentPeriod -1].endPeriod();
	}
	gameOver = Flip(gameOver);
}

Game::~Game()
{
}

