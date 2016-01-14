#include "gamefield.h"
#include "ArduinoNunchuk.h"
#include "car.h"
#include "obstacles.h"
#include <Arduino.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

#define GREEN RGB(100, 240, 20)
#define ORANGE RGB(240, 100, 20)
#define GRAY RGB(160, 160, 160)

void Gamefield::Init(MI0283QT9 * lcd, ArduinoNunchuk nunchuck)
{
	lcdscherm = lcd;
	nunchuk = nunchuck;
	game_car.Init(lcd, nunchuk);
	obsta.Init(lcd);
	for (uint8_t i = 0;i<6;i++)
	{
		pos[i] = 8;
	}
	newpos = 100;
	timer = 0;
}

void Gamefield::StartRoad()
{
	lcdscherm->fillRect(0, 0, 100, 240, GREEN);		//The left grass
	lcdscherm->fillRect(90, 0, 10, 240, ORANGE);	//The left orange line
	lcdscherm->fillRect(100, 0, 120, 240, GRAY);	//The gray road
	lcdscherm->fillRect(220, 0, 10, 240, ORANGE);	//The right orange line
	lcdscherm->fillRect(230, 0, 90, 240, GREEN);	//The right grass
	
	//Generate an obstacle after 10 seconds
	generateobstacle = 10;
	
	//Count how many obstacles are in the field
	countobstacles = 0;
	
	//The number of which road pieces need to be check if they are offroad
	nummer = 4;
	gameover = 0;
}

void Gamefield::MoveRoad(uint8_t hpos, uint8_t dir)
{
	uint8_t wlength = 10;

	if(dir){
		//Move the road to the right
		int wpos = pos[hpos];
		lcdscherm->fillRect(wpos * wlength + wlength, hpos * 40, wlength, 40, GREEN);
		lcdscherm->fillRect(wpos * wlength + wlength + 10, hpos * 40, 10, 40, ORANGE);
		lcdscherm->fillRect(wpos * wlength + wlength + 130, hpos * 40, wlength, 40, GRAY);
		lcdscherm->fillRect(wpos * wlength + wlength + 140, hpos * 40, 10, 40, ORANGE);
		pos[hpos]++;
	}else{
		//Move the road to the left
		int wpos = pos[hpos];
		lcdscherm->fillRect(wpos * wlength , hpos * 40, 10, 40, ORANGE);
		lcdscherm->fillRect(wpos * wlength + 10, hpos * 40, 10, 40, GRAY);
		lcdscherm->fillRect(wpos * wlength + 130, hpos * 40, 10, 40, ORANGE);
		lcdscherm->fillRect(wpos * wlength + 140, hpos * 40, 10, 40, GREEN);
		pos[hpos]--;
	}
}

uint8_t * Gamefield::GetPos()
{
	return pos;
}

void Gamefield::Generate()
{
	//Check if the top of the road is on the generated position
	if (newpos == 100 || newpos == pos[0])
	{
		newpos = random(1, 15);
	}
	uint8_t vorigepos = 100;
	uint8_t i = 0;
	
	//Loop through all the road pieces
	for (i = 0; i < 6; i++)
	{
		if (!gameover)
		{
			if (vorigepos == 100)
			{
				vorigepos = newpos;
			}

			if (vorigepos > pos[i])
			{
				MoveRoad(i, 1);
				game_car.Refresh();
				vorigepos = pos[i]-1;
				CheckGame();
			}else if (vorigepos < pos[i])
			{
				MoveRoad(i, 0);
				game_car.Refresh();
				vorigepos = pos[i]+1;
				CheckGame();
			}
		}
	}
	CheckGame();
	
	//Move the obstacle if there is an obstacle and remove it when it is outside lcd
	if(i == 6 && countobstacles > 0){
		i = 0;
		obsta.Next(0);
		if (obsta.IsActive(0) == 0)
		{
			countobstacles--;
		}
	}
	
	//Generate an obstacle when it is time and there are no other obstacles on the road
	if (timer == generateobstacle && countobstacles < totalobstacles)
	{
		obsta.Createobject(countobstacles, pos[0]);
		if (timer < 20)
		{
			generateobstacle += 10;
		}else if (timer > 19 && timer < 36)
		{
			generateobstacle += 8;
		}else if (timer > 35 && timer < 48)
		{
			generateobstacle += 6;
		}else if (timer > 47 && timer < 56)
		{
			generateobstacle += 4;
		}else if (timer > 55)
		{
			generateobstacle += 2;
		}
		countobstacles++;
	}
	lcdscherm->drawInteger(8, 8, timer, DEC, RGB(0,0,0), GREEN, 1||0x00);
	lcdscherm->drawText(240, 8, "HIGHSCORE:", RGB(0,0,0) , GREEN, 1||0x00);
}

void Gamefield::SetTimer(uint32_t timing)
{
	timer = timing;
}

void Gamefield::SetHS(uint32_t score)
{
	lcdscherm->drawInteger(290, 25, score, DEC, RGB(0,0,0) , GREEN, 1);
}

uint8_t Gamefield::CheckGame()
{
	uint8_t gameover = 0;
	//If there is an obstacle on the road, then check if player hits offroad or block obstacle. Else only check offroad
	if (countobstacles > 0)
	{
		(offroad(game_car.GetPosX(), GetPos())||Working(0))?gameover=1:gameover=0;
	}else{
		(offroad(game_car.GetPosX(), GetPos()))?gameover=1:gameover=0;
	}
	return gameover;
}

uint8_t Gamefield::Working(uint8_t arrayid){
	uint16_t obstacleX = 0;
	uint16_t obstacleY = 0;
	uint16_t xobject = obsta.GetRoad(arrayid) * 10 + 20 + obsta.GetXpos(arrayid);
	uint16_t yobject = obsta.GetYpos(arrayid) * 40 + 10;
	
	//Select the touch zone values of the object
	switch (obsta.GetType(arrayid))
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
	
	//Check if player hits an obstacle
	if ((xobject + obstacleX > game_car.GetPosX() - 20) && (xobject < game_car.GetPosX() + 20) && (yobject + obstacleY < game_car.GetPosY() +70) && (yobject > game_car.GetPosY()))
	{
		switch(obsta.GetType(arrayid)){
			case 0: //steering
			game_car.Reverse();
			obsta.RemoveObstacle(arrayid);
			countobstacles--;
			return 0;
			break;
			case 1: //block
			return 1;
			break;
			case 2://down
			obsta.RemoveObstacle(arrayid);
			if (nummer != 4)
			{
				nummer++;
				game_car.Down();
			}
			countobstacles--;
			return 0;
			break;
			case 3://up
			obsta.RemoveObstacle(arrayid);
			if (nummer != 1)
			{
				nummer--;
				game_car.Up();
			}
			countobstacles--;
			return 0;
			break;
		}
		}else{
		return 0;
	}
}

uint8_t Gamefield::offroad(uint16_t carpos, uint8_t * roadpos)
{
	//Calculate the minimal road size
	uint8_t roadmin = ((roadpos[nummer]>roadpos[nummer+1])?roadpos[nummer]:roadpos[nummer+1]);
	
	//Calculate the maximal road size
	uint8_t roadmax = ((roadpos[nummer]>roadpos[nummer+1])?roadpos[nummer+1]:roadpos[nummer]);
	
	//Check if car is offroad
	if ((roadmin * 10 + 20) >= (carpos - 20) || (roadmax * 10 + 140) <= (carpos + 20))
	{
		return 1;
		}else{
		return 0;
	}
}