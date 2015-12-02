#include <avr/io.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <String.h>
#include "gamefield.h"
#include "car.h"

int main()
{
	init();
	MI0283QT9 lcd;
	
	lcd.begin();
	
	lcd.fillScreen(RGB(153,204,255));
	
	Gamefield veld;
	veld.DrawRoad(lcd, 0, 2);
	veld.DrawRoad(lcd, 1, 2);
	veld.DrawRoad(lcd, 2, 3);
	veld.DrawRoad(lcd, 3, 4);
	veld.DrawRoad(lcd, 4, 4);
	veld.DrawRoad(lcd, 5, 4);
	veld.SetTimer(lcd, 100);
	veld.SetHS(lcd, 1000);
	veld.DrawHS(lcd);
	veld.DrawMenu(lcd);
	Car testautotje = Car(lcd);

	while (1)
	{
		
	}
	
	return 0;
}