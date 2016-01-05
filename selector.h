// selector.h

#ifndef _SELECTOR_h
#define _SELECTOR_h

#include <MI0283QT9.h>
#include "button.h"

class Selector
{
	public:
		
		Selector(MI0283QT9 *lcd_p, uint16_t x_in, uint16_t y_in, uint8_t empty);
		
		~Selector();	
						
		void add();
		
		void subtract();
		
		void drawChar(MI0283QT9 *lcd_p);		
		
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

