// obstacles.h

#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#include <MI0283QT9.h>
class Obstacles{
	public:
     		void Init(MI0283QT9 * lcd);
	 		void Createobject(uint8_t arrayid, uint8_t pos);
			void Next(uint8_t arrayid);
			uint8_t IsActive(uint8_t arrayid);	
			uint8_t GetRoad(uint8_t arrayid);
			uint8_t GetXpos(uint8_t arrayid);
			uint8_t GetYpos(uint8_t arrayid);
			uint8_t GetType(uint8_t arrayid);
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

		void ObstacleSlow(uint8_t arrayid); // Draw arrow to the back
		void ObstacleFast(uint8_t arrayid); // Draw arrow to the front
		void ObstacleSteering(uint8_t arrayid); // Draw double arrow
		void ObstacleBlock(uint8_t arrayid); // Draw Block
	
	
	};
#endif