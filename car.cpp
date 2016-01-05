// car.cpp

#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include "ArduinoNunchuk.h"
#include "car.h"

void Car::Init(MI0283QT9 *lcd)
{
	lcdscherm = lcd;
	
	//Starting position of the car
	x = 180;
	
	//Draw frame
	lcdscherm->fillRect(x - 10, 165, 20, 60, RGB(0,0,255));
	
	//Draw spoiler
	lcdscherm->fillRect(x - 20, 225, 40, 10, RGB(0,0,255));
	
	//Draw wheels
	lcdscherm->fillRect(x - 20, 175, 10, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 20, 205, 10, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 10, 175, 10, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 10, 205, 10, 15, RGB(0,0,0)); //right rear
}


void Car::ObstacleSlow(){
	y = 20;
	lcdscherm->fillTriangle(x-50,y+10,x-30,y+10,x-40,y+20,RGB(255,196,0));
	lcdscherm->fillRect(x-43,y,6,10,RGB(255,196,0));
}

void Car::ObstacleFast(){
	lcdscherm->fillTriangle(x-50,y+10,x-30,y+10,x-40,y,RGB(255,196,0));
	lcdscherm->fillRect(x-43,y+10,6,10,RGB(255,196,0));
}

void Car::ObstacleSteering(){
	lcdscherm->fillTriangle(x-40,y,x-47,y+5,x-40,y+10,RGB(255,196,0));
	lcdscherm->fillRect(x-40,y+4,7,2,RGB(255,196,0));
	lcdscherm->fillTriangle(x-33,y,x-26,y+5,x-33,y+10,RGB(255,196,0));
}

void Car::ObstacleBlock(){
	lcdscherm->fillRect(x-40,y,20,20,RGB(0,0,0));
}


void Car::Refresh(ArduinoNunchuk nunchuk)
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
	lcdscherm->fillRect(x - 10, 165, 20, 60, RGB(0,0,255));
	
	//Draw spoiler
	lcdscherm->fillRect(x - 20, 225, 40, 10, RGB(0,0,255));
	
	//Draw wheels
	lcdscherm->fillRect(x - 20, 175, 10, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 20, 205, 10, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 10, 175, 10, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 10, 205, 10, 15, RGB(0,0,0)); //right rear
}


void Car::Left(uint8_t width)
{
	if (x - width > 20)
	{
		x -= width;
	}
	
	//Frame
	lcdscherm->fillRect(x - 10, 165, width, 60, RGB(0,0,255));
	
	//Spoiler
	lcdscherm->fillRect(x - 20, 225, width, 10, RGB(0,0,255));
	
	//Road
	lcdscherm->fillRect(x + 10, 165, width, 60, RGB(160,160,160));
	
	//Wheels
	lcdscherm->fillRect(x - 20, 175, width, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 20, 205, width, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 10, 175, width, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 10, 205, width, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcdscherm->fillRect(x + 20, 175, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x + 20, 205, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x + 20, 225, width, 10, RGB(160,160,160));
}

void Car::Right(uint8_t width)
{
	if (x + width < 300)
	{
		x += width;
	}
	
	//Frame
	lcdscherm->fillRect(x + 10 - width, 165, width, 60, RGB(0,0,255));
	
	//Spoiler
	lcdscherm->fillRect(x + 20 - width, 225, width, 10, RGB(0,0,255));
	
	//Road
	lcdscherm->fillRect(x - 10 - width, 165, width, 60, RGB(160,160,160));
	
	//Wheels
	lcdscherm->fillRect(x - 10 - width, 175, width, 15, RGB(0,0,0)); //left front
	lcdscherm->fillRect(x - 10 - width, 205, width, 15, RGB(0,0,0)); //left rear
	lcdscherm->fillRect(x + 20 - width, 175, width, 15, RGB(0,0,0)); //right front
	lcdscherm->fillRect(x + 20 - width, 205, width, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcdscherm->fillRect(x - 20 - width, 175, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x - 20 - width, 205, width, 15, RGB(160,160,160));
	lcdscherm->fillRect(x - 20 - width, 225, width, 10, RGB(160,160,160));
}
