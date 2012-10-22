/**
* @file variant12.cpp
* @brief The source file to the task number 12
*/

#include "variant12.h"

#include <string.h> // for strcmp()
#include <stdio.h>	// for printf() and scanf()


// This function displays information about points
void PrintPoints ( screenPoint *scrP )
{
	printf("X\tY\tColor\n");
	printf("----------------------\n");
	for(int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		printf("%u\t%u\t%s\n", (scrP + i)->x, (scrP + i)->y, (scrP + i)->color);
	}
}

// This function sorts the points by color
void SortByColor ( screenPoint *scrP )
{
	screenPoint tmpPoint;
	
	// sorting under the algorithm bubble
	for(int i = NUMBER_OF_POINTS - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(strcmp((scrP + j)->color, (scrP + j + 1)->color) > 0)
			{
				tmpPoint = *(scrP + j);
				*(scrP + j) = *(scrP + j + 1);
				*(scrP + j + 1) = tmpPoint;
			}
		}	// End of for j
	}	// End of for i
}

// This function takes two most distant current for each color
void SearchLargestDistance ( screenPoint *scrP )
{
	unsigned short min;
	unsigned short max;

	unsigned short point1;
	unsigned short point2;
	unsigned short delta;
	unsigned short colorNumber;

	unsigned short i = 0;
	while(i < NUMBER_OF_POINTS)
	{
		min = 0xFFFF;
		max = 0;
		//memcpy ( col, (scrP + i)->color, 5 * sizeof ( char ) ); 
		colorNumber = i;
		while(memcmp((scrP + colorNumber)->color, (scrP + i)->color, 5 * sizeof ( char )) == 0)
		{
			delta = (scrP + i)->x + (scrP + i)->y;

			if(delta < min)
			{
				point1 = i;
				min = delta;
			}

			if(delta > max)
			{
				point2 = i;
				max = delta;
			}

			i++;
		}

		if(point1 != point2)
		{
			printf("The most distant point of %s color: (%u, %u) - (%u, %u);\n", 
				(scrP + point1)->color, (scrP + point1)->x, (scrP + point1)->y, (scrP + point2)->x, (scrP + point2)->y);
		}
		else
		{
			printf("No two distant points %s.\n", (scrP + i - 1)->color); 
		}
	}
}