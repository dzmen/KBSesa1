#include "gamefield.h"
#include <Arduino.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

Gamefield::Gamefield(MI0283QT9 lcd)
{
	lcdscherm = &lcd;
}

void Gamefield::StartRoad()
{
	lcdscherm->fillRect(0, 0, 100, 240, RGB(100, 240, 20));
	lcdscherm->fillRect(100, 0, 10, 240, RGB(240, 100, 20));
	lcdscherm->fillRect(110, 0, 120, 240, RGB(160, 160, 160));
	lcdscherm->fillRect(230, 0, 10, 240, RGB(240, 100, 20));
	lcdscherm->fillRect(240, 0, 80, 240, RGB(100, 240, 20));
}

void Gamefield::MoveRoad(uint8_t hpos, uint8_t dir)
{
	if(dir){
		int wpos = pos[hpos];
		lcdscherm->fillRect(wpos * 20 + 20, hpos * 40, 20, 40, RGB(100, 240, 20));
		lcdscherm->fillRect(wpos * 20 + 40, hpos * 40, 10, 40, RGB(240, 100, 20));
		lcdscherm->fillRect(wpos * 20 + 150, hpos * 40, 20, 40, RGB(160, 160, 160));
		lcdscherm->fillRect(wpos * 20 + 170, hpos * 40, 10, 40, RGB(240, 100, 20));
		pos[hpos]++;
		}else{
		int wpos = pos[hpos];
		lcdscherm->fillRect(wpos * 20 , hpos * 40, 10, 40, RGB(240, 100, 20));
		lcdscherm->fillRect(wpos * 20 + 10, hpos * 40, 20, 40, RGB(160, 160, 160));
		lcdscherm->fillRect(wpos * 20 + 130, hpos * 40, 10, 40, RGB(240, 100, 20));
		lcdscherm->fillRect(wpos * 20 + 140, hpos * 40, 20, 40, RGB(100, 240, 20));
		pos[hpos]--;
	}
}

void Gamefield::Generate()
{
	if (newpos == 100 || newpos == pos[0])
	{
		newpos = random(0, 8);
	}
	uint8_t vorigepos = 100;
	for (int i = 0; i < 6; i++)
	{
		if (vorigepos == 100)
		{
			vorigepos = newpos;
		}

		if (vorigepos > pos[i])
		{
			MoveRoad(i, 1);
			vorigepos = pos[i]-1;
		}else if (vorigepos < pos[i])
		{
			MoveRoad(i, 0);
			vorigepos = pos[i]+1;
		}
	}
	lcdscherm->drawInteger(8, 8, timer, DEC, RGB(0,0,0), RGB(100, 240, 20), 1|0x00);
}

void Gamefield::SetTimer(uint32_t timing)
{
	timer = timing;
}

void Gamefield::DrawHS()
{
	lcdscherm->drawText(240, 8, "HIGHSCORE:", RGB(0,0,0) , RGB(100, 240, 20), 1);
}

void Gamefield::SetHS(uint32_t score)
{
	lcdscherm->drawInteger(290, 25, score, DEC, RGB(0,0,0) , RGB(100, 240, 20), 1);
}