#include "Obstacles.h"

#include <Arduino.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

void Obstacles::Init(MI0283QT9 * lcd)
{
	lcdscherm = lcd;
	y = 20;
	x = 180;
}

void Obstacles::ObstacleSlow(){
	lcdscherm->fillTriangle(x-50,y+10,x-30,y+10,x-40,y+20,RGB(255,196,0));
	lcdscherm->fillRect(x-43,y,6,10,RGB(255,196,0));
}

void Obstacles::ObstacleFast(){
	lcdscherm->fillTriangle(x-50,y+10,x-30,y+10,x-40,y,RGB(255,196,0));
	lcdscherm->fillRect(x-43,y+10,6,10,RGB(255,196,0));
}

void Obstacles::ObstacleSteering(){
	lcdscherm->fillTriangle(x-40,y,x-47,y+5,x-40,y+10,RGB(255,196,0));
	lcdscherm->fillRect(x-40,y+4,7,2,RGB(255,196,0));
	lcdscherm->fillTriangle(x-33,y,x-26,y+5,x-33,y+10,RGB(255,196,0));
}

void Obstacles::ObstacleBlock(){
	lcdscherm->fillRect(x-40,y,20,20,RGB(0,0,0));
}