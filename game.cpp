// game.cpp
// 
// 

#include "game.h"
#include <MI0283QT9.h>
#include "button.h"

Game::Game(MI0283QT9 *lcd_p)
{
	lcd = lcd_p;
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
		
		while(start_game)
		{
			updateTouch();
			
			if (back.isPressed(touch_x, touch_y))
			{
				back.removeButton(lcd);
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
		Button back = Button(100, "back");
		back.drawButton(lcd);
		
		
		while(help_screen)
		{
			updateTouch();
			
			if (back.isPressed(touch_x, touch_y))
			{
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