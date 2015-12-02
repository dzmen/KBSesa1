#include <avr/io.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <String.h>
#include "button.h"

int main()
{
	init();
	
	MI0283QT9 lcd;
	
	lcd.begin();
	
	lcd.fillScreen(RGB(153,204,255));
	
	Button start = Button(lcd,40, "Start");
	Button highscores = Button(lcd,100, "Highscores");
	Button help = Button(lcd,160, "Help");
	
	while (1)
	{
		
	}
	
	return 0;
}
