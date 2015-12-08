// car.h

#ifndef _CAR_h
#define _CAR_h

#include <MI0283QT9.h>

class Car
{
	public:
		/**
		 * Constructs a Car
		 * 
		 * @param lcd The LCD to render the car on
		 */	
		Car(MI0283QT9 lcd);
		void Left(MI0283QT9 lcd, uint16_t xL, uint8_t widthL);
		void Right(MI0283QT9 lcd, uint16_t xR, uint8_t widthR);
	private:
		uint16_t xL;
		uint16_t xR;
		uint8_t widthL;
		uint8_t widthR;
};


#endif

