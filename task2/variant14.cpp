/**
* @file variant14.cpp
* @brief The source file to the task number 14
*/

#include "variant14.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>

// This function is designed for users input data on tests
bool InputTests ( test *arrTest )
{
	bool breakInput = false;
	if(arrTest == NULL)
	{
		return false;
	}
	test *tmp = new test;
	if(tmp == NULL)
	{
		return false;
	}

	printf("Enter data for %u test(s):\n\n", LENGTH_ARR_OF_TESTS);
	for(UCH i = 0; i < LENGTH_ARR_OF_TESTS && breakInput == false; ++i)
	{
		printf("\nEnter quest (max - %u sybmols; 0 or '' - break input):\n", LENGTH_OF_QUEST - 1);
		fflush(stdin);
		fgets((char*)(tmp->quest), LENGTH_OF_QUEST - 1, stdin);
		if( (tmp->quest[0] == '0' ) || (tmp->quest[0] == '\n') )
		{
			breakInput = true;
			continue;
		}
		UCH *tmpPtr;
		for(UCH j = 0; j < NUMBER_ANSWERS && breakInput == false; ++j)
		{
			printf("Enter answer #%u (max - %u sybmols; 0 or '' - break input):\n", j + 1, LENGTH_OF_ANSWER - 1);
			fflush(stdin);
			tmpPtr = tmp->answers + j * LENGTH_OF_ANSWER;
			fgets((char*)(tmpPtr), LENGTH_OF_QUEST - 1, stdin);
			if( (tmpPtr[0] == '0' ) || (tmpPtr[0] == '\n') )
			{
				breakInput = true;
				continue;
			}
		}
		if(breakInput == true)
		{
			continue;
		}
		printf("Enter the number of correct answers [1..%u]: ", NUMBER_ANSWERS);

		short x;
		fflush(stdin);
		while ( !( scanf_s("%hd", &x) && ( (x == 0) || (x >= 1 && x <= NUMBER_ANSWERS) ) ) )
		{
			printf("Incorrectly input data! Please enter again (0 - break unput): ");
			fflush(stdin); // resets the buffer
		}
		if(x == 0)
		{
			breakInput = true;
			continue;
		}
		else
		{
			tmp->correctAnswer =  (UCH)x;
		}
		tmp->checked = false;

		memcpy((arrTest + i), tmp, sizeof(test));
	}	// End of for i
	delete tmp;
	return !breakInput;
}

// This function provides the user testing
void Testing ( test *arrTest )
{
	UCH index; // index term for testing
	bool breakInput = false;
	srand(time(0));
	test *tmpPtr;
	
	for(UCH i = 0; i < NUMBER_OF_TESTS && breakInput == false; ++i)
	{
		index = (UCH)(rand() % LENGTH_ARR_OF_TESTS);
		while((arrTest + index)->checked == true) // while not found unused term
		{
			index = (UCH)(rand() % LENGTH_ARR_OF_TESTS);
		}
		tmpPtr = arrTest + index;
		tmpPtr->checked = true;

		printf("---------------------------------------------------------------\n");
		printf("Quest: %s", tmpPtr->quest);
		for(UCH j = 0; j < NUMBER_ANSWERS; ++j)
		{
			printf("\tAnswer #%u: %s", j + 1, (tmpPtr->answers + j * LENGTH_OF_ANSWER) );
		}
		printf("Enter the number of correct answer (0 - break input): ");
		short x;
		fflush(stdin);
		while ( !( scanf_s("%hd", &x) && (x >= 1 && x <= NUMBER_ANSWERS ) ) )
		{
			printf("Incorrectly input data! Please enter again (0 - break input): ");
			fflush(stdin); // resets the buffer
		}
		if(x == 0)
		{
			breakInput == true;
			continue;
		}
		if(tmpPtr->correctAnswer == (UCH)(x))
		{
			printf("Correctly\n");
		}
		else
		{
			printf("Incorrectly\n");
		}
	} // End of for i
}