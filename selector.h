#ifndef _SELECTOR_h
#define _SELECTOR_h

#include <MI0283QT9.h>
#include "button.h"

class Selector
{
	public:
	
	/**
	* Constructs a Selector object
	*
	* @param lcd_p A pointer to a lcd to draw the selector on
	* @param x Begin x coordinate
	* @param y Begin y coordinate
	* @param empty Choose (0 or 1) if the selector can show an empty char or not
	*/
	Selector(MI0283QT9 *lcd_p, uint16_t x_in, uint16_t y_in, uint8_t empty);
	
	/**
	* Destructs a Selector object
	*/
	~Selector();
	
	/**
	* Set the alfhabet var to the next char within a-z
	*/
	void add();
	
	/**
	* Set the alfhabet var to the previous char within a-z
	*/
	void subtract();
	
	/**
	* Draw the alfhabet var in the lcd
	*
	* @param lcd_p A pointer to a lcd to draw the char on
	*/
	void drawChar(MI0283QT9 *lcd_p);
	
	/**
	* Return the current displayed char
	*
	* @return alfhabet var
	*/
	char getChar();
	
	Button *up_p;
	
	Button *down_p;
	
	private:
	char alfhabet;
	uint16_t x;
	uint16_t y;
	uint8_t empty;
};
#endif

