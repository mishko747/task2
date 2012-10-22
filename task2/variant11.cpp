/**
* @file variant11.cpp
* @brief The source file to the task number 11
*/

#include "variant11.h"

#include <stdio.h>	// for printf() and scanf()
#include <string.h> // for strcmp()

// This function displays information about students
void PrintInfoAboutStudents ( student *stud )
{
	student* tmpPtr;
	
	printf("Surname\tName\tEvaluation\n");
	for(int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		tmpPtr = stud + i;
		printf("%s\t%s\t", tmpPtr->surname, tmpPtr->name);

		for(int j = 0; j < NUMBER_OF_EVALUATIONS; j++)
		{
			printf("%u ", ( tmpPtr->eval >> (j * 3) ) & 7U); 
			// on the value tmpPtr->eval is imposed mask for every 3 bits
		}
		printf("\n");
	}
}

// This function sorts the students by surname
void SortStudents ( student *stud )
{
	student tmpStud;
	// sorting under the algorithm bubble
	for(int i = NUMBER_OF_STUDENTS - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(strcmp((stud + j)->surname, (stud + j + 1)->surname) > 0)
			{
				tmpStud = *(stud + j);
				*(stud + j) = *(stud + j + 1);
				*(stud + j + 1) = tmpStud;
			}
		}	// End of for j
	}	// End of for i
}

// This function counts the average rating
float AVGOfEval(unsigned short value)
{
	unsigned short sum = 0;
	for(int i = 0; i < NUMBER_OF_EVALUATIONS; i++)
	{
		sum += ( value >> (i * 3) ) & 7U;
		// on the value tmpPtr->eval is imposed mask for every 3 bits
	}

	return sum / (float) NUMBER_OF_EVALUATIONS;
}

// This function displays information about the two best students from the list
void PrintBestStudents ( student *stud )
{
	unsigned short firstStud = NUMBER_OF_STUDENTS - 1;	// best student final in the list
	unsigned short secondStud = firstStud;	// second student final in the list

	float *arrAVG = new float[NUMBER_OF_STUDENTS];

	// calculating of the average score for each student
	for(int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		*(arrAVG + i) = AVGOfEval(stud[i].eval);
		// if the average score of student is bigger than the average score of the best students
		if( *(arrAVG + i) > *(arrAVG + firstStud) )
		{
			firstStud = i;	//best student
		}
	}

	*(arrAVG + firstStud) -= 5;	// rating downgrade
	
	for(int i = 0; i < NUMBER_OF_STUDENTS; i++)
	{
		if( *(arrAVG + i) > *(arrAVG + secondStud) )
		{
			secondStud = i;
		}
	}

	printf("\nStudent(s) from the best rated:\n");
	printf("\t%s\t %s\t %.2f\n", (stud + firstStud)->surname, (stud + firstStud)->name, *(arrAVG + firstStud) + 5);

	if(firstStud != secondStud)	// if there is a student with a lower rated
	{
		printf("\t%s\t %s\t %.2f\n", (stud + secondStud)->surname, (stud + secondStud)->name, *(arrAVG + secondStud));
	}
}