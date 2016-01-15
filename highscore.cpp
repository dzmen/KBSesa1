#include "highscore.h"
#include <string.h>
#include <avr/eeprom.h>

void Highscore::init()
{
	adress_1 = 10;
	
	refreshLocalHighscores();
}

void Highscore::resetHighscores()
{
	highscore_1.position = 1;
	highscore_1.score = 0;
	strcpy(highscore_1.name,"");
	
	highscore_2.position = 2;
	highscore_2.score = 0;
	strcpy(highscore_1.name,"");
	
	highscore_3.position = 3;
	highscore_3.score = 0;
	strcpy(highscore_1.name,"");
	saveToEeprom();
}

void Highscore::refreshLocalHighscores()
{
	eeprom_read_block((void*)&eeprom_array,(void*)adress_1,sizeof(eeprom_array));
	highscore_1 = eeprom_array[0];
	highscore_2 = eeprom_array[1];
	highscore_3 = eeprom_array[2];
}
void Highscore::saveToEeprom()
{
	eeprom_array[0] = highscore_1;
	eeprom_array[1] = highscore_2;
	eeprom_array[2] = highscore_3;
	eeprom_write_block((void*)&eeprom_array,(void*)adress_1,sizeof(eeprom_array));
}

highscore Highscore::getHighscore(uint8_t highscore_number)
{
	switch (highscore_number)
	{
		case 1:
			return highscore_1;
			break;
		case 2:
			return highscore_2;
			break;
		case 3:
			return highscore_3;
			break;
	}
}

uint16_t Highscore::checkIfHighscore(uint16_t score)
{
	if (score > highscore_1.score)
	{
		highscore_to_change = &highscore_1;
		return 1;
	}
	else if (score > highscore_2.score)
	{
		highscore_to_change = &highscore_2;
		return 1;
	}
	else if (score > highscore_3.score)
	{
		highscore_to_change = &highscore_3;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Highscore::addHighscore(uint16_t score, char name[6])
{
	if (highscore_to_change->position == 1)
	{
		highscore_3.score = highscore_2.score;
		strcpy(highscore_3.name,highscore_2.name);
		
		highscore_2.score = highscore_1.score;
		strcpy(highscore_2.name,highscore_1.name);
	}
	else if (highscore_to_change->position == 2)
	{
		highscore_3.score = highscore_2.score;
		strcpy(highscore_3.name,highscore_2.name);
	}
	
	highscore_to_change->score = score;
	strcpy(highscore_to_change->name, name);
	saveToEeprom();
}