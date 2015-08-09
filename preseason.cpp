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
#include "display.h"
// this can be removed safely I believe

#ifdef PRESEASON

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{	
	
	sf::Clock clock;
	double deltat = 0;
	
	Game goodOldHockey(1);
	
	Display lcdDisplay;
	
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
	
	sf::RenderWindow window(sf::VideoMode(300, 100), "Table Hockey Game - Preseason testing");
	
	while (window.isOpen())
	{	
		deltat = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{	
				window.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{	if(event.key.code == sf::Keyboard::Escape)
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
				if(event.key.code == sf::Keyboard::I)
				{	lcdDisplay.printContents();
				}			
			}
		}
		
		goodOldHockey.Update(deltat, lcdDisplay);
		
		//lcdDisplay.printToLine(1, 0, "HOME");
		//lcdDisplay.printToLine(1, 6, goodOldHockey.getClockOutput());		
		//lcdDisplay.printToLine(1, 12, "AWAY");
		
		//lcdDisplay.printToLine(2, 0, goodOldHockey.getHomeScore());
		//lcdDisplay.printToLine(2, 7, goodOldHockey.getCurrentPeriod());
		//lcdDisplay.printToLine(2, 14, goodOldHockey.getAwayScore());
		
		line1.setString(lcdDisplay.getLine(1));
		line2.setString(lcdDisplay.getLine(2));

		window.clear();
		window.draw(line1);
		window.draw(line2);		
		window.display();
	}
	print("calling destructor for this object");
	goodOldHockey.~Game();
	print("finished destructor for this object");
	
}

#endif
