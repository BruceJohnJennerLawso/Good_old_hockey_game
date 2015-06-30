// preseason.cpp ///////////////////////////////////////////////////////////////
// lets test the code before it ever hits the arduino side by //////////////////
// running it in a simple C++ program //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"

//#include "Source.c"

//#include "Headers.hpp"
//#include "Source.cpp"
#include "game.h"

#ifdef PRESEASON

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{	
	Game goodOldHockey(5);
	
	sf::Font scorefont;
	if(!scorefont.loadFromFile("./scoreboard.ttf"))
	{	print("Unable to load font, aborting");
		return -1;
	}
	
	sf::Text line1;
	sf::Text line2;
	
	line1.setFont(scorefont);
	line2.setFont(scorefont);
	
	line1.setColor(sf::Color::Cyan);
	line2.setColor(sf::Color::Cyan);		
	
	line1.setPosition(0, 20);
	line2.setPosition(0, 40);	
	
	sf::RenderWindow window(sf::VideoMode(600, 599), "Table Hockey Game - Preseason testing");
	
	while (window.isOpen())
	{	
		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{	
				window.close();
			}
			if(event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			if(event.key.code == sf::Keyboard::Space)
			{	goodOldHockey.toggleClock();
			}
			if(event.key.code == sf::Keyboard::D)
			{	goodOldHockey.Goal(away);
			}
			if(event.key.code == sf::Keyboard::A)
			{	goodOldHockey.Goal(home);
			}
			if(event.key.code == sf::Keyboard::A)
			{	goodOldHockey.Goal(home);
			}			
		}
		std::string outputl1;
		outputl1.append("HOME  ");
		outputl1.append(goodOldHockey.getClockOutput());
		outputl1.append("  AWAY");

		

		line1.setString(outputl1);
		
		
		std::string outputl2;
		outputl2.append(std::to_string(goodOldHockey.getHomeScore()));
		outputl2.append("      ");
		outputl2.append(std::to_string(goodOldHockey.getCurrentPeriod()));
		outputl2.append("      ");
		outputl2.append(std::to_string(goodOldHockey.getAwayScore()));		

		line1.setString(outputl2);		

		window.clear();
		window.draw(line1);
		window.draw(line2);		
		window.display();
	}
	
	goodOldHockey.startClock();
	while(!goodOldHockey.gameFinished())
	{	if(!goodOldHockey.clockIsRunning())
		{	goodOldHockey.startClock();
		}
		goodOldHockey.Update(0.9);
		if(goodOldHockey.getCurrentPeriod() == 4)
		{	
			goodOldHockey.Update(10.1);
			goodOldHockey.Goal(home);
			// the home team wins...
		}
	}	
	goodOldHockey.printClockOutput();
	return 0;
}

#endif
