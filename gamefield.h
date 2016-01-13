// gamefield.h

#ifndef _GAMEFIELD_h
#define _GAMEFIELD_h

#include <MI0283QT9.h>
#include "car.h"
#include "obstacles.h"



class Gamefield
{
	public:	
		/**
		 * Function Init
		 * 
		 * @param lcd The lcd screen driver
		 * @note Binds the lcd screen to the class
		 */	
		void Init(MI0283QT9 * lcd, ArduinoNunchuk nunchuck);
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
		
		uint8_t CheckGame();
		
	private:
		uint8_t pos[6] = {0,0,0,0,0,0};
		uint8_t gameover;
		uint8_t countobstacles = 0;
		uint8_t totalobstacles = 1;
		uint8_t generateobstacle;
		uint8_t newpos;
		uint32_t timer;
		MI0283QT9 * lcdscherm;
		ArduinoNunchuk nunchuk;
		Car game_car;
		Obstacles obsta;
		uint8_t nummer;
		/**
		 * Function MoveRoad
		 * 
		 * @param hpos Y position of the road. Max 5
		 * @param dir gives the direction of change. 1 is right, 0 is left
		 * @note draw 40 Y pixels of the road and 10 X on both side of the road
		 */			
		void MoveRoad(uint8_t hpos, uint8_t dir);
		
		uint8_t offroad(uint16_t carpos, uint8_t * roadpos);
		uint8_t Working(uint8_t arrayid);
};

#endif

