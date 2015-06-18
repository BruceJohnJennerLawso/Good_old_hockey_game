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

class gameClock
{
	gameClock(int init_time, int period_minutes);
	
	float Time;

	void Update();
	// ahh, more params

	~gameClock();


};



#endif
