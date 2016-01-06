// button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#include <MI0283QT9.h>

class Button
{
	public:	
	
		/**
		 * Constructs a Button object
		 * 
		 * @param x Begin x coordinate
		 * @param y Begin y coordinate
		 * @param text The text which the button displays
		 * @note the width and height are applied automatically
		 */		
		Button(uint16_t x, uint8_t y, char* text);
		
		/**
		 * Constructs a Button and center it
		 * 
		 * @param y Begin y coordinate
		 * @param text The text which the button displays
		 * @note the width and height are applied automatically
		 */			
		Button(uint8_t y, char* text);
				
		/**
		 * Draw a button on the given lcd
		 * 
		 * @param lcd_p A pointer to a lcd to draw the button on
		 */	
		void drawButton(MI0283QT9 *lcd_p);		
		
		/**
		 * Remove a button on the given lcd
		 * 
		 * @param lcd_p A pointer to a a lcd to remove the button from
		 */	
		void removeButton(MI0283QT9 *lcd_p);
		
		/**
		 * Check of the given x and y are in range of the coordinates of the button
		 *
		 * @param x Begin x coordinate
		 * @param y Begin y coordinate
		 * @return a 0 or 1
		 */	
		uint8_t isPressed(uint16_t x, uint8_t y);	
						
		private:
			uint16_t x;
			uint16_t y;
			uint16_t width;
			uint8_t height;
			char text_string[15];		
};
#endif