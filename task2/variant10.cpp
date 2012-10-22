/**
* @file variant10.cpp
* @brief The source file to the task number 10
*/

#include "variant10.h"

#include <string.h>	// for strcmp()
#include <memory>	// for memcpy()

// This function sorted list of cars of production year
void SortCarsOfYear ( car *arrOfCars )
{
	car tmpCar;	// temporary variable of structure

	// sorting under the algorithm bubble
	for(int i = NUMBER_OF_CARS - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			// if year of the next car is bigger
			if( (arrOfCars + j)->year < (arrOfCars + j + 1)->year )
			{
				tmpCar = *(arrOfCars + j);
				*(arrOfCars + j) = *(arrOfCars + j + 1);
				*(arrOfCars + j + 1) = tmpCar;
			}
		}	// End of for j
	}	// End of for i
}


// This function displays the average mileage for each brand
void PrintAVGMilleage ( car *arrOfCars )
{
	unsigned short sizeArr = 1;	
	unsigned short curr;	// current element of array
	bool brandInArr;	// availability brand in the array

	totalMilleage *tMill = new totalMilleage[sizeArr];	// created a pointer to the first element of the array
	memcpy ( tMill->brand, arrOfCars->brand, 20 * sizeof ( char ) );	// copy brand car
	tMill->numberOfCars = 0;	// number of cars of this brand
	tMill->totalMileage = 0;	// total mileage of cars of the brand

	for(int i = 0; i < NUMBER_OF_CARS; i++)
	{
		brandInArr = false;

		// search brand in the array
		for(curr = 0; (curr < sizeArr) && (brandInArr == false); curr++)
		{
			if( strcmp( (arrOfCars + i)->brand, (tMill + curr)->brand ) == 0 )
			{
				brandInArr = true;
			}
		}

		// if there is no mark in the array
		if(brandInArr == false)
		{
			// reallocation of memory with the addition of a new element to the array
			tMill = (totalMilleage *) realloc( tMill, sizeof(totalMilleage) * (++sizeArr) );

			memcpy ( (tMill + curr)->brand, (arrOfCars + i)->brand, 20 * sizeof ( char ) );
			(tMill + curr)->numberOfCars = 0;
			(tMill + curr)->totalMileage = 0;
		}
		else
		{
			curr--;
		}

		// add mileage of the given car to the total mileage brand
		(tMill + curr)->totalMileage += (arrOfCars + i)->mileage;
		(tMill + curr)->numberOfCars++;
	}	// End of for i

	printf("\nAverage mileage for each of the brands:\n");
	for(int k = 0; k < sizeArr; k++)
		printf("%s \t%.2f\n", (tMill + k)->brand, ( (tMill + k)->totalMileage / (float)((tMill + k)->numberOfCars )) );
	delete tMill;
}