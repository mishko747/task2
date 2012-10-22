/**
* @file variant12.h
* @brief The header file to the task number 12
*/

#ifndef VARIANT12_H_
#define VARIANT12_H_

const unsigned short NUMBER_OF_POINTS = 3;	// total number of points

struct screenPoint
{
	unsigned short x;
	unsigned short y;
	char color[5];
};

/**
* @brief	This function displays information about points
* @param	[in]	scrP Pointer to the structure screenPoint
* @return	void
*/
void PrintPoints ( screenPoint *scrP );

/**
* @brief	This function sorts the points by color
* @param	[in]	scrP Pointer to the structure screenPoint
* @return	void
*/
void SortByColor ( screenPoint *scrP );

/**
* @brief	This function takes two most distant current for each color
* @param	[in]	scrP Pointer to the structure screenPoint
* @return	void
*/
void SearchLargestDistance ( screenPoint *scrP );


#endif /* VARIANT12_H_ */