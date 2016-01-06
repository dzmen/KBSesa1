// obstacles.h

#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#include <MI0283QT9.h>

class Obstacles{
	public:
	
			void Init(MI0283QT9 * lcd);
			void ObstacleSlow(); // Draw arrow to the back
			void ObstacleFast(); // Draw arrow to the front
			void ObstacleSteering(); // Draw double arrow
			void ObstacleBlock(); // Draw Block
			
	
	private:
	
	uint16_t x;
	uint16_t y;
	MI0283QT9 * lcdscherm;
	
	
	};
#endif