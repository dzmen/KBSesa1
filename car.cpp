// car.cpp

#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include "ArduinoNunchuk.h"
#include "car.h"

Car::Car(MI0283QT9 lcd)
{
	xL = 180;
	xR = 180;
	
	//Draw frame
	lcd.fillRect(170, 165, 20, 60, RGB(0,0,255));
	
	//Draw spoiler
	lcd.fillRect(160, 225, 40, 10, RGB(0,0,255));
	
	//Draw wheels
	lcd.fillRect(160, 175, 10, 15, RGB(0,0,0)); //left front
	lcd.fillRect(190, 175, 10, 15, RGB(0,0,0)); //right front
	lcd.fillRect(160, 205, 10, 15, RGB(0,0,0)); //left rear
	lcd.fillRect(190, 205, 10, 15, RGB(0,0,0)); //right rear
}

void Car::Refresh(MI0283QT9 lcd, ArduinoNunchuk nunchuk, Car testauto)
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


void Car::Left(MI0283QT9 lcd, uint16_t xL, uint8_t widthL)
{
	//Frame
	lcd.fillRect(xL - 10, 165, widthL, 60, RGB(0,0,255));
	
	//Spoiler
	lcd.fillRect(xL - 20, 225, widthL, 10, RGB(0,0,255));
	
	//Road
	lcd.fillRect(xL + 10, 165, widthL, 60, RGB(160,160,160));
	
	//Wheels
	lcd.fillRect(xL - 20, 175, widthL, 15, RGB(0,0,0)); //left front
	lcd.fillRect(xL + 10, 175, widthL, 15, RGB(0,0,0)); //right front
	lcd.fillRect(xL - 20, 205, widthL, 15, RGB(0,0,0)); //left rear
	lcd.fillRect(xL + 10, 205, widthL, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcd.fillRect(xL + 20, 175, widthL, 15, RGB(160,160,160));
	lcd.fillRect(xL + 20, 205, widthL, 15, RGB(160,160,160));
	lcd.fillRect(xL + 20, 225, widthL, 10, RGB(160,160,160));
}

void Car::Right(MI0283QT9 lcd, uint16_t xR, uint8_t widthR)
{
	//Frame
    lcd.fillRect(xR + 10, 165, widthR, 60, RGB(0,0,255));
	
	//Spoiler
	lcd.fillRect(xR + 20, 225, widthR, 10, RGB(0,0,255));
	
	//Road	
	lcd.fillRect(xR - 10, 165, widthR, 60, RGB(160,160,160));
		
	//Wheels	
	lcd.fillRect(xR + 20, 175, widthR, 15, RGB(0,0,0)); //left front
	lcd.fillRect(xR - 10, 175, widthR, 15, RGB(0,0,0)); //right front
	lcd.fillRect(xR + 20, 205, widthR, 15, RGB(0,0,0)); //left rear
	lcd.fillRect(xR - 10, 205, widthR, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcd.fillRect(xR - 20, 175, widthR, 15, RGB(160,160,160));
	lcd.fillRect(xR - 20, 205, widthR, 15, RGB(160,160,160));
	lcd.fillRect(xR - 20, 225, widthR, 10, RGB(160,160,160));


}