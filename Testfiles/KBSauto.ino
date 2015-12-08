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
	
	uint16_t xL = 180;
	uint16_t xR = 180;
	
	Car testauto = Car(lcd);
	
	while (1)
	{
		nunchuk.update();
		
		if (xL > 20)
		{
			if (nunchuk.analogX < 110 && nunchuk.analogX >= 90)
			{
				xL -= 2;
				xR -= 2;
				testauto.Left(lcd, xL, 3);
			}
			if (nunchuk.analogX < 90 && nunchuk.analogX >= 70)
			{
				xL -= 4;
				xR -= 4;
				testauto.Left(lcd, xL, 5);
			}
			if (nunchuk.analogX < 70 && nunchuk.analogX >= 50)
			{
				xL -= 6;
				xR -= 6;
				testauto.Left(lcd, xL, 7);
			}
			if (nunchuk.analogX < 50 && nunchuk.analogX >= 30)
			{
				xL -= 8;
				xR -= 8;
				testauto.Left(lcd, xL, 9);
			}
			if (nunchuk.analogX < 30)
			{
				xL -= 10;
				xR -= 10;
				testauto.Left(lcd, xL, 11);
			}
		}
		
		if (xR < 300)
		{
			if (nunchuk.analogX > 140 && nunchuk.analogX <= 160)
			{
				testauto.Right(lcd, xR, 3);
				xL += 2;
				xR += 2;
			}
			if (nunchuk.analogX > 160 && nunchuk.analogX <= 180)
			{
				testauto.Right(lcd, xR, 5);
				xL += 4;
				xR += 4;
			}
			if (nunchuk.analogX > 180 && nunchuk.analogX <= 195)
			{
				testauto.Right(lcd, xR, 7);
				xL += 6;
				xR += 6;
			}
			if (nunchuk.analogX > 195 && nunchuk.analogX <= 210)
			{
				testauto.Right(lcd, xR, 9);
				xL += 8;
				xR += 8;
			}
			if (nunchuk.analogX > 210)
			{
				testauto.Right(lcd, xR, 11);
				xL += 10;
				xR += 10;
			}
		}
	}
	
	return 0;
}