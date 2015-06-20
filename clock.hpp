// clock.hpp ///////////////////////////////////////////////////////////////////
// The timeclock object for the table hockey game, /////////////////////////////
// interfaces with the adafruit lcd libraries //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"


#ifndef ClOcK
#define ClOcK

#define PRESEASON


#ifdef PRESEASON

	#include <string>
	typedef std::string String;
#else
	#include "Arduino.h"
#endif

#include <vector>

typedef double seconds;
typedef short int score;

bool Equal(score team1, score team2);


enum player {home, away};

class Period
{
	public:
	Period(seconds init_time, int period_minutes);
	Period(int period_minutes);


	private:
	seconds Time;
	bool clockRunning;
	
	score homeScore, awayScore;
	// score for this period, so we can have period by period
	// stats
	// slightly misleading name here I guess

	public:
	void Update(seconds deltat);
	seconds getPeriodTime();
	bool periodOver();
	
	bool clockIsRunning();

	void stopClock();
	// generic one, regardless of what event triggered the clock to stop
	void startClock();
	String getClockOutput();

	~Period();
};

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
