// button.cpp

#include "button.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <string.h>

Button::Button(uint16_t x, uint8_t y, char* text)
{
	y = y;
	x = x;
	height = 40;
	
	//convert a char to string
	strcpy(text_string, text);	
	
	//calculate the width
	width = strlen(text_string) * 24 + 20;		
}

Button::Button(uint8_t y, char* text)
{
	y = y;
	height = 40;
	
	//convert a char to string
	strcpy(text_string, text);	
	
	//calculate the width
	width = strlen(text_string) * 24 + 20;	
	
	//calculate the x coordinate so its in the center
	x = (320 - width) / 2;		
}

void Button::drawButton(MI0283QT9 *lcd_p)
{
	//draw the background of the button
	lcd_p->fillRoundRect(x , y - 10, width, height, 10, RGB(0,128,255));
	
	//draw the text of the button
	lcd_p->drawText(x + 10, y, text_string, RGB(255,255,255), RGB(0,128,255),3);
}

void Button::removeButton(MI0283QT9 *lcd_p)
{
	//draw the background of the button
	lcd_p->fillRoundRect(x , y - 10, width, height, 10, RGB(153,204,255));	
}

uint8_t Button::isPressed(uint16_t x, uint8_t y)
{
	uint16_t xend = x + width;
	uint8_t yend = y - 10 + height;
	
	//check if the x and y vars are between the x and y range of the button	
	if ((y >= y - 10 && y <= yend) && (x >= x && x <= xend))
	{
		return 1;		
	} 
	else
	{
		return 0;
	}	
}