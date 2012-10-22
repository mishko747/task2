/**
* @file task2.cpp
* @brief Source file of project 
*/

#include "task2.h"

#include <iostream>
#include <stdio.h>
#include <ctime>	// for time()

//	This function checks the correctness of the data entered by the user
unsigned short ProtectionInput ( unsigned short minValue, unsigned short maxValue )
{
	long x;
	while (!scanf_s("%ld", &x) || (x < minValue || x > maxValue) )
	{
		fflush(stdin); // resets the buffer
		printf("Error! Incorrectly input data!\n");
		printf("Please enter the number once again: ");
	}
	return (unsigned short)x;
}

void main ( void )
{
	unsigned short option;
	while(true)
	{
		printf ("1  - Task number 9\n");
		printf ("2  - Task number 10\n");
		printf ("3  - Task number 11\n");
		printf ("4  - Task number 12\n");
		printf ("5  - Task number 13\n");
		printf ("6  - Task number 14\n");
		printf ("7  - Task number 15\n");
		printf ("0  - Exit;\n");
		printf ("Enter the number of action please: ");
		option = ProtectionInput(0, 7);

		switch(option)
		{
			case 1:
			// Task number 9
			{
				float resTest;	// test result
				unsigned short testCount;	// number of tests
				term *termArray = new term[TERM_LENGTH];

				printf("Please enter a word and its translation:\n");
				for(int i = 0; i < TERM_LENGTH; i++)
				{
					scanf("%s %s", termArray[i].original, termArray[i].transl);
					termArray[i].checked = false;
				}

				system("cls");

				printf("Please enter a number of tests: "); 
				testCount = ProtectionInput(1, TERM_LENGTH);
				resTest = UserTesting(termArray, testCount);
				printf("\nPercentage of correct answers: %.2f%%\n", resTest);

				delete termArray;
				break;
			}
			case 2:
			// Task number 10
			{
				car *arrOfCars = new car[NUMBER_OF_CARS];

				for(int i = 0; i < NUMBER_OF_CARS; i++)
				{
					printf("\nEnter brand and number about the car	: ");
					scanf("%s %s", arrOfCars[i].brand, arrOfCars[i].number);
					printf("Enter year of production about the car	: ");
					arrOfCars[i].year = ProtectionInput(0, 2012);
					printf("Enter milleage about the car		: ");
					arrOfCars[i].mileage = ProtectionInput(0, USHRT_MAX);
				}

				SortCarsOfYear(arrOfCars);
				
				printf("\nBrand \tNumber \tYear \tMilleage\n");
				for(int i = 0; i < NUMBER_OF_CARS; i++)
					printf("%s\t %s\t %u\t %u\n",  arrOfCars[i].brand, arrOfCars[i].number, arrOfCars[i].year, arrOfCars[i].mileage);

				PrintAVGMilleage(arrOfCars);

				delete arrOfCars;
				break;
			}
			case 3:
			// Task number 11
			{
				unsigned short tmpValue;

				student *arrOfStud = new student[NUMBER_OF_STUDENTS];

				for(int i = 0; i < NUMBER_OF_STUDENTS; i++)
				{
					arrOfStud[i].eval = 0;

					printf("\nEnter first and last name of student by a space: ");
					scanf("%s %s", arrOfStud[i].surname, arrOfStud[i].name);
					
					printf("\nEnter evaluations: \n"); 
					for(int j = 0; j < NUMBER_OF_EVALUATIONS; j++)
					{
						tmpValue = ProtectionInput(2, 5);
						arrOfStud[i].eval |= tmpValue << (j * 3);
						// on the value tmpPtr->eval is imposed mask for every 3 bits
					}
				}	// End of for i

				PrintInfoAboutStudents(arrOfStud);

				PrintBestStudents(arrOfStud);

				delete arrOfStud;
				break;
			}
			case 4:
			// Task number 12
			{
				screenPoint *arrOfPoint = new screenPoint[NUMBER_OF_POINTS];
				unsigned int tmpValue;

				for(int i = 0; i < NUMBER_OF_POINTS; i++)
				{
					printf("\nEnter x: ");	arrOfPoint[i].x = ProtectionInput(0, 680);	
					printf("Enter y: ");	arrOfPoint[i].y = ProtectionInput(0, 680);	
					printf("Enter Color: "); scanf("%s", arrOfPoint[i].color);
				}
				PrintPoints(arrOfPoint);
				SortByColor(arrOfPoint);
				printf("\n");
				PrintPoints(arrOfPoint);

				SearchLargestDistance(arrOfPoint);
				delete arrOfPoint;
				break;
			}
			case 5:
			// Task number 13
			{
				system("cls");
				medStudent *mStud = new medStudent[NUMBER_MED_STUDENTS];
				if(mStud == NULL)
				{
					printf("Memory allocation error!\n");
					break;
				}

				if( InputDataMedStudents(mStud) == false )
				{
					printf("Data input do not complete.\n");
					delete mStud;
					break;
				}

				PrintDataOfStudents(mStud);

				printf("Sorted by name list of students:\n");
				if(SotrStudents(mStud) == false)
				{
					printf("Sort completed with errors\n");
				}

				PrintDataOfStudents(mStud);

				if(PrintHeightWeightAWG(mStud) == false)
				{
					printf("When calculating averages height and weight error occurred!\n");
				}
				delete mStud;
			}
			break;
			case 6:
			// Task number 14
			{
				system("cls");
				test *arrTest = new test[LENGTH_ARR_OF_TESTS];
				if(arrTest == NULL)
				{
					printf("Memory allocation error!\n");
					break;
				}
				
				if( InputTests(arrTest) == false )
				{
					printf("Data input do not complete.\n");
					delete arrTest;
					break;
				}
				system("cls");
				printf("\t\t*** TESTING ***\n");
				Testing(arrTest);

				delete arrTest;
			}
			break;
			case 7:
			// Task number 15
			{
				Triangle *arrTriangle = new Triangle[NUMBER_OF_TRIANGLE];
				if(arrTriangle == NULL)
				{
					printf("Memory allocation error!\n");
					break;
				}
				system("cls");

				if(InputDataOfTriangle(arrTriangle) == false)
				{
					printf("Error input!\n");
					delete arrTriangle;
					break;
				}
				PrintDataOfTriangle(arrTriangle);

				CalculatePerum(arrTriangle);

				PrintDataOfTriangle(arrTriangle);

				PrintPercentTriangle(arrTriangle);

				delete arrTriangle;
				break;
			}
			default:
				return;
		}	// End of switch(i)
		printf ("Press any key to continue...\n"); 
		_getwch();	// waiting of action
		system("cls");
	}	// End of while(true)
}