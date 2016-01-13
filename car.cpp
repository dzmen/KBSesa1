// car.cpp

#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include "Arduinonunchuk.h"
#include "car.h"

void Car::Init(MI0283QT9 *lcd, ArduinoNunchuk nunchuck)
{
	//Save lcd and nunchuk for further use later
	lcdscherm = lcd;
	nunchuk = nunchuck;
	
	//Starting position of the car
	x = 180;
	y = 165;
	
	//Draw frame
	lcdscherm->fillRect(x - 10, y, 20, 60, RGB(0,0,255));
	
	//Draw spoiler
	lcdscherm->fillRect(x - 20, y + 60, 40, 10, RGB(0,0,255));
	
	//Draw wheels
	lcdscherm->fillRect(x - 20, y + 10, 10, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 20, y + 40, 10, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 10, y + 10, 10, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 10, y + 40, 10, 15, RGB(0,0,0)); //right rear
}


void Car::Refresh()
{
	nunchuk.update();
	
	if (nunchuk.analogX < 30)
	{
		Left(10);
	}
	else if (nunchuk.analogX > 30 && nunchuk.analogX <= 50)
	{
		Left(8);
	}
	else if (nunchuk.analogX > 50 && nunchuk.analogX <= 70)
	{
		Left(6);
	}
	else if (nunchuk.analogX > 70 && nunchuk.analogX <= 90)
	{
		Left(4);
	}
	else if (nunchuk.analogX > 90 && nunchuk.analogX <= 100)
	{
		Left(2);
	}
	else if (nunchuk.analogX > 100 && nunchuk.analogX <= 150)
	{
		Straight();
	}
	
	else if (nunchuk.analogX > 150 && nunchuk.analogX <= 160)
	{
		Right(2);
	}
	else if (nunchuk.analogX > 160 && nunchuk.analogX <= 180)
	{
		Right(4);
	}
	else if (nunchuk.analogX > 180 && nunchuk.analogX <= 195)
	{
		Right(6);
	}
	else if (nunchuk.analogX > 195 && nunchuk.analogX <= 210)
	{
		Right(8);
	}
	else if (nunchuk.analogX > 210)
	{
		Right(10);
	}
	
}

uint16_t Car::GetPos()
{
	return x;
}

void Car::Straight()
{
	//Draw frame
	lcdscherm->fillRect(x - 10, y, 20, 60, RGB(0,0,255));
	
	//Draw spoiler
	lcdscherm->fillRect(x - 20, y + 60, 40, 10, RGB(0,0,255));
	
	//Draw wheels
	lcdscherm->fillRect(x - 20, y + 10, 10, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 20, y + 40, 10, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 10, y + 10, 10, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 10, y + 40, 10, 15, RGB(0,0,0)); //right rear
}


void Car::Left(uint8_t width)
{
	//If car has not reached left side of screen yet, decrease x
	if (x - width > 20)
	{
		x -= width;
	}
	
	//Frame
	lcdscherm->fillRect(x - 10, y, width, 60, RGB(0,0,255));
	
	//Spoiler
	lcdscherm->fillRect(x - 20, y + 60, width, 10, RGB(0,0,255));
	
	//Road
	lcdscherm->fillRect(x + 10, y, width, 60, RGB(160,160,160));
	
	//Wheels
	lcdscherm->fillRect(x - 20, y + 10, width, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 20, y + 40, width, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 10, y + 10, width, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 10, y + 40, width, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcdscherm->fillRect(x + 20, y + 10, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x + 20, y + 40, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x + 20, y + 60, width, 10, RGB(160,160,160));
}

void Car::Right(uint8_t width)
{
	//If car has not reached right side of screen yet, increase x
	if (x + width < 300)
	{
		x += width;
	}
	
	//Frame
	lcdscherm->fillRect(x + 10 - width, y, width, 60, RGB(0,0,255));
	
	//Spoiler
	lcdscherm->fillRect(x + 20 - width, y + 60, width, 10, RGB(0,0,255));
	
	//Road
	lcdscherm->fillRect(x - 10 - width, y, width, 60, RGB(160,160,160));
	
	//Wheels
	lcdscherm->fillRect(x - 10 - width, y + 10, width, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 10 - width, y + 40, width, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 20 - width, y + 10, width, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 20 - width, y + 40, width, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcdscherm->fillRect(x - 20 - width, y + 10, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x - 20 - width, y + 40, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x - 20 - width, y + 60, width, 10, RGB(160,160,160));
}
