/**
 * @file    common.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    02/11/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/***************************** Public functions *******************************/
abs_offset_t abs(offset_t num) {
    return (abs_offset_t)(num < 0 ? num *= -1 : num);
}
/******************************************************************************/
