// highscore.h

#ifndef _HIGHSCORE_h
#define _HIGHSCORE_h

#include <avr/io.h>

typedef struct
{
	uint8_t position;
	uint16_t score;
	char name[6];
}highscore;

class Highscore
{
	
	public:
		
		/**
		 * Constructs a Highscore object
		 * 
		 * @param *eeprom_array A pointer to an array in the Arduino's EEPROM
		 */	
		void init(/*uint16_t adress1, uint16_t adress2, uint16_t adress3*/);
		
		void resetHighscores();
				
		//void saveHighscore(highscore highscore, uint16_t *address);
		
		/**
		 * Get access to the highscore array
		 * 
		 * @param a pointer to the highscore_array variable
		 */	
		highscore getHighscore(uint8_t highscore_number);
		
		/**
		 * Add a new highscore
		 *
		 * @param index The index of the array to put the score in
		 * @param score A value to save as a highscore
		 */	
				
		uint8_t checkIfHighscore(uint8_t score);
		
		void addHighscore(uint8_t score, char name[6]);
		
		highscore *highscore_to_change;
		
		
	private:
		highscore highscore_1;
		highscore highscore_2;
		highscore highscore_3;
		int adress_1;
		int adress_2;
		int adress_3;
		
		void refreshLocalHighscores();
		
		void saveToEeprom(uint8_t highscore_number);
};

#endif

