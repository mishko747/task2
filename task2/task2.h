/**
* @file task2.h
* @brief The header file project 
*/

#ifndef TASK2_H_
#define TASK2_H_

#include "variant9.h"
#include "variant10.h"
#include "variant11.h"
#include "variant12.h"
#include "variant13.h"
#include "variant14.h"
#include "variant15.h"

typedef unsigned char UCH;

/**
* @brief	This function checks the correctness of the data entered by the user
* @param	[in]	minValue Unsigned short number
* @param	[in]	maxValue Unsigned short number
* @post		return unsigned short number that the user entered
* @return	unsigned short
*/
unsigned short ProtectionInput ( unsigned short minValue, unsigned short maxValue );

#endif /* TASK2_H_ */