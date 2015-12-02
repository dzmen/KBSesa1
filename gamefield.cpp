#include "gamefield.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>

void Gamefield::DrawRoad(MI0283QT9 lcdscherm, uint8_t hpos, uint8_t wpos)
{
	lcdscherm.fillRect(0, hpos * 40, wpos * 20, 40, RGB(100, 240, 20));
	lcdscherm.fillRect(wpos * 20, hpos * 40, 10, 40, RGB(240, 100, 20));
	lcdscherm.fillRect(wpos * 20 + 10, hpos * 40, 120, 40, RGB(160, 160, 160));
	lcdscherm.fillRect(wpos * 20 + 130, hpos * 40, 10, 40, RGB(240, 100, 20));
	lcdscherm.fillRect(wpos * 20 + 140, hpos * 40, 320 - (wpos * 20 + 140), 40, RGB(100, 240, 20));
}

void Gamefield::SetTimer(MI0283QT9 lcdscherm, uint32_t time)
{
	lcdscherm.drawInteger(8, 8, time, DEC, RGB(0,0,0), RGB(100, 240, 20), 1);
}

void Gamefield::DrawHS(MI0283QT9 lcdscherm)
{
	lcdscherm.drawText(240, 8, "HIGHSCORE:", RGB(0,0,0) , RGB(100, 240, 20), 1);
}

void Gamefield::SetHS(MI0283QT9 lcdscherm, uint32_t score)
{
	lcdscherm.drawInteger(290, 25, score, DEC, RGB(0,0,0) , RGB(100, 240, 20), 1);
}

void Gamefield::DrawMenu(MI0283QT9 lcd)
{
	lcd.fillRoundRect(250, 190, 50, 25,5,RGB(0,128,255));
	lcd.drawText(260,200,"MENU", RGB(255,255,255),RGB(0,128,255),1);
}