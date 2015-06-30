/*********************
hockeyTonight.pde

Testing out the time clock structures defined in game.hpp and
up. Not a full demo, as more components will need to be added
before the project is truly done
**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
#include <clock.h>
#include <game.h>


// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

void clearLcd();

void setup()
{
	// Debugging output
	Serial.begin(9600);
	// set up the LCD's number of columns and rows: 
	lcd.begin(16, 2);

	// Print a message to the LCD. We track how long it takes since
	// this library has been optimized a bit and we're proud of it :)
	int time = millis();
	lcd.setCursor(0,0);
	lcd.print("Table Hockey");
	lcd.setCursor(0,1);
	lcd.print("    Game");
	time = millis() - time;
	Serial.print("Initialized in  "); Serial.print(time); Serial.println(" ms");
	lcd.setBacklight(WHITE);
	delay(5000);
        clearLcd();
	// hold this open five secs, so we can see the startup message
	// before we get going
}

void clearLcd()
{	
	lcd.setCursor(0,0);
	lcd.print("                ");	
	lcd.setCursor(0,1);
	lcd.print("                ");
	// allows us to avoid the weird artifact issues where characters were being
	// left onscreen after new pieces of text were being redrawn
}

Game hockeyGame(5);
// standard five minute long periods

// I think its because the original clock that came with the game used
// 5 min long periods

float deltat = 0;
float timeElapsed = 0;

uint8_t i=0;
void loop()
{
	hockeyGame.Update(deltat);

        int homeScore = hockeyGame.getHomeScore();
        int awayScore = hockeyGame.getAwayScore();  
        int period = hockeyGame.getCurrentPeriod();      

	lcd.setCursor(0,0);
	lcd.print("HOME");

	lcd.setCursor(6,0);
	lcd.print(hockeyGame.getClockOutput());
	
	lcd.setCursor(12, 0);
	lcd.print("AWAY");
	
	lcd.setCursor(0,1);
	lcd.print(homeScore);

	lcd.setCursor(7,1);
	lcd.print(period);

	lcd.setCursor(14,1);
	lcd.print(awayScore);

	// set the cursor to column 0, line 1
	// (note: line 1 is the second row, since counting begins with 0):
	//lcd.setCursor(0, 1);
	// print the number of seconds since reset:
	//lcd.print(millis()/1000);

	uint8_t buttons = lcd.readButtons();

	if (buttons)
	{	
		lcd.clear();
		lcd.setCursor(0,0);
		if (buttons & BUTTON_UP)
		{	
			// lcd.print("UP ");
		}
		if (buttons & BUTTON_DOWN)
		{
			// lcd.print("DOWN ");
		}
		if (buttons & BUTTON_LEFT)
		{	hockeyGame.Goal(home);
			
			clearLcd();
			lcd.setCursor(0,0);
			lcd.print("Home Team Scores");
			delay(5000);
			clearLcd();
		}
		if (buttons & BUTTON_RIGHT)
		{	hockeyGame.Goal(away);
			
			clearLcd();
			lcd.setCursor(0,0);
			lcd.print("Away Team Scores");
			delay(5000);
			clearLcd();
		}
		if (buttons & BUTTON_SELECT)
		{	// we'll treat this as a clock toggle
			hockeyGame.toggleClock();
			//lcd.print("Toggle");
		}
	}
	deltat = ((millis()-timeElapsed)/1000);
	timeElapsed = millis();
}
