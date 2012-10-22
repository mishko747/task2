/**
* @file variant11.h
* @brief The header file to the task number 11
*/

#ifndef VARIANT11_H_
#define VARIANT11_H_

const unsigned short NUMBER_OF_STUDENTS = 5;	// number of students in the list
const unsigned short NUMBER_OF_EVALUATIONS = 3;	// number of evaluations of student

struct student
{
	char surname[22];
	char name[10];
	unsigned short eval;
};

/**
* @brief	This function displays information about students
* @param	[in]	stud Pointer to the structure student
* @return	void
*/
void PrintInfoAboutStudents ( student *stud );

/**
* @brief	This function sorts the students by surname
* @param	[in]	stud Pointer to the structure student
* @return	void
*/
void SortStudents ( student *stud );

/**
* @brief	This function counts the average rating
* @param	[in]	value Unsigned short number
* @return	float
*/
float AVGOfEval ( unsigned short value );

/**
* @brief	This function displays information about the two best students from the list
* @param	[in]	stud Pointer to the structure student
* @return	void
*/
void PrintBestStudents ( student *stud );

#endif /* VARIANT11_H_ */