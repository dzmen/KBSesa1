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
	//TOP SECRET CODE 
	lcd.tp_matrix.a = 79800;
	lcd.tp_matrix.b = 4294966596;
	lcd.tp_matrix.c = 4250933096;
	lcd.tp_matrix.d = 2700;
	lcd.tp_matrix.e = 57800;
	lcd.tp_matrix.f = 4291263596;
	lcd.tp_matrix.div = 109865;
	
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	
	spel.init(lcd);
	
	while (1)
	{
		spel.run();
	}
	
	return 0;
}