// highscore.cpp
// 
// 

#include "highscore.h"
#include <avr/eeprom.h>
#include <string.h>
#include "EEPROMAnything.h"

void Highscore::init(/*uint16_t adress1, uint16_t adress2, uint16_t adress3*/)
{
	resetHighscores();
	//highscore1_address = &adress1;
	//highscore2_address = &adress2;
	//highscore3_address = &adress3;
	//
	//resetHighscores();
	//
	//saveHighscore(highscore_1, highscore1_address);
	//saveHighscore(highscore_2, highscore2_address);
	//saveHighscore(highscore_3, highscore3_address);
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
}
//
//void Highscore::refreshHighscore(highscore highscore, uint16_t *address) //alles refreshen, geen vaiablen meer
//{
	//EEPROM_readAnything((int)address,highscore);
	////highscore.name;
	////eeprom_read_block((void*)&highscore.name, (void*)address, sizeof(highscore));
	////highscore.score;
	////eeprom_read_block((void*)&highscore.score, (void*)address, sizeof(highscore));
//}
//
//void Highscore::saveHighscore(highscore highscore, uint16_t *address)
//{
	//EEPROM_writeAnything((int)address,highscore);
	////eeprom_write_block((const void*)&highscore, (void*)address, sizeof(highscore)); // hierondre bij doen
//}

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


//void Highscore::compareScore(uint8_t score, char* name) //herzien
//{
	////if (score > highscore_1.score)
	////{
		////addHighscore(highscore_1, score, name, highscore1_address);
	////} 
	////else if (score > highscore_2.score)
	////{
		////addHighscore(highscore_2, score, name, highscore2_address);
	////}
	////else if (score > highscore_3.score)
	////{
		////addHighscore(highscore_3, score, name, highscore3_address);
	////}
//}

//void Highscore::tijd()
//{
	//highscore_1.score = 10;
	//strcpy(highscore_1.name, "jan");
	//saveHighscore(highscore_1, highscore1_address);
	//
	//refreshHighscore(highscore_1, highscore1_address);
//}
//
//void Highscore::test1()
//{
	//highscore_1.score = 500;
	//strcpy(highscore_1.name, "wilco");
	//
	//highscore_2.score = 250;
	//strcpy(highscore_2.name, "jan");
	//
	//highscore_3.score = 20;
	//strcpy(highscore_3.name, "ik");
//}

uint8_t Highscore::checkIfHighscore(uint8_t score)
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

void Highscore::addHighscore(uint8_t score, char name[6])
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
	
}