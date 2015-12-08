// car.cpp

#include "car.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>

Car::Car(MI0283QT9 lcd)
{
	//Draw frame
	lcd.fillRect(170, 150, 20, 60, RGB(0,0,255));
	
	//Draw spoiler
	lcd.fillRect(160, 210, 40, 10, RGB(0,0,255));
	
	//Draw wheels
	lcd.fillRect(160, 160, 10, 15, RGB(0,0,0)); //left front
	lcd.fillRect(190, 160, 10, 15, RGB(0,0,0)); //right front
	lcd.fillRect(160, 190, 10, 15, RGB(0,0,0)); //left rear
	lcd.fillRect(190, 190, 10, 15, RGB(0,0,0)); //right rear
}

void Car::Left(MI0283QT9 lcd, uint16_t xL, uint8_t widthL)
{
	//Frame
	lcd.fillRect(xL - 10, 150, widthL, 60, RGB(0,0,255));
	
	//Spoiler
	lcd.fillRect(xL - 20, 210, widthL, 10, RGB(0,0,255));
	
	//Road
	lcd.fillRect(xL + 10, 150, widthL, 60, RGB(160,160,160));
	
	//Wheels
	lcd.fillRect(xL - 20, 160, widthL, 15, RGB(0,0,0)); //left front
	lcd.fillRect(xL + 10, 160, widthL, 15, RGB(0,0,0)); //right front
	lcd.fillRect(xL - 20, 190, widthL, 15, RGB(0,0,0)); //left rear
	lcd.fillRect(xL + 10, 190, widthL, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcd.fillRect(xL + 20, 160, widthL, 15, RGB(160,160,160));
	lcd.fillRect(xL + 20, 190, widthL, 15, RGB(160,160,160));
	lcd.fillRect(xL + 20, 210, widthL, 10, RGB(160,160,160));
}

void Car::Right(MI0283QT9 lcd, uint16_t xR, uint8_t widthR)
{
	//Frame
    lcd.fillRect(xR + 10, 150, widthR, 60, RGB(0,0,255));
	
	//Spoiler
	lcd.fillRect(xR + 20, 210, widthR, 10, RGB(0,0,255));
	
	//Road	
	lcd.fillRect(xR - 10, 150, widthR, 60, RGB(160,160,160));
		
	//Wheels	
	lcd.fillRect(xR + 20, 160, widthR, 15, RGB(0,0,0)); //left front
	lcd.fillRect(xR - 10, 160, widthR, 15, RGB(0,0,0)); //right front
	lcd.fillRect(xR + 20, 190, widthR, 15, RGB(0,0,0)); //left rear
	lcd.fillRect(xR - 10, 190, widthR, 15, RGB(0,0,0)); //right rear
	
	//Road
	lcd.fillRect(xR - 20, 160, widthR, 15, RGB(160,160,160));
	lcd.fillRect(xR - 20, 190, widthR, 15, RGB(160,160,160));
	lcd.fillRect(xR - 20, 210, widthR, 10, RGB(160,160,160));


}