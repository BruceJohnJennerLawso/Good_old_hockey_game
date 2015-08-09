// output.hpp //////////////////////////////////////////////////////////////////
// hardware outputs, ie the arduino pins ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"

#ifndef HaRdWaReOuT
#define HaRdWaReOuT

#include "environment.h"

class outputDriver
{
	public:
	outputDriver();
	outputDriver(pin output_pin, pinstate init_state);
	
	protected:
	pinstate State;
	pin pinNumber;
	
	public:
	
	void setPinNumber(pin new_pin);
	pin getPinNumber();
	
	void setPinState(pinstate new_state);
	pinstate getPinState();
	
	virtual void Update(seconds deltat);
	
	~outputDriver();
};


#endif
