/**
 * @file    test.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    30/10/2022
 */

#ifndef TEST_H
#define TEST_H
/****************************** Included files ********************************/
#include <stdbool.h>
#include <stdio.h>
/******************************** Definition **********************************/
#define TEST_START(name)\
    printf("\n\r>>> Test start for %s <<<\n\n", name)
#define TEST_FINISH \
    printf("*******************************************************************\
***********\n")
/*************** Application Programming Interface prototypes *****************/

/**
 * @brief User interaction function
 * @details The function accepts a response from the user to continue testing
 * and returns a boolean result.
 * @returns true, if the user entered the values 'y' or 'Y' or false - if any
 * other character
 */
bool DoRepeat(void);
/******************************************************************************/
#endif /* !TEST_H */
