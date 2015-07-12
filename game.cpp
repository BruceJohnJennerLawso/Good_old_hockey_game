// game.cpp ////////////////////////////////////////////////////////////////////
// Game object that contains a dynamic list of periods /////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include "game.h"

#ifdef PRESEASON

#include <iostream>

#endif
// Game Class /////////////////////////////////////////////////////////////////


Game::Game(int period_minutes): 

periodLength(((seconds)period_minutes)*60), numberOfPeriods(3), gameEnded(false),
currentPeriod(1)
{	
	print("Constructing Game::Game(", period_minutes, ")");
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
	print("finished constructing Game::Game");
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

#ifdef PRESEASON
	
void Game::printClockOutput()
{	std::cout << "################" << std::endl;
	std::cout << "HOME" << "  " << this->getClockOutput() << "  " << "AWAY" << std::endl;
	std::cout << this->getHomeScore() << "      " << this->getCurrentPeriod() << "      " << this->getAwayScore() << std::endl;
}
	
#endif

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
		{	
			print("Current period # ", currentPeriod, " finished");
			
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

void Game::Update(seconds deltat, Display &display)
{
	this->Update(deltat);
	
	display.printToLine(1, 0, "HOME");
	display.printToLine(1, 6, this->getClockOutput());
	display.printToLine(1, 12, "AWAY");
	
	display.printToLine(2, 0, this->getHomeScore());
	display.printToLine(2, 7, this->getCurrentPeriod());
	if(this->getAwayScore() >= 10)
	{	display.printToLine(2, 14, this->getAwayScore());
	}
	else
	{	display.printToLine(2, 15, this->getAwayScore());
	}
}

bool Game::newOvertime()
{	
	print("starting creation of new overtime (new Period[] next)");
	Period * newPeriods;
	newPeriods = new Period[numberOfPeriods];
	
	print("create overtime with ", numberOfPeriods, " periods so far");
	
	for(int cy = 0; cy < (numberOfPeriods-1); ++cy)
	{	newPeriods[cy] = periods[cy];
	}
	newPeriods[numberOfPeriods - 1].setPeriodTime(periodLength);
	periods = newPeriods;
	// uhh, I think this should work...
	return true;
}


void Game::startClock()
{	
	periods[currentPeriod -1].startClock();
}

void Game::stopClock()
{
	periods[currentPeriod -1].stopClock();
}

void Game::toggleClock()
{
	if(!this->gameFinished())
	{
		if(this->clockIsRunning() == true)
		{	this->stopClock();
		}
		else
		{	this->startClock();
		}
		// cannot figure it out, everything looks right, why isnt it working in
		// the sketch?
	}
}

bool Game::clockIsRunning()
{	
	return periods[currentPeriod-1].clockIsRunning();
}

void Game::Goal(player scoredBy)
{	
	if(!this->gameFinished())
	{	if(this->clockIsRunning() == true)
		{	
			periods[currentPeriod -1].Goal(scoredBy);
			if(this->inOvertime())
			{	this->gameOver();
			}
		}
	}
}

score Game::getHomeScore()
{	score output = 0;
	for(int cy = 0; cy < numberOfPeriods; ++cy)
	{	
		output += periods[cy].getHomeScore();
	}
	return output;
}

score Game::getAwayScore()
{	score output = 0;
	for(int cy = 0; cy < numberOfPeriods; ++cy)
	{	
		output += periods[cy].getAwayScore();
	}
	return output;
}

bool Game::gameFinished()
{	return gameEnded;
}

void Game::gameOver()
{	if(currentPeriod > 3)
	{	// in overtime, goal was scored, but the program dont know to close
		// just yet, cause usually the period isnt over by the usual way of
		// the clock running out
		periods[currentPeriod -1].endPeriod();
	}
	gameEnded = Flip(gameEnded);
}

Game::~Game()
{	delete[] periods;
}

