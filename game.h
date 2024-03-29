#ifndef _GAME_h
#define _GAME_h

#include <MI0283QT9.h>
#include "ArduinoNunchuk.h"
#include "gamefield.h"
#include "highscore.h"

class Game
{
	public:
	
	/**
	* Constructs a Game object
	*
	* @param lcd_p A pointer to a lcd to render the game elements on
	*/
	void init(MI0283QT9 lcd_p);
	
	/**
	* Runs the game object
	*
	*/
	void run();
	
	/**
	* Update the touch_x and touch_y variables with functions from the MI0283QT9 library
	*
	*/
	void updateTouch();
	
	/**
	* Update the touch_x and touch_y variables with 1000 so they can't be the same as a coordinate on the lcd display
	*
	*/
	void removeLastTouch();
	
	private:
	MI0283QT9 *lcd;
	uint8_t main_screen;
	uint8_t start_game;
	uint8_t highcore_screen;
	uint8_t settings_screen;
	uint8_t help_screen;
	
	uint16_t touch_x;
	uint16_t touch_y;
	uint8_t screen_brightness;
	
	Gamefield field;
	ArduinoNunchuk nunchuk;
	Highscore game_highscores;
	
	uint16_t pauseteller = 0;
	uint32_t pauseseconds = 0;
	
	uint32_t quittime = 0;
};

#endif