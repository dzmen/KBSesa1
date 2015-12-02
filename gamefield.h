// gamefield.h

#ifndef _GAMEFIELD_h
#define _GAMEFIELD_h

#include <MI0283QT9.h>

class Gamefield
{
	public:	
		/**
		 * Function DrawRoad
		 * 
		 * @param lcdscherm The LCD to render the road on
		 * @param hpos Y position of the road. Max 5
		 * @param wpos X position of the road. Max 8
		 * @note draw 40 Y pixels of the road
		 */			
		void DrawRoad(MI0283QT9 lcdscherm, uint8_t hpos, uint8_t wpos);
		
		void SetTimer(MI0283QT9 lcdscherm, uint32_t time);	
		
		void DrawHS(MI0283QT9 lcdscherm);
		
		void SetHS(MI0283QT9 lcdscherm, uint32_t score);
		
		void DrawMenu(MI0283QT9 lcd);
		
};

#endif

