#include <avr/io.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <String.h>
#include <Wire.h>
#include "ArduinoNunchuk.h"
#include "gamefield.h"
#include "car.h"

volatile uint16_t teller = 0;
volatile uint8_t speed = 0;
volatile uint8_t seconden = 0;
volatile uint8_t changeroad = 0;

ISR(TIMER2_OVF_vect) {
	teller++;
	speed++;
	if ( speed >= 1)
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
	TCCR2B |= (1 << CS22) | (1<<CS20);
	TIMSK2 |= (1<<TOIE2);
	TCNT2 = 0;
	sei();
	
	lcd.begin();
	
	Gamefield veld;
	veld.StartRoad(lcd);
	veld.SetTimer(0);
	veld.SetHS(lcd, 1000);
	veld.DrawHS(lcd);
	veld.DrawMenu(lcd);
	Car testautotje = Car(lcd);
	uint8_t pos = 4;
	uint8_t dir = 1;
	while (1)
	{
			if (changeroad)
			{
				veld.Generate(lcd);
				changeroad = 0;
			}
			veld.SetTimer(seconden);
			
			
	}
	
	return 0;
}