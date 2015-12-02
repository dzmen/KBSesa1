#include <avr/io.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <String.h>
#include "car.h"

int main()
{
	init();
	
	MI0283QT9 lcd;
	
	lcd.begin();
	
	lcd.fillScreen(RGB(160,160,160));
	
	Car test = Car(lcd);
	
	while (1)
	{
		
	}
	
	return 0;
}