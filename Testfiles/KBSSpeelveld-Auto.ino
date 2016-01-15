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
volatile uint8_t startcar = 0;
Car testauto;
ArduinoNunchuk nunchuk;

ISR(TIMER2_OVF_vect) {
	teller++;
	speed++;
	if ( speed >= 70)
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
	//Timer 2
	TCCR2B |= (1 << CS22) | (1<<CS20);
	TIMSK2 |= (1<<TOIE2);
	TCNT2 = 0;
	sei();
	
	nunchuk.init();
		
	testauto.Init(lcd);
	
	Gamefield veld;
	veld.Init(lcd);
	veld.StartRoad();
	veld.SetTimer(0);
	veld.SetHS(1000);
	uint8_t pos = 4;
	uint8_t dir = 1;
	startcar = 1;
	while (1)
	{
			//if (changeroad)
			//{
				veld.Generate();
			//	changeroad = 0;
			//}
			veld.SetTimer(seconden);
			testauto.Refresh(nunchuk);
			if (checkoffroad(testauto.GetPos(), veld.GetPos()))
			{
				veld.SetHS(999);
			}else{
				veld.SetHS(0);
			}
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