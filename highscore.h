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
		
		/**
		 * Copy the array in the EEPROM to a local array for later use
		 * 
		 */	
		//void refreshHighscore(highscore highscore, uint16_t *address);
		
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
		void addHighscore(uint8_t score, char name[6]);
		
		/**
		 * A function to check which highscore needs to be replaced by the given score.
		 * If the given score is not higher than a value in the highscore_array, it's not saved
		 * 
		 * @param score A value to save as highscore
		 */	
		//void compareScore(uint8_t score, char name[6]);
		
		//void tijd();
		
		//void test1();
		
		uint8_t checkIfHighscore(uint8_t score);
		
		highscore *highscore_to_change;
		
	private:
		highscore highscore_1;
		highscore highscore_2;
		highscore highscore_3;
		uint16_t *highscore1_address;
		uint16_t *highscore2_address;
		uint16_t *highscore3_address;
		//unsigned int *eeprom_array;
		//unsigned int highscore_array[3];		
};

#endif

