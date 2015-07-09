// display.h ///////////////////////////////////////////////////////////////////
// wrapper for messages printed to the lcd /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"

#include "environment.h"

#ifndef DiSpLaY
#define DiSpLaY

#define display_width 16
// make this generic in case its on a different lcd screen or something
//#define display_rows 2
// maybe some more preprocessor stuff, this is too complicated for now

class Display
{
	public:
	Display();
	Display(String line_one, String line_two);	
	
	protected:
	
	//String lineOne;
	//String lineTwo;
	
	char lineOne[display_width];
	char lineTwo[display_width];	
	
	// we'll just trim anything above 16 chars off when we print
	// if you wrote to past 16, it aint my problem
	
	public:
	
	String getLine(short line_number);
	
	void printToLine(short line_number, short startPoint, String input);
	
	~Display();
};


#endif
