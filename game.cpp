// game.cpp ////////////////////////////////////////////////////////////////////
// Game object that contains a dynamic list of periods /////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include "game.hpp"

// Game Class /////////////////////////////////////////////////////////////////



Game::Game(int period_minutes): 

periodLength(period_minutes), numberOfPeriods(3), gameOver(false)	 
{
	// ah dammit, no new in avr-gcc
}

int Game::getNumberOfPeriods()
{	return numberOfPeriods;
}

bool Game::inOvertime()
{	if(currentPeriod > 3)
	{	return true;
	}
	return false;
}

void Game::Update(seconds deltat)
{	
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
				if(Equal(homeScore(), awayScore()))
				{	// time to head to (more) overtime(s)
					
				}
				else
				{	// game is over, everybody go home now
					
				}
				
			}
		}
	}
}

bool Game::newOvertime()
{
	
}

void Game::Goal(player scoredBy)
{
}

score Game::homeScore()
{	
}

score Game::awayScore()
{
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

