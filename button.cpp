// button.cpp

#include "button.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <string.h>

Button::Button(MI0283QT9 lcd, int x, int y, char* text)
{
	//convert a char to string
	char textString[81];
	strcpy(textString, text);
	
	//calculate the width 
	int width = strlen(textString) * 24 + 20;
	
	lcd.fillRoundRect(x - 10,y - 10,width,40,10,RGB(0,128,255)); 
	
	//draw the text of the button
	lcd.drawText(x,y,textString, RGB(255,255,255),RGB(0,128,255),3);
	
}

Button::Button(MI0283QT9 lcd, int y, char* text)
{
	//convert a char to string
	char textString[81];
	strcpy(textString, text);
	
	//calculate the width
	int width = strlen(textString) * 24 + 20;
	
	int x = (320 - width) / 2;
	
	lcd.fillRoundRect(x ,y - 10,width,40,10,RGB(0,128,255));
	
	//draw the text of the button
	lcd.drawText(x + 10,y,textString, RGB(255,255,255),RGB(0,128,255),3);
	
}


