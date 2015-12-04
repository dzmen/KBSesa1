// gamefield.h

#ifndef _GAMEFIELD_h
#define _GAMEFIELD_h

#include <MI0283QT9.h>

class Gamefield
{
	public:	
		/**
		 * Function MoveRoad
		 * 
		 * @param lcdscherm The LCD to render the road on
		 * @param hpos Y position of the road. Max 5
		 * @param dir gives the direction of change. 1 is right, 0 is left
		 * @note draw 40 Y pixels of the road and 20 X on both side of the road
		 */			
		void MoveRoad(MI0283QT9 lcdscherm, uint8_t hpos, uint8_t dir);
		
		/**
		 * Function SetTimer
		 * 
		 * @param lcdscherm The LCD to render the road on
		 * @param time The time you are playing
		 * @note Set the timer in the game
		 */	
		void SetTimer(MI0283QT9 lcdscherm, uint32_t time);	
		
		/**
		 * Function DrawHS
		 * 
		 * @param lcdscherm The LCD to render the road on
		 * @note draws the text "HIGHSCORE"
		 */	
		void DrawHS(MI0283QT9 lcdscherm);
		
		/**
		 * Function SetHS
		 * 
		 * @param lcdscherm, The LCD to render the road on
		 * @param score, The highscore at the moment
		 */	
		void SetHS(MI0283QT9 lcdscherm, uint32_t score);
		
		/**
		 * Function DrawMenu
		 * 
		 * @param lcdscherm The LCD to render the road on
		 * @note draws the menu button
		 */	
		void DrawMenu(MI0283QT9 lcd);
		
		/**
		 * Function StartRoad
		 * 
		 * @param lcdscherm The LCD to render the road on
		 * @note draws the start road of the game
		 */	
		void StartRoad(MI0283QT9 lcdscherm);
		
};

#endif

