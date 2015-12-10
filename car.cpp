// car.cpp

#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include "ArduinoNunchuk.h"
#include "car.h"

Car::Car(MI0283QT9 lcd)
{
	lcdscherm = &lcd;
	
	//Starting position of the car
	x = 180;
	
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

void Car::Refresh(ArduinoNunchuk nunchuk)
{
	nunchuk.update();
	
	if (x > 20)
	{
		if (nunchuk.analogX < 110 && nunchuk.analogX >= 90)
		{
			Left(2);
		}
		if (nunchuk.analogX < 90 && nunchuk.analogX >= 70)
		{
			Left(4);
		}
		if (nunchuk.analogX < 70 && nunchuk.analogX >= 50)
		{
			Left(6);
		}
		if (nunchuk.analogX < 50 && nunchuk.analogX >= 30)
		{
			Left(8);
		}
		if (nunchuk.analogX < 30)
		{
			Left(10);
		}
	}
	
	if (x < 300)
	{
		if (nunchuk.analogX > 140 && nunchuk.analogX <= 160)
		{
			Right(2);
		}
		if (nunchuk.analogX > 160 && nunchuk.analogX <= 180)
		{
			Right(4);
		}
		if (nunchuk.analogX > 180 && nunchuk.analogX <= 195)
		{
			Right(6);
		}
		if (nunchuk.analogX > 195 && nunchuk.analogX <= 210)
		{
			Right(8);
		}
		if (nunchuk.analogX > 210)
		{
			Right(10);
		}
	}
}


void Car::Left(uint8_t width)
{
	x -= width;
	
	//Frame
	lcdscherm->fillRect(x - 10, 165, width + 1, 60, RGB(0,0,255));
	
	//Spoiler
	lcdscherm->fillRect(x - 20, 225, width + 1, 10, RGB(0,0,255));
	
	//Road
	lcdscherm->fillRect(x + 10, 165, width + 1, 60, RGB(160,160,160));
	
	//Wheels
	lcdscherm->fillRect(x - 20, 175, width + 1, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x + 10, 175, width + 1, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x - 20, 205, width + 1, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 10, 205, width + 1, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcdscherm->fillRect(x + 20, 175, width + 1, 15, RGB(160,160,160));
	lcdscherm->fillRect(x + 20, 205, width + 1, 15, RGB(160,160,160));
	lcdscherm->fillRect(x + 20, 225, width + 1, 10, RGB(160,160,160));
}

void Car::Right(uint8_t width)
{
	x += width;
	
	//Frame
    lcdscherm->fillRect(x + 10, 165, width + 1, 60, RGB(0,0,255));
	
	//Spoiler
	lcdscherm->fillRect(x + 20, 225, width + 1, 10, RGB(0,0,255));
	
	//Road	
	lcdscherm->fillRect(x - 10, 165, width + 1, 60, RGB(160,160,160));
		
	//Wheels	
	lcdscherm->fillRect(x + 20, 175, width + 1, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 10, 175, width + 1, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 20, 205, width + 1, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x - 10, 205, width + 1, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcdscherm->fillRect(x - 20, 175, width + 1, 15, RGB(160,160,160));
	lcdscherm->fillRect(x - 20, 205, width + 1, 15, RGB(160,160,160));
	lcdscherm->fillRect(x - 20, 225, width + 1, 10, RGB(160,160,160));
	
	
}