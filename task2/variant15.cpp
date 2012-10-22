/**
* @file variant15.cpp
* @brief The source file to the task number 15
*/

#include "variant15.h"

#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

void CalculatePerum ( Triangle *arr )
{
	char *tmp;
	for(unsigned char i = 0; i < NUMBER_OF_TRIANGLE; ++i)
	{
		tmp = arr[i].points;
		arr[i].per += sqrt(pow( (float)(tmp[0] - tmp[2]), 2) + pow( (float)(tmp[1] - tmp[3]), 2));
		arr[i].per += sqrt(pow( (float)(tmp[0] - tmp[4]), 2) + pow( (float)(tmp[1] - tmp[5]), 2));
		arr[i].per += sqrt(pow( (float)(tmp[2] - tmp[4]), 2) + pow( (float)(tmp[3] - tmp[5]), 2));
	}
}

bool InputDataOfTriangle ( Triangle *arrTriangle )
{
	if(arrTriangle == NULL)
	{
		printf("Memory allocation error!\n");
		return false;
	}
	Triangle *tmpT = new Triangle;

	if(tmpT == NULL)
	{
		printf("Memory allocation error!\n");
		return false;
	}

	bool breakInput = false;


	printf("Enter the coordinates of the vertices for %u triangles: \n", NUMBER_OF_TRIANGLE);
	printf("Coordinates must be within [-127 .. 127], -128 - break.\n");

	signed short *tmp = new signed short;

	for(unsigned char i = 0; (i < NUMBER_OF_TRIANGLE) && (breakInput == false); ++i)
	{
		printf("  Enter the coordinates for %u triangle: \n", i + 1);
		for(unsigned char j = 0; (j < NUMBER_OF_COORDINATE) && (breakInput == false); ++j)
		{
			printf("  Endter x%d: ", j + 1);
			fflush(stdin);
			while( !scanf_s("%d", tmp) || *tmp < -128 || *tmp > 127 )
			{
				printf("  Incorrectly input data!\n");
				printf("  Repeat input: ");
				fflush(stdin);
			}

			if(*tmp == -128)
			{
				breakInput = true;
				continue;
			}
			tmpT->points[j * 2] = (char)*tmp;

			printf("  Endter y%d: ", j + 1);
			fflush(stdin);
			while( !scanf_s("%d", tmp) || *tmp < -128 || *tmp > 127 )
			{
				printf("  Incorrectly input data!\n");
				printf("  Repeat input: ");
				fflush(stdin);
			}
			if(*tmp == -128)
			{
				breakInput = true;
				continue;
			}
			tmpT->points[j * 2 + 1] = (char)*tmp;

		}	// End of for j
		if(breakInput == true)
		{
			continue;	
		}
		tmpT->per = 0;
		memcpy((arrTriangle + i), tmpT, sizeof(Triangle));
		printf("memcpu\n");
	}	// End of for i
	
	delete tmpT;
	return !breakInput;
} 


void PrintDataOfTriangle ( Triangle *arrTrianlge )
{

	if(arrTrianlge == NULL)
	{
		printf("Memory allocation error!\n");
		return;
	}
	printf("A\tB\tC\tPerumeter\n");
	char *tmp;
	for(unsigned char i = 0; i < NUMBER_OF_TRIANGLE; ++i)
	{
		tmp = arrTrianlge[i].points;
		printf("(%d, %d)\t(%d, %d)\t(%d, %d)\t%.2lf\n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], arrTrianlge[i].per);
	}
}

void SortArrayOfTriangle ( Triangle *arr )
{
	if(arr == NULL)
	{
		printf("Memory allocation error!\n");
		return;
	}
	Triangle *tmp = new Triangle;
	// sorting under the algorithm bubble
	for(unsigned char i = NUMBER_OF_TRIANGLE - 1; i > 0; --i)
	{
		for(unsigned char j = 0; j < i; ++j)
		{
			if(arr[j].per < arr[j + 1].per)
			{
				*tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = *tmp;
			}
		}	// End of for j
	}	// End of for i
	delete tmp;
}

void PrintPercentTriangle (Triangle *arr )
{
	if(arr == NULL)
	{
		printf("Memory allocation error!\n");
		return;
	}
	float minValue = arr[0].per;

	for(unsigned char i = 1; i < NUMBER_OF_TRIANGLE; ++i)
	{
		if(arr[i].per < minValue)
		{
			minValue = arr[i].per;
		}
	}
	unsigned char number = 0;
	for(unsigned char i = 0; i < NUMBER_OF_TRIANGLE; ++i)
	{
		if(arr[i].per > (minValue * 2.0))
		{
			number++;
		}
	}
	printf("Minimal perumeter: %.2f\n", minValue);
	printf("Percent triangles P/minP > 2: %.2f%%\n", (number / (float)NUMBER_OF_TRIANGLE) * 100.0);
}