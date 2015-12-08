// button.cpp

#include "button.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <string.h>

Button::Button(uint16_t x, uint8_t y, char* text)
{
	this->y = y;
	this->x = x;
	this->height = 40;
	
	//convert a char to string
	strcpy(this->text_string, text);	
	
	//calculate the width
	this->width = strlen(this->text_string) * 24 + 20;
		
}

Button::Button(uint8_t y, char* text)
{
	this->y = y;
	this->height = 40;
	
	//convert a char to string
	strcpy(this->text_string, text);	
	
	//calculate the width
	this->width = strlen(this->text_string) * 24 + 20;	
	
	//calculate the x coordinate so its in the center
	this->x = (320 - this->width) / 2;
		
}

void Button::drawButton(MI0283QT9 lcd)
{
	//draw the background of the button
	lcd.fillRoundRect(this->x , this->y - 10, this->width, this->height, 10, RGB(0,128,255));
	
	//draw the text of the button
	lcd.drawText(this->x + 10, this->y, this->text_string, RGB(255,255,255), RGB(0,128,255),3);
}

void Button::removeButton(MI0283QT9 lcd)
{
	//draw the background of the button
	lcd.fillRoundRect(this->x , this->y - 10, this->width, this->height, 10, RGB(153,204,255));
	
}

uint8_t Button::isPressed(uint16_t x, uint8_t y)
{
	uint16_t xend = this->x + this->width;
	uint8_t yend = this->y - 10 + this->height;
	
	//check if the x and y vars are between the x and y range of the button	
	if ((y >= this->y - 10 && y <= yend) && (x >= this->x && x <= xend))
	{
		return 1;		
	} 
	else
	{
		return 0;
	}	
}


