// pwm.hpp /////////////////////////////////////////////////////////////////////
// pulse width modulation output object ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"


#ifndef PuLsEwIdThMoDuLaTiOn
#define PuLsEwIdThMoDuLaTiOn

#include "output.h"

class pwmDriver: protected outputDriver
{
	public:
	
	pwmDriver();
	pwmDriver(pin output_pin, percent init_percentage);
	
	protected:
	
	seconds sinceSwitch;
	
	percent outputPercentage;
	
	public:
	
	void setPercentage(percent new_percent);
	percent getPercentage();
	
	void Update(seconds deltat);
	
	~pwmDriver();
	
};

#endif
