// clock.hpp ///////////////////////////////////////////////////////////////////
// The timeclock object for the table hockey game, /////////////////////////////
// interfaces with the adafruit lcd libraries //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include <stdlib.h>
// why malloc why

#ifndef ClOcK
#define ClOcK

#define PRESEASON


#ifdef PRESEASON

	#include <string>
	typedef std::string String;
#else
	#include "Arduino.h"
#endif


bool Flip(bool input);


typedef double seconds;
typedef short int score;

bool Equal(score team1, score team2);


enum player {home, away};

class Period
{
	public:
	Period(seconds init_time, int period_minutes);
	Period(int period_minutes);


	Period operator = (const Period p);	

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
	
	void Faceoff();
	// as a true canadian, yes I hear a whistle in my head when typing
	// this
	
	bool clockIsRunning();

	void stopClock();
	// generic one, regardless of what event triggered the clock to stop
	void startClock();
	String getClockOutput();

	~Period();
};




#endif
