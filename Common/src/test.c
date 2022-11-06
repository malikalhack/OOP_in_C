/**
 * @file    test.c
 * @version 1.1.0
 * @authors Anton Chernov
 * @date    30/10/2022
 * @date    06/11/2022
 */

/****************************** Included files ********************************/
#include "test.h"
/********************* Application Programming Interface **********************/
bool DoRepeat(void) {
    char answer;
    printf("Would you like to repeat the test? ");
    fflush(stdout);
    DISCARD_RETURN(scanf(" %c", &answer));
    return (((answer == 'y') || (answer == 'Y')) ? true : false);
}
/******************************************************************************/
