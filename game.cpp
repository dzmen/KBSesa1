// game.cpp
// 
// 

#include "game.h"
#include <MI0283QT9.h>
#include "button.h"

Game::Game(MI0283QT9 lcd)
{
	this->lcd = lcd;
	this->main_screen = 1;
	this->start_game = 0;
	this->highcore_screen = 0;
	this->help_screen = 0;
	
	this->lcd.fillScreen(RGB(153,204,255));
	
}

void Game::run()
{
	
	/**
	* Run the main menu 
	*/	
	if(this->main_screen)
	{
		Button start = Button(40, "Start");
		Button highscores = Button(100, "Highscores");
		Button help = Button(160, "Help");
		
		start.drawButton(this->lcd);
		highscores.drawButton(this->lcd);
		help.drawButton(this->lcd);
		
		while(this->main_screen)
		{
			updateTouch();
			
			if (start.isPressed(this->touch_x, this->touch_y))
			{
				start.removeButton(this->lcd);
				highscores.removeButton(this->lcd);
				help.removeButton(this->lcd);
				removeLastTouch();
				this->main_screen = 0;
				this->start_game = 1;
				
			}
			else if (highscores.isPressed(this->touch_x, this->touch_y))
			{
				start.removeButton(this->lcd);
				highscores.removeButton(this->lcd);
				help.removeButton(this->lcd);
				removeLastTouch();
				this->main_screen = 0;
				this->highcore_screen = 1;
				
			}
			else if (help.isPressed(this->touch_x, this->touch_y))
			{
				start.removeButton(this->lcd);
				highscores.removeButton(this->lcd);
				help.removeButton(this->lcd);
				removeLastTouch();
				this->main_screen = 0;
				this->help_screen = 1;
				
			}
		}
	}
	/**
	* Run the game
	*/	
	else if(this->start_game)
	{
		Button back = Button(0,10, "back");
		back.drawButton(this->lcd);
		
		while(this->start_game)
		{
			updateTouch();
			
			if (back.isPressed(this->touch_x, this->touch_y))
			{
				back.removeButton(this->lcd);
				removeLastTouch();
				this->start_game = 0;
				this->main_screen = 1;
			}
		}
	}
	/**
	* Run the highscore screen
	*/	
	else if(this->highcore_screen)
	{
		Button back = Button(0,10, "back");
		back.drawButton(this->lcd);		
		
		while(this->highcore_screen)
		{
			updateTouch();
			
			if (back.isPressed(this->touch_x, this->touch_y))
			{
				back.removeButton(this->lcd);							
				removeLastTouch();
				this->highcore_screen = 0;
				this->main_screen = 1;			
			}
		}
	}
	/**
	* Run the help screen
	*/	
	else if(this->help_screen)
	{
		Button back = Button(100, "back");
		back.drawButton(this->lcd);
		
		
		while(this->help_screen)
		{
			updateTouch();
			
			if (back.isPressed(this->touch_x, this->touch_y))
			{
				back.removeButton(this->lcd);
				removeLastTouch();
				this->help_screen = 0;
				this->main_screen = 1;
			}
		}
	}
}

void Game::updateTouch()
{
	this->lcd.touchRead();
	this->touch_x = this->lcd.touchX();
	this->touch_y = this->lcd.touchY();
}

void Game::removeLastTouch()
{
	this->touch_x = 1000;
	this->touch_y = 1000;
}

//
//void Game::MainMenu()
//{
	//this->running = 0;
		//
	//Button start = Button(40, "Start");
	//Button highscores = Button(100, "Highscores");
	//Button help = Button(160, "Help");
	//
	//start.drawButton(lcd);
	//highscores.drawButton(lcd);
	//help.drawButton(lcd);
	//
	//this->running = 1;
	//
	//while(this->running)
	//{
		//lcd.touchRead();		
		//
		//if (start.isPressed(lcd.touchX(),lcd.touchY()))
		//{
			////this->lcd.drawChar(0,0,'a',RGB(0,0,0),RGB(153,204,255),2);
			//Start();
			//
		//}
		//if (highscores.isPressed(lcd.touchX(),lcd.touchY()))
		//{
			////this->lcd.drawChar(0,0,'b',RGB(0,0,0),RGB(153,204,255),2);
			//Highscores();
		//}
		//if (help.isPressed(lcd.touchX(),lcd.touchY()))
		//{
			////this->lcd.drawChar(0,0,'c',RGB(0,0,0),RGB(153,204,255),2);
			//Help();
		//}
	//}
	//
//}
//
//void Game::Start()
//{
	//this->running = 0;
		//
	//Button back = Button(10,10, "back");
	//back.drawButton(lcd);
	//
	//this->running = 1;
	//
	//while(this->running)
	//{
		//lcd.touchRead();
				//
		//if (back.isPressed(lcd.touchX(),lcd.touchY()))
		//{
			//MainMenu();
		//}
	//}
//}
//
//void Game::Highscores()
//{
	//this->running = 0;
		//
	//Button back = Button(10,10, "back");
	//back.drawButton(lcd);
	//
	//this->running = 1;
	//
	//while(this->running)
	//{
		//lcd.touchRead();
				//
		//if (back.isPressed(lcd.touchX(),lcd.touchY()))
		//{
			//MainMenu();
		//}
	//}
//}
//
//void Game::Help()
//{
	//this->running = 0;
		//
	//Button back = Button(10,10, "back");
	//back.drawButton(lcd);
	//
	//this->running = 1;
	//
	//while(this->running)
	//{
		//lcd.touchRead();
				//
		//if (back.isPressed(lcd.touchX(),lcd.touchY()))
		//{
			//MainMenu();
		//}
	//}
//}




