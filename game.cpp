// game.cpp
// 
// 

#include "game.h"
#include <MI0283QT9.h>
#include "button.h"
#include "ArduinoNunchuk.h"
#include "gamefield.h"
#include "car.h"
#include "highscore.h"
#include "selector.h"

#define WHITE RGB(255,255,255)
#define BLACK RGB(0,0,0)
#define LIGHT_BLUE RGB(153,204,255)
#define DARK_BLUE RGB(0,128,255)

void Game::init(MI0283QT9 lcd_p)
{
	lcd = &lcd_p;
	main_screen = 1;
	start_game = 0;
	highcore_screen = 0;
	help_screen = 0;
	game_highscores.init();
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
		field.Init(lcd);
		field.StartRoad();
		field.SetTimer(0);
		field.SetHS(1000);
		game_car.Init(lcd);	
		
		while(start_game)
		{
			field.Generate();
			game_car.Refresh(nunchuk);
			
			//if (nunchuk.cButton)
			//{
				uint8_t test = random(1,200);
				
				if (game_highscores.checkIfHighscore(test))
				{								
					lcd->fillScreen(LIGHT_BLUE);
				
					lcd->drawText(20, 20, "New highscore!", WHITE, LIGHT_BLUE, 2);
					lcd->drawText(20, 40, "Score:", WHITE, LIGHT_BLUE, 2);	
					lcd->drawInteger(120,40,test,DEC, WHITE, LIGHT_BLUE, 2);				
				
					Selector char1 = Selector(lcd,20,90,0);
					Selector char2 = Selector(lcd,80,90,1);
					Selector char3 = Selector(lcd,140,90,1);
					Selector char4 = Selector(lcd,200,90,1);
					Selector char5 = Selector(lcd,260,90,1);						
				
					Button add = Button(200, "add");
					add.drawButton(lcd);
				
					while(start_game)
					{
						updateTouch();
					
						char1.drawChar(lcd);
						char2.drawChar(lcd);
						char3.drawChar(lcd);
						char4.drawChar(lcd);
						char5.drawChar(lcd);
					
						if (char1.up_p->isPressed(touch_x, touch_y)) //1
						{
							char1.add();
							removeLastTouch();
						}
						if (char1.down_p->isPressed(touch_x, touch_y))
						{
							char1.subtract();
							removeLastTouch();
						}
						if (char2.up_p->isPressed(touch_x, touch_y)) //2
						{
							char2.add();
							removeLastTouch();
						}
						if (char2.down_p->isPressed(touch_x, touch_y))
						{
							char2.subtract();
							removeLastTouch();
						}
						if (char3.up_p->isPressed(touch_x, touch_y)) //3
						{
							char3.add();
							removeLastTouch();
						}
						if (char3.down_p->isPressed(touch_x, touch_y))
						{
							char3.subtract();
							removeLastTouch();
						}
						if (char4.up_p->isPressed(touch_x, touch_y)) //4
						{
							char4.add();
							removeLastTouch();
						}
						if (char4.down_p->isPressed(touch_x, touch_y))
						{
							char4.subtract();
							removeLastTouch();
						}
						if (char5.up_p->isPressed(touch_x, touch_y)) //5
						{
							char5.add();
							removeLastTouch();
						}
						if (char5.down_p->isPressed(touch_x, touch_y))
						{
							char5.subtract();
							removeLastTouch();
						}					
						if (add.isPressed(touch_x, touch_y))
						{
							char s[6] = {char1.getChar(),char2.getChar(),char3.getChar(),char4.getChar(),char5.getChar(),'\0'};
							
							game_highscores.addHighscore(test,s);
							removeLastTouch();
							start_game = 0;
							main_screen = 1;
						}
					}
				//}
			}
			else
			{
				removeLastTouch();
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
		
		highscore number1 = game_highscores.getHighscore(1);
		highscore number2 = game_highscores.getHighscore(2);
		highscore number3 = game_highscores.getHighscore(3);
		
		if (number1.score)
		{
			lcd->drawChar(20, 20, '1', WHITE, LIGHT_BLUE, 3);
			lcd->drawText(60, 20, number1.name, WHITE, LIGHT_BLUE, 3);
			lcd->drawInteger(200, 20, number1.score, DEC, WHITE, LIGHT_BLUE, 3);
			
			if (number2.score)
			{
				lcd->drawChar(20, 50, '2', WHITE, LIGHT_BLUE, 3);
				lcd->drawText(60, 50, number2.name, WHITE, LIGHT_BLUE, 3);
				lcd->drawInteger(200, 50, number2.score, DEC, WHITE, LIGHT_BLUE, 3);
				
				if (number3.score)
				{
					lcd->drawChar(20, 80, '3', WHITE, LIGHT_BLUE, 3);
					lcd->drawText(60, 80, number3.name, WHITE, LIGHT_BLUE, 3);
					lcd->drawInteger(200, 80, number3.score, DEC, WHITE, LIGHT_BLUE, 3);
				}
			}
		}
		else
		{
			lcd->drawText(20,20,"No highscores yet.",WHITE,LIGHT_BLUE, 2);
		}
								
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
		
		game_highscores.resetHighscores();
		
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