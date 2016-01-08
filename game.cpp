// game.cpp

#include "game.h"
#include <MI0283QT9.h>
#include "button.h"
#include "ArduinoNunchuk.h"
#include "gamefield.h"
#include "highscore.h"
#include "selector.h"

#define WHITE RGB(255,255,255)
#define BLACK RGB(0,0,0)
#define LIGHT_BLUE RGB(153,204,255)
#define DARK_BLUE RGB(0,128,255)
#define GREEN RGB(100, 240, 20)
#define ORANGE RGB(240, 100, 20)
#define GRAY RGB(160, 160, 160)
#define YELLOW RGB(255, 196, 0)

volatile uint16_t teller = 0;
volatile uint32_t seconds = 0;

ISR(TIMER2_OVF_vect) {
	teller++;
	if ( teller >= 300)
	{
		seconds++;
		teller = 0;
	}
}

void Game::init(MI0283QT9 lcd_p)
{
	lcd = &lcd_p;
	touch_x = 0;
	touch_y = 0;
	screen_brightness = 50;
	lcd->led(screen_brightness);
	main_screen = 1;
	start_game = 0;
	highcore_screen = 0;
	settings_screen = 0;
	help_screen = 0;
	TCCR2B |= (1 << CS22) | (1<<CS20);
	TIMSK2 |= (1<<TOIE2);
	TCNT2 = 0;
	sei();
	game_highscores.init();
}
	

