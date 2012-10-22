/**
* @file variant9.cpp
* @brief The source file to the task number 9
*/

#include "variant9.h"

#include <stdio.h>	// for printf() and scanf()
#include <stdlib.h> // for srand() and rand()
#include <string.h>	// for strcmp()
#include <ctime>	// for time()

//	This function holding testing the user and displays the result
float UserTesting ( term *termArray, unsigned short countTests )
{
	unsigned short index; // index term for testing
	char enteredWord[WORD_LENGTH];
	unsigned short countOfCorrectAnswers = 0;
	srand(time(0));
	
	for(int i = 0; i < countTests; i++)
	{
		index = rand() % TERM_LENGTH;
		while(termArray[index].checked == true) // while not found unused term
		{
			index = rand() % TERM_LENGTH;
		}
		termArray[index].checked = true;

		printf("---------------------------------------------------------------\n");
		printf("Please enter the translation of the word: %s\n", termArray[index].original);
		printf("Translation: "); scanf("%s", &enteredWord);

		// if the translation from a dictionary is identical entered word
		if(strcmp(termArray[index].transl, enteredWord) == 0)
		{
			countOfCorrectAnswers++;
			printf("Correctly\n");
		}
		else
		{
			printf("Incorrectly\n");
		} // End of if
	} // End of for

	if(countOfCorrectAnswers == 0) return 0;
	return ((float)countOfCorrectAnswers / (float)countTests) * 100.0 ;
}
