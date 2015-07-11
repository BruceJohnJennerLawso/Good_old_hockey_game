// display.cpp /////////////////////////////////////////////////////////////////
// wrapper for messages printed to the lcd /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include "display.h"

#ifdef PRESEASON
	
#include <iostream>

#endif

Display::Display()
{
	for(int cy = 0; cy != 16; ++cy)
	{	lineOne[cy] = clear_character;
		lineTwo[cy] = clear_character;	
	}
}

Display::Display(String line_one, String line_two)
{
	for(int cy = 0; cy != 16; ++cy)
	{	lineOne[cy] = (line_one.c_str())[cy];
	}
	for(int cy = 0; cy != 16; ++cy)
	{	lineTwo[cy] = (line_two.c_str())[cy];	
	}
}


String Display::getLine(short line_number)
{
	String output = "                ";
	if(line_number == 1)
	{	
		for(int cy = 0; cy != 16; ++cy)
		{	output[cy] = lineOne[cy];
		}
		//output[0] = 'y';
	}
	else if(line_number == 2)
	{	for(int cy = 0; cy != 16; ++cy)
		{	output[cy] = lineTwo[cy];
		}
	}
	else
	{	print("line number inaccessible");
		String output = "error";
	}
	//print("getLine is returning");
	//print(output);
	return output;
}

void Display::clearLine(short line_number)
{	if((line_number == 2)||(line_number ==1))
	{ 
		for(int cy = 0; cy != 16; ++cy)
		{	if(line_number == 1)
			{	lineOne[cy] = clear_character;
			}	
			else if(line_number == 2)
			{	lineTwo[cy] = clear_character;
			}	
		}
	}
}

void Display::clearDisplay()
{	this->clearLine(1);
	this->clearLine(2);
}

void Display::printToLine(short line_number, short startPoint, String input)
{
	//#ifdef PRESEASON
	
	
	if(line_number == 1)
	{	
		for(int cy = 0; cy != 16; ++cy)
		{	if((cy >= startPoint)&&(cy < (startPoint+input.length()) ))
			{	lineOne[cy] = input[cy - startPoint];
			}
		}
	}
	else if(line_number == 2)
	{	for(int cy = 0; cy != 16; ++cy)
		{	if((cy >= startPoint)&&(cy < (startPoint+input.length()) ))
			{	lineTwo[cy] = input[cy - startPoint];
			}
		}
	}
	else
	{	print("error printing to line");
		print("line number inaccessible");
	}
	
	//#else

	
	//#endif

	
}

String getStringAtInt(int input)
{	
	String output;
	#ifdef PRESEASON
	
	output = std::to_string(input);
	
	#else
	
	output = "foo";
	
	#endif
	
	return output;
}


void Display::printToLine(short line_number, short startPoint, int input)
{	
	printToLine(line_number, startPoint, getStringAtInt(input));
	
	#ifdef PRESEASON
	
	
	#else

	
	#endif

	
}

#ifdef PRESEASON
	
void Display::printContents()
{
	for(int cy = 0; cy != 16; ++cy)
	{	std::cout << lineOne[cy] << ", ";
	}	std::cout << std::endl;
	for(int cy = 0; cy != 16; ++cy)
	{	std::cout << lineTwo[cy] << ", ";
	}	std::cout << std::endl;
}
	
#endif

Display::~Display()
{
}
