// car.cpp

#include "car.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>

Car::Car(MI0283QT9 lcd)
{
	//Draw frame
	lcd.fillRect(140, 140, 40, 70, RGB(0,0,255));
	
	//Draw bumper
	lcd.fillRect(138, 135, 44, 5, RGB(0,0,255));
	
	//Draw spoiler
	lcd.fillRect(130, 210, 60, 10, RGB(0,0,255));
	
	//Draw wheels
	lcd.fillRect(130, 145, 10, 15, RGB(0,0,0)); //left front
	lcd.fillRect(180, 145, 10, 15, RGB(0,0,0)); //right front
	lcd.fillRect(130, 185, 10, 15, RGB(0,0,0)); //left rear
	lcd.fillRect(180, 185, 10, 15, RGB(0,0,0)); //right rear
	
	//Draw cockpit
	lcd.fillRect(140, 170, 40, 30, RGB(0, 128, 255));
}


