// button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#include <MI0283QT9.h>

class Button
{
	public:
		/**
		 * Constructs a Button
		 * 
		 * @param lcd The LCD to render the button on
		 * @param x Begin x coordinate
		 * @param y Begin y coordinate
		 * @param text The text which the button displays
		 * @note the width and height are applied automatically
		 */		
		Button(MI0283QT9 lcd, uint16_t x, uint8_t y, char* text);
		
		/**
		 * Constructs a Button and centers it
		 * 
		 * @param lcd The LCD to render the button on
		 * @param y Begin y coordinate
		 * @param text The text which the button displays
		 * @note the width and height are applied automatically
		 */			
		Button(MI0283QT9 lcd, uint8_t y, char* text);
		
};


#endif

