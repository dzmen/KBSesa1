#include <avr/io.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <String.h>
#include <Wire.h>
#include "game.h"

volatile uint16_t teller = 0;
volatile uint8_t speed = 0;
volatile uint8_t seconden = 0;
volatile uint8_t changeroad = 0;
Game spel;

ISR(TIMER2_OVF_vect) {
	teller++;
	speed++;
	if ( speed >= 2)
	{
		changeroad = 1;
		speed = 0;
	}
	if ( teller >= 300)
	{
		seconden++;
		teller = 0;
	}
}


int main()
{
	init();
	MI0283QT9 lcd;
	lcd.begin();
	lcd.touchStartCal();
	//TOP SECRET CODE
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	
	spel.Init(lcd);
	
	TCCR2B |= (1 << CS22) | (1<<CS20);
	TIMSK2 |= (1<<TOIE2);
	TCNT2 = 0;
	sei();

	while (1)
	{
		spel.run();
	}
	
	return 0;
}

uint8_t checkoffroad(uint16_t carpos, uint8_t * roadpos){
	//carpos.  -20 is min,  +20 is max
	//roadpos. roadpos * 10 + 10 is min, roadpos * 10 + 130 is max
	uint8_t roadmin = ((roadpos[4]>roadpos[5])?roadpos[4]:roadpos[5]);
	uint8_t roadmax = ((roadpos[4]>roadpos[5])?roadpos[5]:roadpos[4]);
	if ((roadmin * 10 + 10) >= (carpos - 20) || (roadmax * 10 + 140) <= (carpos + 20))
	{
		return 1;
		}else{
		return 0;
	}
}