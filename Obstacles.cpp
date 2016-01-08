#include "Obstacles.h"

#include <Arduino.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

#define YELLOW RGB(255,196,0)

void Obstacles::Init(MI0283QT9 * lcd)
{
	lcdscherm = lcd;
	ypos = 1;
}

void Obstacles::Createobject(uint8_t pos)
{
	xpos = random(10, 110);
	objecttype = random(0,3);
	switch (objecttype)
	{
		case 0:
			ObstacleSteering(pos);
			break;
		case 1:
			ObstacleBlock(pos);
			break;
		case 2:
			ObstacleSlow(pos);
			break;
		case 3:
			ObstacleFast(pos);
			break;
	}
}

void Obstacles::Next(uint8_t pos)
{
	ypos++;
	switch (objecttype)
	{
		case 0:
			ObstacleSteering(pos);
			break;
		case 1:
			ObstacleBlock(pos);
			break;
		case 2:
			ObstacleSlow(pos);
			break;
		case 3:
			ObstacleFast(pos);
			break;
	}
}

void Obstacles::ObstacleSlow(uint8_t pos)
{
	uint16_t xobject = pos * 10 + 20 + xpos;
	uint16_t yobject = ypos * 40 + 20;
	lcdscherm->fillTriangle(xobject-50,yobject+10,xobject-30,yobject+10,xobject-40,yobject+20,YELLOW);
	lcdscherm->fillRect(xobject-43,yobject,6,10,YELLOW);
}

void Obstacles::ObstacleFast(uint8_t pos)
{
	uint16_t xobject = pos * 10 + 20 + xpos;
	uint16_t yobject = ypos * 40 + 20;
	lcdscherm->fillTriangle(xobject-50,yobject+10,xobject-30,yobject+10,xobject-40,yobject,YELLOW);
	lcdscherm->fillRect(xobject-43,yobject+10,6,10,YELLOW);
}

void Obstacles::ObstacleSteering(uint8_t pos)
{
	uint16_t xobject = pos * 10 + 20 + xpos;
	uint16_t yobject = ypos * 40 + 20;
	lcdscherm->fillTriangle(xobject-40,yobject,xobject-47,yobject+5,xobject-40,yobject+10,YELLOW);
	lcdscherm->fillRect(xobject-40,yobject+4,7,2,YELLOW);
	lcdscherm->fillTriangle(xobject-33,yobject,xobject-26,yobject+5,xobject-33,yobject+10,YELLOW);
}

void Obstacles::ObstacleBlock(uint8_t pos)
{
	uint16_t xobject = pos * 10 + 20 + xpos;
	uint16_t yobject = ypos * 40 + 20;
	lcdscherm->fillRect(xobject-40,yobject,15,15,YELLOW);
}