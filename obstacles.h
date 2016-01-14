// obstacles.h

#ifndef _OBSTACLES_h
#define _OBSTACLES_h

#include <MI0283QT9.h>
class Obstacles{
	public:
	        
		/*
		  Constructs a obstacle
		  
		  @param *lcd Pointer to the LCD to render the obstacle on

		 */	
     		void Init(MI0283QT9 * lcd);
			 
	   /*
	   create a obstacle
	   @param arrayid Gets the array position
	   @param pos Gets the road position
	   */
	 		void Createobject(uint8_t arrayid, uint8_t pos);
			 
	    /*
	   goes to the next position of the obstacle
	   @param arrayid Gets the array position
	   */
			void Next(uint8_t arrayid);
	    /*
	   make the obstacle active
	   @param arrayid Gets the array position
	   */
			uint8_t IsActive(uint8_t arrayid);
			
	      /*
	  return the road position
	   @param arrayid Gets the array position
	   */	
			uint8_t GetRoad(uint8_t arrayid);	
	    /*
	   return the x position
	   @param arrayid Gets the array position
	   */	
			uint8_t GetXpos(uint8_t arrayid);
	   /*
	   return the y position
	   @param arrayid Gets the array position
	   */
			uint8_t GetYpos(uint8_t arrayid);
		 /*
	   return the type
	   @param arrayid Gets the array position
	   */
			uint8_t GetType(uint8_t arrayid);
	 /*
	   remove the obstacle
	   @param arrayid Gets the array position
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

         /*
	   Draw down
	   @param arrayid Gets the array position
	   */
		void ObstacleSlow(uint8_t arrayid); 
		   /*
	    Draw up
	   @param arrayid Gets the array position
	   */
		void ObstacleFast(uint8_t arrayid); 
		  /*
	    Draw steering
	   @param arrayid Gets the array position
	   */
		void ObstacleSteering(uint8_t arrayid); 
		  /*
	    Draw Block
	   @param arrayid Gets the array position
	   */
		void ObstacleBlock(uint8_t arrayid); 
	
	
	};
#endif