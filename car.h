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
		 * @param *lcd Pointer to the LCD to render the car on
		 * @param nunchuk Used to get nunchuk values
		 */	
		void Init(MI0283QT9 *lcd, ArduinoNunchuk nunchuck);
		
		/**
		 * Refreshes the car so it can move depending on nunchuk direction	 
		 */	
		void Refresh();
		
		/**
		 * Get the position of the car
		 *
		 * @return x coord of the car
		 */		
		uint16_t GetPos();
		
	private:
		MI0283QT9 * lcdscherm;
		ArduinoNunchuk nunchuk;
		uint16_t x;
		uint16_t y;
	    uint8_t dir;
		/**
		 * Keeps the car going straight
		 */	
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
		void Up();
		void Down();
		void Reverse();
};

#endif