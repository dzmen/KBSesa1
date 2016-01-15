#include "selector.h"
#include "button.h"

#define WHITE RGB(255,255,255)
#define LIGHT_BLUE RGB(153,204,255)

Selector::Selector(MI0283QT9 *lcd_p, uint16_t x_in, uint16_t y_in, uint8_t empty_in)
{
	x = x_in;
	y = y_in;
	empty = empty_in;
	
	if (empty)
	{
		alfhabet = ' ';
	}
	else
	{
		alfhabet = 'a';
	}
	
	up_p = new Button(x,y,"+");
	up_p->drawButton(lcd_p);
	
	drawChar(lcd_p);
	
	down_p = new Button(x, y + 65,"-");
	down_p->drawButton(lcd_p);
}

Selector::~Selector()
{
	delete up_p;
	delete down_p;
}

void Selector::add()
{
	//if char is empty or 'z'
	if (alfhabet == ' ' || alfhabet == 0x7A)
	{
		//if char is empty and 'z'
		if(empty && alfhabet == 0x7A)
		{
			alfhabet = ' ';
		}
		else
		{
			alfhabet = 0x61;
		}
	}
	else
	{
		alfhabet++;
	}
}

void Selector::subtract()
{
	//if char is empty or 'a'
	if (alfhabet == ' ' || alfhabet == 0x61)
	{
		//if char is empty and 'a'
		if(empty && alfhabet == 0x61)
		{
			alfhabet = ' ';
		}
		else
		{
			alfhabet = 0x7A;
		}
	}
	else
	{
		alfhabet--;
	}
}

void Selector::drawChar(MI0283QT9 *lcd_p)
{
	lcd_p->drawChar(x + 10,y + 30,alfhabet, WHITE,LIGHT_BLUE,3);
}

char Selector::getChar()
{
	return alfhabet;
}
