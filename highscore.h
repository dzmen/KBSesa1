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
		 */	
		void init();
		
		/**
		 * Set all the Highscores on 0 and empty the name strings
		 */	
		void resetHighscores();
		
		/**
		 * Get access to the highscore array
		 * 
		 * @param highscore_number Choose which highscore you want
		 * @return a highscore struct
		 */	
		highscore getHighscore(uint8_t highscore_number);
		
		/**
		 * Add a new highscore
		 *
		 * @param score A value to save as a highscore
		 * @param name A string to save the users name in
		 * @note if necessary, this function copies the previous highscore to the next one
		 */	
		void addHighscore(uint16_t score, char name[6]);
		
		/**
		 * Get access to the highscore array
		 * 
		 * @param score A score to check if there is a new highscore
		 * @return a 1 if there is a new highscore, 0 if there is not
		 * @note if there is a new highscore, the address is saved to highscore_to_change var for later use
		 */			
		uint16_t checkIfHighscore(uint16_t score);		
		
		highscore *highscore_to_change;		
		
	private:
		highscore highscore_1;
		highscore highscore_2;
		highscore highscore_3;
		int adress_1;
		
		highscore eeprom_array[3];
		
		/**
		 * Copy the highscores from the EEPROM to local variables
		 */	
		void refreshLocalHighscores();
		
		/**
		 * Save the eeprom_array to the EEPROM
		 */	
		void saveToEeprom();
};

#endif

