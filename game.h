// game.hpp ////////////////////////////////////////////////////////////////////
// Game object that contains a dynamic list of periods /////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#ifndef gAmE
#define gAmE


#include "clock.h"
#include "display.h"

class Game
{	public:
	Game(int period_minutes);
	
	Game(const Game& other);
	
	Game& operator =(const Game& other);
	
	private:
	Period * periods;
	seconds periodLength;
	
	int numberOfPeriods;
	
	int currentPeriod;
	// use 1, 2, 3, here, for more readable to hockey fans than the
	// programming convention of starting at 0		
	
	bool gameEnded;
	
	public:
	
	int getNumberOfPeriods();
	//int getCurrentPeriod();
	String getCurrentPeriod();
	String getClockOutput();
	#ifdef PRESEASON
	
	void printClockOutput();
	
	#endif

	
	bool inOvertime();
	void Update(seconds deltat);
	void Update(seconds deltat, Display &display);	
	
	bool newOvertime();
	// use return value to catch any "cant allocate more memory"
	// exceptions
	
	// maybe we can get away with using exceptions here if we are
	// very careful
	
	void startClock();
	void stopClock();
	void toggleClock();
	bool clockIsRunning();
	
	void Goal(player scoredBy);
	score getHomeScore();
	score getAwayScore();
	
	bool gameFinished();
	
	void gameOver();
	~Game();

};

#endif
