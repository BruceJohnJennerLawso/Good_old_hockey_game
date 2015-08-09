// pwm.cpp /////////////////////////////////////////////////////////////////////
// pulse width modulation output object ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"

#include "pwm.h"


pwmDriver::pwmDriver(): outputDriver()
{	sinceSwitch = 0;
	outputPercentage = 0;
	
}


pwmDriver::pwmDriver(pin output_pin, percent init_percentage): outputDriver(output_pin, high)
{	sinceSwitch = 0;
	outputPercentage = init_percentage;
}


void pwmDriver::setPercentage(percent new_percent)
{	outputPercentage = new_percent;
}

percent pwmDriver::getPercentage()
{	return outputPercentage;
}

void pwmDriver::Update(seconds deltat)
{	// the actually interesting part here
}

pwmDriver::~pwmDriver()
{
}
	
