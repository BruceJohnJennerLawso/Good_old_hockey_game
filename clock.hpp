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

#include "Arduino.h"
#include <vector>

typedef double time;
typedef short int score;

enum player {home, away};

class Period
{
	public:
	Period(time init_time, int period_minutes);
	Period(int period_minutes);


	private:
	time Time;
	bool clockRunning;
	
	score homeScore, awayScore;
	// score for this period, so we can have period by period
	// stats
	// slightly misleading name here I guess

	public:
	void Update(time deltat);
	time getPeriodTime();
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
	
	public:
	void Update(time deltat);
	void Goal(player scoredBy);
	~Game();

};



#endif
