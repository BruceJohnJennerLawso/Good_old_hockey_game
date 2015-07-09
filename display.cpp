// display.cpp /////////////////////////////////////////////////////////////////
// wrapper for messages printed to the lcd /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include "display.h"



Display::Display()
{
	for(int cy = 0; cy != 15; ++cy)
	{	lineOne[cy] = ' ';
		lineTwo[cy] = ' ';	
	}
}

Display::Display(String line_one, String line_two)
{
	for(int cy = 0; cy != 15; ++cy)
	{	lineOne[cy] = (line_one.c_str())[cy];
	}
	for(int cy = 0; cy != 15; ++cy)
	{	lineTwo[cy] = (line_two.c_str())[cy];	
	}
}

String Display::getLine(short line_number)
{
	String output;
	if(line_number == 1)
	{	output = lineOne;
	}
	else if(line_number == 2)
	{	output = lineTwo;
	}
	else
	{	print("line number inaccessible");
		String output = "error";
	}
	return output;
}

void Display::printToLine(short line_number, short startPoint, String input)
{
	#ifdef PRESEASON
	
	if(line_number == 1)
	{	
		for(int cy = 0; cy != 15; ++cy)
		{	if((cy >= startPoint)&&(cy <= (startPoint+input.length())))
			{	lineOne[cy] = input[cy - startPoint];
			}
		}
	}
	else if(line_number == 2)
	{	for(int cy = 0; cy != 15; ++cy)
		{	if((cy >= startPoint)&&(cy <= (startPoint+input.length())))
			{	lineTwo[cy] = input[cy - startPoint];
			}
		}
	}
	else
	{	print("error printing to line");
		print("line number inaccessible");
	}
	
	#else

	
	#endif

	
}




Display::~Display()
{
}
