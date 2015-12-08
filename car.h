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
		Car(MI0283QT9 lcd);
		void Refresh(MI0283QT9 lcd, ArduinoNunchuk nunchuk, Car testauto);
	private:
		void Left(MI0283QT9 lcd, uint16_t xL, uint8_t widthL);
		void Right(MI0283QT9 lcd, uint16_t xR, uint8_t widthR);
		
		uint16_t xL;
		uint16_t xR;
		uint8_t widthL;
		uint8_t widthR;
};


#endif

