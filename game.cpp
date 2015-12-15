// game.cpp
// 
// 

#include "game.h"
#include <MI0283QT9.h>
#include "button.h"
#include "ArduinoNunchuk.h"
#include "gamefield.h"
#include "car.h"

void Game::Init(MI0283QT9 lcd_p)
{
	lcd = &lcd_p;
	main_screen = 1;
	start_game = 0;
	highcore_screen = 0;
	help_screen = 0;	
	lcd->fillScreen(RGB(153,204,255));	
}

void Game::run()
{
	
	/**
	* Run the main menu 
	*/	
	if(main_screen)
	{
		Button start = Button(40, "Start");
		Button highscores = Button(100, "Highscores");
		Button help = Button(160, "Help");
		
		start.drawButton(lcd);
		highscores.drawButton(lcd);
		help.drawButton(lcd);
		
		while(main_screen)
		{
			updateTouch();
			
			if (start.isPressed(touch_x, touch_y))
			{
				start.removeButton(lcd);
				highscores.removeButton(lcd);
				help.removeButton(lcd);
				removeLastTouch();
				main_screen = 0;
				start_game = 1;
				
			}
			else if (highscores.isPressed(touch_x, touch_y))
			{
				start.removeButton(lcd);
				highscores.removeButton(lcd);
				help.removeButton(lcd);
				removeLastTouch();
				main_screen = 0;
				highcore_screen = 1;
				
			}
			else if (help.isPressed(touch_x, touch_y))
			{
				start.removeButton(lcd);
				highscores.removeButton(lcd);
				help.removeButton(lcd);
				removeLastTouch();
				main_screen = 0;
				help_screen = 1;
				
			}
		}
	}
	/**
	* Run the game
	*/	
	else if(start_game)
	{
		Button back = Button(0,10, "back");
		back.drawButton(lcd);
		
		nunchuk = ArduinoNunchuk();
		nunchuk.init();
		veld.Init(lcd);
		veld.StartRoad();
		veld.SetTimer(0);
		veld.SetHS(1000);
		autotje.Init(lcd);
		
		while(start_game)
		{
			updateTouch();

			veld.Generate();
			autotje.Refresh(nunchuk);
			
			//if (back.isPressed(touch_x, touch_y))
			//{
			//	back.removeButton(lcd);
			//	removeLastTouch();
			//	start_game = 0;
			//	main_screen = 1;
			//}
		}
	}
	/**
	* Run the highscore screen
	*/	
	else if(highcore_screen)
	{
		Button back = Button(0,10, "back");
		back.drawButton(lcd);		
		
		while(highcore_screen)
		{
			updateTouch();
			
			if (back.isPressed(touch_x, touch_y))
			{
				back.removeButton(lcd);							
				removeLastTouch();
				highcore_screen = 0;
				main_screen = 1;			
			}
		}
	}
	/**
	* Run the help screen
	*/	
	else if(help_screen)
	{
		Button back = Button(200, "back");
		back.drawButton(lcd);
		lcd->drawText(20,40,"GoFast is een racegame met als doel",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,50,"zo lang mogelijk op de baan te ",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,60,"blijven. Als de auto op de rode",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,70,"strook komt dan ben je af. De auto",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,80,"die je bestuurd gaat steeds sneller",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,90,"rijden waardoor het spel steeds",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,100,"moeilijker wordt. Hoe langer je het",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,110,"vol houdt, hoe hoger je score is.",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,120,"De drie hoogste scores worden",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,130,"opgeslagen in de Highscore lijst. Je ",RGB(255,255,255),RGB(153,204,255),1);
		    lcd->drawText(20,140,"bestuurt het spel met de joystick,",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,150,"hiermee kun je de auto hard of",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,160,"zacht naar links of rechts",RGB(255,255,255),RGB(153,204,255),1);
			lcd->drawText(20,170,"laten rijden. ",RGB(255,255,255),RGB(153,204,255),1);
		while(help_screen)
		{
			updateTouch();
			
			if (back.isPressed(touch_x, touch_y))
			{
				lcd->fillScreen(RGB(153,204,255));	
				back.removeButton(lcd);
				removeLastTouch();
				help_screen = 0;
				main_screen = 1;
			}
		}
	}
}

void Game::updateTouch()
{
	lcd->touchRead();
	touch_x = lcd->touchX();
	touch_y = lcd->touchY();
}

void Game::removeLastTouch()
{
	touch_x = 1000;
	touch_y = 1000;
}