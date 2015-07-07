// environment.h ///////////////////////////////////////////////////////////////
// types and preprocessor definitions shared across multiple files /////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"


#ifndef EnViRoNmEnT
#define EnViRoNmEnT


#define PRESEASON


#ifdef PRESEASON

	#include <string>
	typedef std::string String;
	// otherwise, we sneakily get away with it just being the String
	// type declared in the Arduino source
	
#else
	#include "Arduino.h"
#endif

#endif
