#include <avr/io.h>
#include <Wire.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include "ArduinoNunchuk.h"
#include "car.h"

int main()
{
	init();
	
	ArduinoNunchuk nunchuk = ArduinoNunchuk();
	nunchuk.init();
	
	MI0283QT9 lcd;
	lcd.begin();
	
	lcd.fillScreen(RGB(160,160,160));
	
	Car testauto = Car(lcd);
	
	while (1)
	{
		testauto.Refresh(lcd, nunchuk, testauto);
	}
	
	return 0;
}