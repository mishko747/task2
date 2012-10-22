/**
* @file variant9.h
* @brief The header file to the task number 9
*/

#ifndef VARIANT9_H_
#define VARIANT9_H_

const unsigned short WORD_LENGTH = 25;	// length of a word
const unsigned short TERM_LENGTH = 5;	// number of terms in the dictionary

struct term
{
	char original[WORD_LENGTH];
	char transl[WORD_LENGTH];
	bool checked;	// sign using the term
};

/**
* @brief	This function holding testing the user and displays the result
* @param	[in]	termArray Pointer to the first term of the dictionary (an array of terms)
* @param	[in]	countTests Number of tests
* @post		returns the number of correct answers in percent
* @return	float
*/
float UserTesting ( term *termArray, unsigned short countTests );

#endif /* VARIANT9_H_ */