/**
* @file variant14.h
* @brief The header file to the task number 14
*/

#ifndef VARIANT14_H_
#define VARIANT14_H_

typedef unsigned char UCH;

#define LENGTH_ARR_OF_TESTS	5U	// total number of tests
#define LENGTH_OF_QUEST		32U		// size question in characters
#define LENGTH_OF_ANSWER	32U	// size answer in characters
#define NUMBER_ANSWERS		4U		// number of responses
#define NUMBER_OF_TESTS		3U		// number of tests for the user

struct test
{
	UCH quest[LENGTH_OF_QUEST];	// question
	UCH answers[NUMBER_ANSWERS * LENGTH_OF_ANSWER];	// array of answers
	UCH correctAnswer;	// number of correct answers
	bool checked;	// sign of testing on this question
};

/**
* @brief	This function is designed for users input data on tests
* @param	[in]	arrTest Pointer to the structure test
* @post		returns true if the input data is completed correctly, false - otherwise.
* @return	bool
*/
bool InputTests ( test *arrTest );

/**
* @brief	This function provides the user testing
* @param	[in]	arrTest Pointer to the structure test
* @return	void
*/
void Testing ( test *arrTest );


#endif /* VARIANT14_H_ */