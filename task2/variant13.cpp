/**
* @file variant13.h
* @brief The header file to the task number 13
*/

#include "variant13.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <mbstring.h>

// This function checks the correctness of the input numbers in the range [0 .. 255]
UCH ProtectionInputUChar ( UCH min, UCH max )
{
	short x;
	fflush(stdin);
	while ( !( scanf_s("%hd", &x) && ( (x == 0) || (x >= min && x <= max) ) ) )
	{
		printf("Incorrectly input data! Please enter again (0 - break unput): ");
		fflush(stdin); // resets the buffer
	}
	return (UCH)x;
}

// This function is designed for users input data on students
bool InputDataMedStudents ( medStudent *mStud )
{
	bool breakInput = false;
	if(mStud == NULL)
	{
		return false;
	}
	medStudent *tmp = new medStudent;
	if(tmp == NULL)
	{
		return false;
	}

	printf("Enter data for medical examination %u students:\n\n", NUMBER_MED_STUDENTS);
	for(UCH i = 0; i < NUMBER_MED_STUDENTS && breakInput == false; ++i)
	{
		printf("Enter name and initials (max - %u sybmols; 0 or ' ' - break input):\n", LENGTH_OF_NAME);
		fflush(stdin);
		fgets((char*)(tmp->name), LENGTH_OF_NAME, stdin);
		if( (tmp->name[0] == '0' ) || (tmp->name[0] == '\n') )
		{
			breakInput = true;
			continue;
		}

		printf("Enter the years ([1..127]; 0 - break input): ");
		tmp->years = ProtectionInputUChar(1, 127);
		BREAK_INPUT(tmp->years);
		
		printf("Enter the gender (1 - man, 2 - women; 0 - break input): ");
		tmp->gender = ProtectionInputUChar(1, 2) - 1;
		BREAK_INPUT(tmp->gender + 1);

		printf("Enter the height ([1..255]; 0 - break input): ");
		tmp->height = ProtectionInputUChar(1, 255);
		BREAK_INPUT(tmp->height);

		printf("Enter the weight ([1..255]; 0 - break input): ");
		tmp->weight = ProtectionInputUChar(1, 255);
		BREAK_INPUT(tmp->weight);

		memcpy((mStud + i), tmp, sizeof(medStudent));
	}	// End of for i
	delete tmp;
	return !breakInput;
}

// This function is for sort the records on students by name
bool SotrStudents ( medStudent *mStud )
{
	if(mStud == NULL) 
	{
			return false;
	}
	medStudent *tmp = new medStudent;
	if(tmp == NULL) 
	{
		return false;
	}
	// sorting under the algorithm bubble
	for(UCH i = NUMBER_MED_STUDENTS - 1; i > 0; --i)
	{
		for(UCH j = 0; j < i; ++j)
		{
			if(_mbscmp( (mStud + j)->name, (mStud + j + 1)->name) > 0)
			{
				*tmp = *(mStud + j);
				*(mStud + j) = *(mStud + j + 1);
				*(mStud + j + 1) = *tmp;
			}
		}	// End of for j
	}	// End of for i
	
	delete tmp;
	return true;
}

// This aunction displays th average values of height and weight of students
// (separately for girls and bous separately)
bool PrintHeightWeightAWG ( medStudent *mStud )
{
	if(mStud == NULL) 
	{
		return false;
	}
	UCH *arr = new UCH[2 * 3];
	memset(arr, 0, 2 * 3 * sizeof(UCH));
	if(arr == NULL) 
	{
		return false;
	}

	for(UCH i = 0; i < NUMBER_MED_STUDENTS; ++i)
	{
		if((mStud + i)->gender == 1)
		{
			*(arr + 3 + 0) += 1; 
			*(arr + 3 + 1) += (mStud + i)->height;
			*(arr + 3 + 2) += (mStud + i)->weight;
		}
		else
		{
			*(arr + 0) += 1; 
			*(arr + 1) += (mStud + i)->height;
			*(arr + 2) += (mStud + i)->weight;
		}
	}
	printf("-----------------------------------------------\n");
	if(*(arr + 0) != 0)
	{
		printf("Average height in boys	: %.2f\n", *(arr + 1) / (float)*(arr + 0));
		printf("Average weight in boys	: %.2f\n", *(arr + 2) / (float)*(arr + 0));
	}
	else
	{
		printf("Boys not in the list.\n");
	}

	if(*(arr + 3) != 0)
	{
		printf("Average height in girls	: %.2f\n", *(arr + 3 + 1) / (float)*(arr + 3 + 0) );
		printf("Average weight in girls	: %.2f\n", *(arr + 3 + 2) / (float)*(arr + 3 + 0) );	
	}
	else
	{
		printf("Girls not in the list.\n");
	}

	delete arr;
	return true;
}

// This function displays a list of data on students in a table
void PrintDataOfStudents ( medStudent *mStud )
{
	if(mStud == NULL)
	{
		printf("Error output!");
		return;
	}

	UCH iter;
	printf("Surname and initials\t Years\t Gender\t Height\t Weight\n");
	for(UCH i = 0; i < NUMBER_MED_STUDENTS; ++i)
	{
		iter = 1;
		while((mStud + i)->name[iter] != '\n' && iter < LENGTH_OF_NAME)
		{
			iter++;
		}
		if(iter != LENGTH_OF_NAME)
		{
			(mStud + i)->name[iter] = '\0';
		}
		printf("%-20s\t %u\t %s\t %u\t %u\n", (mStud + i)->name, (mStud + i)->years, (mStud + i)->gender ? "girl" : "boy",  (mStud + i)->height, (mStud + i)->weight);
	}
}