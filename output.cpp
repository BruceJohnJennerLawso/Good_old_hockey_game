// output.cpp //////////////////////////////////////////////////////////////////
// hardware outputs, ie the arduino pins ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"

#include "output.h"


	
	
outputDriver::outputDriver()
{	State = low;
	pinNumber = 0;
	// error code, cant find a pin
}

outputDriver::outputDriver(pin output_pin, pinstate init_state)
{	State = init_state;
	pinNumber = output_pin;
}
	
	
void outputDriver::setPinNumber(pin new_pin)
{	pinNumber = new_pin;
}

pin outputDriver::getPinNumber()
{	return pinNumber;
}

void outputDriver::setPinState(pinstate new_state)
{	State = new_state;
}

pinstate outputDriver::getPinState()
{	return State;
}

void outputDriver::Update(seconds deltat)
{	
	//...
}
	
outputDriver::~outputDriver()
{
}

