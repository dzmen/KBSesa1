// button.cpp

#include "button.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <string.h>

Button::Button(MI0283QT9 lcd, uint16_t x, uint8_t y, char* text)
{
	//convert a char to string
	char textString[81];
	strcpy(textString, text);
	
	//calculate the width 
	uint16_t width = strlen(textString) * 24 + 20;
	
	//draw the background of the button
	lcd.fillRoundRect(x - 10,y - 10,width,40,10,RGB(0,128,255)); 
	
	//draw the text of the button
	lcd.drawText(x,y,textString, RGB(255,255,255),RGB(0,128,255),3);
	
}

Button::Button(MI0283QT9 lcd, uint8_t y, char* text)
{
	//convert a char to string
	char textString[81];
	strcpy(textString, text);
	
	//calculate the width
	uint16_t width = strlen(textString) * 24 + 20;
	
	//calculate the x coordinate so its in the center
	uint8_t x = (320 - width) / 2;
	
	//draw the background of the button
	lcd.fillRoundRect(x ,y - 10,width,40,10,RGB(0,128,255));
	
	//draw the text of the button
	lcd.drawText(x + 10,y,textString, RGB(255,255,255),RGB(0,128,255),3);
	
}


