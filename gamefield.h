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
	* @param lcd A pointer to a lcd to render the game elements on
	* @param nunchuck Used to get nunchuk values
	*
	*/
	void Init(MI0283QT9 * lcd, ArduinoNunchuk nunchuck);
	
	/**
	* Generate the random road every tick
	*
	*/
	void Generate();
	
	/**
	* Set the time value so it can be generated in the game
	*
	* @param timer The time you are playing
	* 
	*/
	void SetTimer(uint32_t timer);
	
	/**
	* Set the highscore value so it can be generated in the game
	*
	* @param score, The highscore at the moment
	*/
	void SetHS(uint32_t score);
	
	/**
	* Draws the start road of the game
	*
	*/
	void StartRoad();
	
	/**
	* Get the positions of the road peaces
	*
	*/
	
	uint8_t * GetPos();
	
	/**
	* Check if the player is still alive
	*
	*/
	
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
	* draw 40 Y pixels of the road and 10 X on both side of the road. Color depends of direction
	*
	* @param hpos Y position of the road. Max 5
	* @param dir gives the direction of change. 1 is right, 0 is left
	*/
	void MoveRoad(uint8_t hpos, uint8_t dir);
	
	/**
	* Checks if the player is off the road
	*
	* @param carpos The position of the car
	* @param roadpos The positions of the road
	*/	
	uint8_t offroad(uint16_t carpos, uint8_t * roadpos);
	
	/**
	* Checks if the player hits a obstacle
	*
	* @param arrayid The number of the obstacle that is generated
	*/
	uint8_t Working(uint8_t arrayid);
};

#endif

