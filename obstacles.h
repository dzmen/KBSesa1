#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#include <MI0283QT9.h>
class Obstacles{
	public:
	
	/**
	* Initialize the obstacle object
	*
	* @param lcd_p A pointer to a lcd to render the obstacles on
	*/
	void Init(MI0283QT9 * lcd);
	
	/**
	* Create an obstacle
	*
	* @param arrayid Gets the array position
	* @param pos Gets the road position
	*/
	void Createobject(uint8_t arrayid, uint8_t pos);
	
	/**
	* Goes to the next position of the obstacle
	* @param arrayid Gets the array position
	*/
	void Next(uint8_t arrayid);
	
	/**
	* Check if the obstacle is active
	* @param arrayid The array position of the obstacles array
	*/
	uint8_t IsActive(uint8_t arrayid);
	
	/**
	* Return the road position of the obstacle
	* @param arrayid The array position of the obstacles array
	*/
	uint8_t GetRoad(uint8_t arrayid);
	
	/**
	* Return the X position of the obstacle
	* @param arrayid The array position of the obstacles array
	*/
	uint8_t GetXpos(uint8_t arrayid);
	
	/**
	* Return the Y position of the obstacle
	* @param arrayid The array position of the obstacles array
	*/
	uint8_t GetYpos(uint8_t arrayid);
	
	/**
	* Return the Type of the obstacle
	* @param arrayid The array position of the obstacles array
	*/
	uint8_t GetType(uint8_t arrayid);
	
	/**
	* Remove the obstacle from the road
	* @param arrayid The array position of the obstacles array
	*/
	void RemoveObstacle(uint8_t arrayid);
	
	private:
	typedef struct
	{
		uint8_t roadpos;
		uint8_t xpos;
		uint8_t ypos;
		uint8_t type;
		uint8_t active;
	}Obstacle;
	
	MI0283QT9 * lcdscherm;
	Obstacle objecten[10];

	/**
	* Draw the down arrow
	* @param arrayid The array position of the obstacles array
	*/
	void ObstacleSlow(uint8_t arrayid);
	
	/**
	* Draw the up arrow
	* @param arrayid The array position of the obstacles array
	*/
	void ObstacleFast(uint8_t arrayid);
	
	/**
	* Draw the steering change arrows
	* @param arrayid The array position of the obstacles array
	*/
	void ObstacleSteering(uint8_t arrayid);
	
	/**
	* Draw the block
	* @param arrayid The array position of the obstacles array
	*/
	void ObstacleBlock(uint8_t arrayid);
	
};
#endif