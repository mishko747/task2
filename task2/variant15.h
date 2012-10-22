/**
* @file variant15.h
* @brief The header file to the task number 15
*/

#ifndef VARIANT15_H_
#define VARIANT15_H_

#define NUMBER_OF_TRIANGLE 3U
#define	NUMBER_OF_COORDINATE 3U

struct Triangle
{
	char points[NUMBER_OF_COORDINATE * 2U];
	float per;
};

void CalculatePerum ( Triangle *arr );

bool InputDataOfTriangle ( Triangle *arrTriangle );

void PrintDataOfTriangle ( Triangle *arrTrianlge );

void SortArrayOfTriangle ( Triangle *arr );

void PrintPercentTriangle (Triangle *arr );
// S(т-ка)=1/2((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3))


#endif /* VARIANT15_H_ */