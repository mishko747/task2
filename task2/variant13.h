/**
* @file variant12.h
* @brief The header file to the task number 13
*/

#ifndef VARIANT13_H_
#define VARIANT13_H_

typedef unsigned char UCH;

#define NUMBER_MED_STUDENTS 5U	// number of records of students [1..255]
#define LENGTH_OF_NAME 32U	// number of characters field name and initials

// macros to interrupt input data
#define BREAK_INPUT(x) if((x) == 0) { breakInput = true; continue;}

struct medStudent
{
	UCH name[LENGTH_OF_NAME];	// surname and initials
	unsigned years : 7;		// age student
	unsigned gender: 1;		// gender of student
	unsigned height: 8;		// student height
	unsigned weight: 8;		// weight student
};

/**
* @brief	This function checks the correctness of the input numbers in the range [0 .. 255]
* @param	[in]	minValue Unsigned char number
* @param	[in]	maxValue Unsigned char number
* @post		return unsigned char number that the user entered
* @return	unsigned char
*/
UCH ProtectionInputUChar ( UCH min, UCH max );

/**
* @brief	This function is designed for users input data on students
* @param	[in]	mStud Pointer to the structure medStudent
* @post		returns true if the input data is completed correctly, false - otherwise.
* @return	bool
*/
bool InputDataMedStudents ( medStudent *mStud );

/**
* @brief	This function is for sort the records on students by name
* @param	[in]	mStud Pointer to the structure medStudent
* @post		returns true if the sorting is completed correctly, false - otherwise.
* @return	bool
*/
bool SotrStudents ( medStudent *mStud );

/**
* @brief	This aunction displays th average values of height and weight of students
*				(separately for girls and bous separately)
* @param	[in]	mStud Pointer to the structure medStudent
* @post		returns true if the calculation and print is completed correctly, false - otherwise.
* @return	bool
*/
bool PrintHeightWeightAWG ( medStudent *mStud );

/**
* @brief	This function displays a list of data on students in a table
* @param	[in]	mStud Pointer to the structure medStudent
* @return	void
*/
void PrintDataOfStudents ( medStudent *mStud );

#endif /* VARIANT13_H_ */