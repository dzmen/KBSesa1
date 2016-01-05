#include <avr/io.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <String.h>
#include "button.h"
#include "game.h"

int main()
{
	init();
	
	MI0283QT9 lcd;
	
	lcd.begin();
	
	//TOP SECRET CODE 
	lcd.tp_matrix.a = 79800;
	lcd.tp_matrix.b = 4294966596;
	lcd.tp_matrix.c = 4250933096;
	lcd.tp_matrix.d = 2700;
	lcd.tp_matrix.e = 57800;
	lcd.tp_matrix.f = 4291263596;
	lcd.tp_matrix.div = 109865;
	
	//lcd.fillScreen(RGB(153,204,255));
	//
	//Button start = Button(40, "Start");
	//Button highscores = Button(100, "Highscores");
	//Button help = Button(160, "Help");
	//
	//start.drawButton(lcd);
	//highscores.drawButton(lcd);
	//help.drawButton(lcd);
	Game game = Game(lcd);
	while (1)
	{
		game.run();
		
		//lcd.touchRead();
		//
		//int a = lcd.touchX();
		//int b = lcd.touchY();
		//
		////if(a <= 20 && b <= 20)
		////{
			////lcd.drawChar(0,0,'a',RGB(0,0,0),RGB(153,204,255),2);
		////}
		//if (start.isPressed(a,b) == 1)
		//{
			//lcd.drawChar(0,0,'a',RGB(0,0,0),RGB(153,204,255),2);
		//}
		//if (highscores.isPressed(a,b) == 1)
		//{
			//lcd.drawChar(0,0,'b',RGB(0,0,0),RGB(153,204,255),2);
		//}
		//if (help.isPressed(a,b)== 1)
		//{
			//lcd.drawChar(0,0,'c',RGB(0,0,0),RGB(153,204,255),2);
		//}
		
	}
	
	return 0;
}
