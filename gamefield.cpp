#include "gamefield.h"
#include "ArduinoNunchuk.h"
#include "car.h"
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
	
	for (uint8_t i = 0;i<6;i++)
	{
		pos[i] = 8;
	}
	newpos = 100;
	timer = 0;
}

void Gamefield::StartRoad()
{
	lcdscherm->fillRect(0, 0, 100, 240, GREEN);
	lcdscherm->fillRect(90, 0, 10, 240, ORANGE);
	lcdscherm->fillRect(100, 0, 120, 240, GRAY);
	lcdscherm->fillRect(220, 0, 10, 240, ORANGE);
	lcdscherm->fillRect(230, 0, 90, 240, GREEN);
}

void Gamefield::MoveRoad(uint8_t hpos, uint8_t dir)
{
	uint8_t wlength = 10;
	if(dir){
		int wpos = pos[hpos];
		lcdscherm->fillRect(wpos * wlength + wlength, hpos * 40, wlength, 40, GREEN);
		lcdscherm->fillRect(wpos * wlength + wlength + 10, hpos * 40, 10, 40, ORANGE);
		lcdscherm->fillRect(wpos * wlength + wlength + 130, hpos * 40, wlength, 40, GRAY);
		lcdscherm->fillRect(wpos * wlength + wlength + 140, hpos * 40, 10, 40, ORANGE);
		pos[hpos]++;
		}else{
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
	if (newpos == 100 || newpos == pos[0])
	{
		newpos = random(1, 15);
	}
	uint8_t vorigepos = 100;
	for (uint8_t i = 0; i < 6; i++)
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
	uint8_t gameover = offroad(game_car.GetPos(), GetPos());
	return gameover;
}

uint8_t Gamefield::offroad(uint16_t carpos, uint8_t * roadpos)
{
	uint8_t roadmin = ((roadpos[4]>roadpos[5])?roadpos[4]:roadpos[5]);
	uint8_t roadmax = ((roadpos[4]>roadpos[5])?roadpos[5]:roadpos[4]);
	if ((roadmin * 10 + 20) >= (carpos - 20) || (roadmax * 10 + 140) <= (carpos + 20))
	{
		return 1;
	}else{
		return 0;
	}
}