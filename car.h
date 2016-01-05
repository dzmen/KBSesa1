// car.h

#ifndef _CAR_h
#define _CAR_h

#include <MI0283QT9.h>
#include "ArduinoNunchuk.h"

class Car
{
	public:
		/**
		 * Constructs a Car
		 * 
		 * @param lcd The LCD to render the car on
		 */	
		void Init(MI0283QT9 *lcd);
		
		/**
		 * Constructs a Car
		 * 
		 * @param nunchuk Used to get nunchuk values
		 */	
		void Refresh(ArduinoNunchuk nunchuk);
		
		void ObstacleSlow(); // Draw arrow to the back
		void ObstacleFast(); // Draw arrow to the front
		void ObstacleSteering(); // Draw double arrow
		void ObstacleBlock(); // Draw Block
		
		uint16_t GetPos();
		
	private:
		MI0283QT9 * lcdscherm;
		uint16_t x;
	    uint16_t y;
	
	
		void Straight();
		/**
		 * Moves the car to the left
		 * 
		 * @param width The amount of pixels the car has to move
		 */	
		void Left(uint8_t width);
		
		/**
		 * Moves the car to the right
		 * 
		 * @param width The amount of pixels the car has to move
		 */	
		void Right(uint8_t width);
};


#endif