void Game::run()
{
	
	/**
	* Run the main menu 
	*/	
	if(main_screen)
	{
		removeLastTouch();
		
		lcd->fillScreen(LIGHT_BLUE);	
		Button start = Button(30, "Start");
		Button highscores = Button(85, "Highscores");
		Button settings = Button(140, "Settings");
		Button help = Button(195, "Help");
		
		start.drawButton(lcd);
		highscores.drawButton(lcd);
		settings.drawButton(lcd);
		help.drawButton(lcd);	
				
		while(main_screen)
		{			
			updateTouch();
			
			if (start.isPressed(touch_x, touch_y))
			{
				start.removeButton(lcd);
				highscores.removeButton(lcd);
				settings.removeButton(lcd);
				help.removeButton(lcd);
				removeLastTouch();
				main_screen = 0;
				start_game = 1;
				
			}
			else if (highscores.isPressed(touch_x, touch_y))
			{
				start.removeButton(lcd);
				highscores.removeButton(lcd);
				settings.removeButton(lcd);
				help.removeButton(lcd);
				removeLastTouch();
				main_screen = 0;
				highcore_screen = 1;
				
			}
			else if (settings.isPressed(touch_x, touch_y))
			{
				start.removeButton(lcd);
				highscores.removeButton(lcd);
				settings.removeButton(lcd);
				help.removeButton(lcd);
				removeLastTouch();
				main_screen = 0;
				settings_screen = 1;
				
			}
			else if (help.isPressed(touch_x, touch_y))
			{
				start.removeButton(lcd);
				highscores.removeButton(lcd);
				settings.removeButton(lcd);
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
		uint8_t gameover = 0;
		seconds = 0;
		removeLastTouch();
		nunchuk = ArduinoNunchuk();
		nunchuk.init();
		nunchuk.update();
		randomSeed(nunchuk.accelX + nunchuk.accelY + nunchuk.accelZ);
		field.Init(lcd, nunchuk);
		field.StartRoad();
		field.SetTimer(0);
		field.SetHS(game_highscores.getHighscore(1).score);
		
		while(start_game)
		{
			field.Generate();
			field.SetTimer(seconds);

			if (field.CheckGame())
			{
				start_game = 0;
				quittime = seconds;
				gameover = 1;
			}
			if (nunchuk.zButton)
			{
				pauseteller = teller;
				pauseseconds = seconds;
				uint8_t pause1 = 1;
				uint8_t pause2 = 0;
				lcd->drawText(80, 45, "Pause", WHITE, LIGHT_BLUE, 4);
				
				while(pause1)
				{
					nunchuk.update();
					if (!nunchuk.zButton)
					{
						pause2 = 1;
						pause1 = 0;
					}
				}
				
				while(pause2)
				{
					nunchuk.update();
					if (nunchuk.zButton)
					{
						teller = pauseteller;
						seconds = pauseseconds;
						pause2 = 0;
					}
				}
				
				uint8_t pos = field.GetPos()[1];
				
				lcd->fillRect(0, 40, pos * 10 + 10, 40, GREEN);
				lcd->fillRect(pos * 10 + 10, 40, 10, 40, ORANGE);
				lcd->fillRect(pos * 10 + 20, 40, 120, 40, GRAY);
				lcd->fillRect(pos * 10 + 140, 40, 10, 40, ORANGE);
				lcd->fillRect(pos * 10 + 150, 40, 320 - (pos * 10 + 150), 40, GREEN);
			}
		}
		if (game_highscores.checkIfHighscore(quittime))
		{
			lcd->fillScreen(LIGHT_BLUE);
			
			lcd->drawText(20, 20, "New highscore!", WHITE, LIGHT_BLUE, 2);
			lcd->drawText(20, 40, "Score:", WHITE, LIGHT_BLUE, 2);
			lcd->drawInteger(120,40,quittime,DEC, WHITE, LIGHT_BLUE, 2);
			
			Selector char1 = Selector(lcd,20,90,0);
			Selector char2 = Selector(lcd,80,90,1);
			Selector char3 = Selector(lcd,140,90,1);
			Selector char4 = Selector(lcd,200,90,1);
			Selector char5 = Selector(lcd,260,90,1);
			
			Button add = Button(200, "Done");
			add.drawButton(lcd);
			
			while(gameover)
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
					
					game_highscores.addHighscore(quittime,s);
					removeLastTouch();
					gameover = 0;
					main_screen = 1;
				}
			}
		}
		else
		{
			lcd->drawText(20, 40, "Game over", WHITE, LIGHT_BLUE, 4);
			lcd->drawText(105, 80, "Score:", WHITE, LIGHT_BLUE, 2);
			lcd->drawInteger(200,80,quittime,DEC, WHITE, LIGHT_BLUE, 2);
			
			Button back = Button(200, "back");
			back.drawButton(lcd);
			
			while(gameover)
			{
				updateTouch();
				
				if (back.isPressed(touch_x, touch_y))
				{
					removeLastTouch();
					gameover = 0;
					main_screen = 1;
				}
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
	* Run the settings screen
	*/	
	else if(settings_screen)
	{
		Button back = Button(200, "back");
		back.drawButton(lcd);
		
		lcd->drawText(20,20,"Highscores: ",WHITE,LIGHT_BLUE,2);
		
		highscore copy_of_first_highscore = game_highscores.getHighscore(1);
		Button delete_highscores = Button(20,60,"delete");
		
		if (copy_of_first_highscore.score)
		{			
			delete_highscores.drawButton(lcd);
		}
		else
		{
			lcd->drawText(20,60,"No highscores.",WHITE,LIGHT_BLUE,2);
		}
		
		
		lcd->drawText(20,100,"Screen brightness: ",WHITE,LIGHT_BLUE,2);
		
		Button niv_1 = Button(20,140,"1");
		niv_1.drawButton(lcd);
		
		Button niv_2 = Button(70,140,"2");
		niv_2.drawButton(lcd);
		
		Button niv_3 = Button(120,140,"3");
		niv_3.drawButton(lcd);
		
		Button niv_4 = Button(170,140,"4");
		niv_4.drawButton(lcd);
				
		while(settings_screen)
		{
			updateTouch();
			
			if (delete_highscores.isPressed(touch_x,touch_y))
			{
				if (copy_of_first_highscore.score)
				{
					game_highscores.resetHighscores();
					delete_highscores.removeButton(lcd);
					lcd->drawText(20,60,"No highscores.",WHITE,LIGHT_BLUE,2);
					removeLastTouch();
				}
			}
			if (niv_1.isPressed(touch_x,touch_y))
			{				
				screen_brightness  = 25;
				lcd->led(screen_brightness);
				removeLastTouch();				
			}
			if (niv_2.isPressed(touch_x,touch_y))
			{
				screen_brightness = 50;
				lcd->led(screen_brightness);
				removeLastTouch();		
			}
			if (niv_3.isPressed(touch_x,touch_y))
			{
				screen_brightness = 75;
				lcd->led(screen_brightness);
				removeLastTouch();
			}
			if (niv_4.isPressed(touch_x,touch_y))
			{
				screen_brightness = 100;
				lcd->led(screen_brightness);
				removeLastTouch();
			}			
			if (back.isPressed(touch_x, touch_y))
			{
				removeLastTouch();
				settings_screen = 0;
				main_screen = 1;
			}	
			
		}
	}
	/**
	* Run the help screen
	*/	
	else if(help_screen)
	{
		uint8_t help1 = 1;
		uint8_t help2 = 0;
		
		Button back = Button(200, "back");
		back.drawButton(lcd);
		
		if (help1)
		{
			lcd->fillRect(0, 0, 320, 180, LIGHT_BLUE);
			uint8_t help_1 = 1;
			
			Button next = Button(240, 200, ">>");
			next.drawButton(lcd);
			
			String helptext[] = {"GoFast is a game where you have to","stay on the road as long as possible.","If the car touches the red line it's","game over. While playing, obstacles",
			"will appear on the road which become","more frequent over time. You control","the car with the nunchuk joystick."};
			
			int y = 15;
			for (int i = 0; i < 7; i++)
			{
				lcd->drawText(15, y, helptext[i], WHITE, LIGHT_BLUE, 1);
				y += 10;
			}
			
			lcd->drawText(15, 110, "Controls:", WHITE, LIGHT_BLUE, 1);
			lcd->drawText(15, 130, "Joystick left  = Move car to the left", WHITE, LIGHT_BLUE, 1);
			lcd->drawText(15, 145, "Joystick right = Move car to the right", WHITE, LIGHT_BLUE, 1);
			lcd->drawText(15, 160, "Z button       = Pause game", WHITE, LIGHT_BLUE, 1);
			
			
			while(help1)
			{
				updateTouch();
				
				if (next.isPressed(touch_x, touch_y))
				{
					next.removeButton(lcd);
					removeLastTouch();
					help1 = 0;
					help2 = 1;
				}
				if (back.isPressed(touch_x, touch_y))
				{
					next.removeButton(lcd);
					back.drawButton(lcd);
					removeLastTouch();
					help1 = 0;
					help_screen = 0;
					main_screen = 1;
				}
			}
		}
		
		if (help2)
		{
			lcd->fillRect(0, 0, 320, 180, LIGHT_BLUE);
			uint8_t help_2 = 1;
			
			Button prev = Button(10, 200, "<<");
			prev.drawButton(lcd);
			
			lcd->drawText(20, 15, "Obstacles:", WHITE, LIGHT_BLUE, 1);
			
			//Arrow down
			lcd->fillTriangle(20, 50, 40, 50, 30, 60, YELLOW);
			lcd->fillRect(27, 40, 6, 10, YELLOW);
			
			//Arrow up
			lcd->fillTriangle(20, 88, 40, 88, 30, 78, YELLOW);
			lcd->fillRect(27, 88, 6, 10, YELLOW);
			
			//Double arrow
			lcd->fillTriangle(26, 122, 19, 127, 26, 132, YELLOW);
			lcd->fillRect(26, 126, 7, 3, YELLOW);
			lcd->fillTriangle(33, 122, 40, 127, 33, 132, YELLOW);
			
			//Block
			lcd->fillRect(20, 158, 20, 20, YELLOW);
			
			lcd->drawText(50, 45, "= Car moves down", WHITE, LIGHT_BLUE, 1);
			lcd->drawText(50, 85, "= Car moves up", WHITE, LIGHT_BLUE, 1);
			lcd->drawText(50, 125, "= Reverse steering", WHITE, LIGHT_BLUE, 1);
			lcd->drawText(50, 165, "= Game over", WHITE, LIGHT_BLUE, 1);
			
			while(help2)
			{
				updateTouch();
				
				if (prev.isPressed(touch_x, touch_y))
				{
					prev.removeButton(lcd);
					removeLastTouch();
					help2 = 0;
					help1 = 1;
				}
				if (back.isPressed(touch_x, touch_y))
				{
					prev.removeButton(lcd);
					back.drawButton(lcd);
					removeLastTouch();
					help2 = 0;
					help_screen = 0;
					main_screen = 1;
				}
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