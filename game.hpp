// game.hpp ////////////////////////////////////////////////////////////////////
// Game object that contains a dynamic list of periods /////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"

#include "clock.hpp"


#ifndef gAmE
#define gAmE

class Game
{	public:
	Game(int period_minutes);
	
	private:
	Period * periods;
	int periodLength;
	
	int numberOfPeriods;
	
	int currentPeriod;
	// use 1, 2, 3, here, for more readable to hockey fans than the
	// programming convention of starting at 0		
	
	bool gameOver;
	
	public:
	
	int getNumberOfPeriods();
	
	bool inOvertime();
	void Update(seconds deltat);
	
	bool newOvertime();
	// use return value to catch any "cant allocate more memory"
	// exceptions
	
	// maybe we can get away with using exceptions here if we are
	// very careful
	
	void Goal(player scoredBy);
	score homeScore();
	score awayScore();
	
	bool gameFinished();
	
	void gameIsOver();
	~Game();

};

#endif
