/**
* @file variant10.h
* @brief The header file to the task number 10
*/

#ifndef VARIANT10_H_
#define VARIANT10_H_

const unsigned short NUMBER_OF_CARS = 3;	// list size of cars

struct totalMilleage	// total mileage for a particular brand
{
	char brand[20];
	unsigned short totalMileage;
	unsigned short numberOfCars;
};

struct car	// information about car
{
	char brand[20];
	char number[10];
	unsigned short year;
	unsigned short mileage;
};

/**
* @brief	This function sorted list of cars of production year
* @param	[in]	arrOfCars Pointer to the structure with a description of car
* @return	void
*/
void SortCarsOfYear ( car *arrOfCars );

/**
* @brief	This function displays the average mileage for each brand
* @param	[in]	arrOfCars Pointer to the structure with a description of car
* @return	void
*/
void PrintAVGMilleage ( car *arrOfCars );

#endif /* VARIANT10_H_ */