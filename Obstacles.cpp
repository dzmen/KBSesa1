#include "Obstacles.h"

#include <Arduino.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

#define YELLOW RGB(255,196,0)
#define GRAY RGB(160, 160, 160)

void Obstacles::Init(MI0283QT9 * lcd)
{
	lcdscherm = lcd;
}

void Obstacles::Createobject(uint8_t arrayid, uint8_t pos)
{
	objecten[arrayid].roadpos = pos;
	objecten[arrayid].ypos = 0;
	objecten[arrayid].xpos = random(60, 100);
	objecten[arrayid].type = random(0,4);
	objecten[arrayid].active = 1;
	switch (objecten[arrayid].type)
	{
		case 0:
			ObstacleSteering(arrayid);
			break;
		case 1:
			ObstacleBlock(arrayid);
			break;
		case 2:
			ObstacleSlow(arrayid);
			break;
		case 3:
			ObstacleFast(arrayid);
			break;
	}
}

void Obstacles::Next(uint8_t arrayid)
{
	RemoveObstacle(arrayid);
	objecten[arrayid].ypos++;
	if (objecten[arrayid].ypos <= 6)
	{
		switch (objecten[arrayid].type)
		{
			case 0:
				ObstacleSteering(arrayid);
				break;
			case 1:
				ObstacleBlock(arrayid);
				break;
			case 2:
				ObstacleSlow(arrayid);
				break;
			case 3:
				ObstacleFast(arrayid);
				break;
		}
	}else{
		objecten[arrayid].active = 0;
	}
}

uint8_t Obstacles::IsActive(uint8_t arrayid){
	return objecten[arrayid].active;
	
}

uint8_t Obstacles::GetRoad(uint8_t arrayid){
	return objecten[arrayid].roadpos;
}
uint8_t Obstacles::GetXpos(uint8_t arrayid){
	return objecten[arrayid].xpos;
}
uint8_t Obstacles::GetYpos(uint8_t arrayid){
	return objecten[arrayid].ypos;
}
uint8_t Obstacles::GetType(uint8_t arrayid){
	return objecten[arrayid].type;
}


void Obstacles::RemoveObstacle(uint8_t arrayid)
{
	uint8_t obstacleX;
	uint8_t obstacleY;
	uint16_t xobject = objecten[arrayid].roadpos * 10 + 20 + objecten[arrayid].xpos;
	switch (objecten[arrayid].type)
	{
		case 0:   // steering
			xobject -= 48;
			obstacleX = 23;
			obstacleY = 11;
			break;
		case 1: // block
			xobject -= 40;
			obstacleX = 15;
			obstacleY = 15;
			break;
		case 2: // slow
			xobject -=51;
			obstacleX = 22;
			obstacleY = 21;
			break;
		case 3: // fast
			xobject -=51;
			obstacleX = 22;
			obstacleY = 21;
			break;
	}
	uint16_t yobject = objecten[arrayid].ypos * 40 + 10;
	lcdscherm->fillRect(xobject, yobject, obstacleX, obstacleY, GRAY);
}

void Obstacles::ObstacleSlow(uint8_t arrayid)
{
	//obstacleX = 10;
	//obstacleY = 20;
	uint16_t xobject = objecten[arrayid].roadpos * 10 + 20 + objecten[arrayid].xpos;
	uint16_t yobject = objecten[arrayid].ypos * 40 + 10;
	lcdscherm->fillTriangle(xobject-50,yobject+10,xobject-30,yobject+10,xobject-40,yobject+20,YELLOW);
	lcdscherm->fillRect(xobject-43,yobject,6,10,YELLOW);
}

void Obstacles::ObstacleFast(uint8_t arrayid)
{
	//obstacleX = 10;
	//obstacleY = 20;
	uint16_t xobject = objecten[arrayid].roadpos * 10 + 20 + objecten[arrayid].xpos;
	uint16_t yobject = objecten[arrayid].ypos * 40 + 10;
	lcdscherm->fillTriangle(xobject-50,yobject+10,xobject-30,yobject+10,xobject-40,yobject,YELLOW);
	lcdscherm->fillRect(xobject-43,yobject+10,6,10,YELLOW);
}

void Obstacles::ObstacleSteering(uint8_t arrayid)
{
	//obstacleX = 21;
	//obstacleY = 10;
	uint16_t xobject = objecten[arrayid].roadpos * 10 + 20 + objecten[arrayid].xpos;
	uint16_t yobject = objecten[arrayid].ypos * 40 + 10;
	lcdscherm->fillTriangle(xobject-40,yobject,xobject-47,yobject+5,xobject-40,yobject+10,YELLOW);
	lcdscherm->fillRect(xobject-40,yobject+4,7,2,YELLOW);
	lcdscherm->fillTriangle(xobject-33,yobject,xobject-26,yobject+5,xobject-33,yobject+10,YELLOW);
}

void Obstacles::ObstacleBlock(uint8_t arrayid)
{
	//obstacleX = 15;
	//obstacleY = 15;
	uint16_t xobject = objecten[arrayid].roadpos * 10 + 20 + objecten[arrayid].xpos;
	uint16_t yobject = objecten[arrayid].ypos * 40 + 10;
	lcdscherm->fillRect(xobject-40,yobject,15,15,YELLOW);
}