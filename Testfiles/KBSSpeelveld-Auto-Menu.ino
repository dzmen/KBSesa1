#include <avr/io.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <String.h>
#include <Wire.h>
#include "game.h"

Game spel;

int main()
{
	init();
	MI0283QT9 lcd;
	lcd.begin();
	lcd.touchStartCal();
	//TOP SECRET CODE
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	
	spel.init(lcd);

	while (1)
	{
		spel.run();
	}
	
	return 0;
}