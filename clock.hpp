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

class gameClock
{
	public:
	gameClock(time init_time, int period_minutes);

	private:
	time Time;

	public:
	void Update(time deltat);
	time getClockTime();
	bool periodOver();
	void stopClock();
	// generic one, regardless of what event triggered the clock to stop
	void startClock();
	String getClockOutput();
	String getClockOutput(time deltat);

	~gameClock();
};

class Game
{	public:
	
	Game(int period_minutes);
	
	private:
	std::vector<gameClock> Periods;
	// dont even know if vector is gonna work here, we'll see
	// its not a problem for regular games, but we can have arbitrary
	// number of overtimes, which complicates things

	score homeScore, awayScore;

	public:
	void Update(time deltat);
	void Goal(player scoredBy);

};



#endif
