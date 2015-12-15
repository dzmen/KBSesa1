// game.h

#ifndef _GAME_h
#define _GAME_h

#include <MI0283QT9.h>
#include "ArduinoNunchuk.h"
#include "gamefield.h"
#include "car.h"

class Game
{
	public:
		
		/**
		 * Constructs a Game object
		 * 
		 * @param lcd_p A pointer to a lcd to render the game elements on
		 */	
		void Init(MI0283QT9 lcd_p);	
		
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
		uint8_t help_screen;
		
		uint16_t touch_x;
		uint16_t touch_y;
		
		Gamefield veld;
		Car autotje;
		ArduinoNunchuk nunchuk;
};

#endif