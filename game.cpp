// game.cpp
// 
// 

#include "game.h"
#include <MI0283QT9.h>
#include "button.h"
#include "ArduinoNunchuk.h"
#include "gamefield.h"
#include "car.h"

#define WHITE RGB(255,255,255)
#define LIGHT_BLUE RGB(153,204,255)
#define DARK_BLUE RGB(0,128,255)

void Game::Init(MI0283QT9 lcd_p)
{
	lcd = &lcd_p;
	main_screen = 1;
	start_game = 0;
	highcore_screen = 0;
	help_screen = 0;	
}

void Game::run()
{
	
	/**
	* Run the main menu 
	*/	
	if(main_screen)
	{
		lcd->fillScreen(LIGHT_BLUE);	
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
		nunchuk = ArduinoNunchuk();
		nunchuk.init();
		veld.Init(lcd);
		veld.StartRoad();
		veld.SetTimer(0);
		veld.SetHS(1000);
		autotje.Init(lcd);
		
		while(start_game)
		{
			veld.Generate();
			autotje.Refresh(nunchuk);
			
			if (nunchuk.cButton)
			{
				start_game = 0;
				main_screen = 1;
			}
		}
	}
	/**
	* Run the highscore screen
	*/	
	else if(highcore_screen)
	{
		Button back = Button(200, "back");
		back.drawButton(lcd);	
		
		lcd->drawChar(20,20,'1',WHITE, LIGHT_BLUE, 3);
		lcd->drawChar(20,50,'2',WHITE, LIGHT_BLUE, 3);
		lcd->drawChar(20,80,'3',WHITE, LIGHT_BLUE, 3);
		
		lcd->drawText(60,20,"Wilco",WHITE,LIGHT_BLUE, 3);
		lcd->drawText(60,50,"Jann",WHITE,LIGHT_BLUE, 3);
		lcd->drawText(60,80,"Jan",WHITE,LIGHT_BLUE, 3);
		
		lcd->drawInteger(200,20,200,DEC, WHITE,LIGHT_BLUE, 3);
		lcd->drawInteger(200,50,182,DEC, WHITE,LIGHT_BLUE, 3);
		lcd->drawInteger(200,80,20,DEC, WHITE,LIGHT_BLUE, 3);
				
		while(highcore_screen)
		{
			updateTouch();
			
			if (back.isPressed(touch_x, touch_y))
			{						
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
		String helptext[] = {"GoFast is een racegame met als doel","zo lang mogelijk op de baan te","blijven. Als de auto op de rode","strook komt dan ben je af. De auto",
			"die je bestuurd gaat steeds sneller","rijden waardoor het spel steeds","moeilijker wordt. Hoe langer je het","vol houdt, hoe hoger je score is.",
			"De drie hoogste scores worden","opgeslagen in de Highscore lijst. Je","bestuurt het spel met de joystick,","hiermee kun je de auto hard of",
		"zacht naar links of rechts","laten rijden."};
		int yasregel = 40;
		for (int i = 0; i < 14; i++)
		{
			lcd->drawText(20,yasregel,helptext[0+ i],WHITE,LIGHT_BLUE,1);
	     	yasregel = yasregel + 10;
		}
		
		while(help_screen)
		{
			updateTouch();
			
			if (back.isPressed(touch_x, touch_y))
			{
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
	lcd->lcd_x = 0;
	lcd->lcd_y = 0;
	touch_x = 0;
	touch_y = 0;
}