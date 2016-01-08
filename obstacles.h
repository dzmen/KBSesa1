// obstacles.h

#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#include <MI0283QT9.h>

typedef struct
{
			uint8_t obstacleY;
			uint8_t obstacleX;
			uint8_t roadpos;
			uint8_t ypos;
			uint8_t xpos;
			uint8_t type;

}Obstacle;


class Obstacles{
	public:
	
			void Init(MI0283QT9 * lcd);
			void Createobject(uint8_t pos);
			void Next();
			
			
	
	private:
		uint16_t x;
		uint16_t y;
		MI0283QT9 * lcdscherm;
		uint8_t ypos;
		uint8_t xpos;
		uint8_t objecttype;
		uint8_t obstacleY;
		uint8_t obstacleX;
		uint8_t roadpos;
		
		void ObstacleSlow(); // Draw arrow to the back
		void ObstacleFast(); // Draw arrow to the front
		void ObstacleSteering(); // Draw double arrow
		void ObstacleBlock(); // Draw Block
	
	
	};
#endif