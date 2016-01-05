// gamefield.h

#ifndef _GAMEFIELD_h
#define _GAMEFIELD_h

#include <MI0283QT9.h>

class Gamefield
{
	public:	
		/**
		 * Function Init
		 * 
		 * @param lcd The lcd screen driver
		 * @note Binds the lcd screen to the class
		 */	
		void Init(MI0283QT9 * lcd);
		/**
		 * Function Generate
		 * 
		 * @note Generate the random road
		 */			
		void Generate();
		/**
		 * Function SetTimer
		 * 
		 * @param timer The time you are playing
		 * @note Set the timer in the game
		 */	
		void SetTimer(uint32_t timer);	
		
		/**
		 * Function SetHS
		 * 
		 * @param score, The highscore at the moment
		 */	
		void SetHS(uint32_t score);
		
		/**
		 * Function StartRoad
		 * 
		 * @note draws the start road of the game
		 */	
		void StartRoad();
		
		/**
		 * Function GetPos
		 * 
		 * @note get the position of the road
		 */	
		
		uint8_t * GetPos();
		
		void Reset();
	private:
		uint8_t pos[6] = {8,8,8,8,8,8};
		uint8_t newpos = 100;
		uint32_t timer = 0;
		MI0283QT9 * lcdscherm;
		/**
		 * Function MoveRoad
		 * 
		 * @param hpos Y position of the road. Max 5
		 * @param dir gives the direction of change. 1 is right, 0 is left
		 * @note draw 40 Y pixels of the road and 10 X on both side of the road
		 */			
		void MoveRoad(uint8_t hpos, uint8_t dir);
};

#endif

