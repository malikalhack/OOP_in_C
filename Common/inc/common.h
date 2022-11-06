/**
 * @file    common.h
 * @version 1.1.0
 * @authors Anton Chernov
 * @date    02/11/2022
 * @date    06/11/2022
 */

#ifndef COMMON_H
#define COMMON_H
 /****************************** Included files ********************************/
#include <stdint.h>
/******************************** Definition **********************************/
#define HALF_PARAMETER(param) ((param) & 0x1 ? (param) / 2 + 1 : (param) / 2)

typedef uint16_t coordinate_t;
typedef signed short offset_t;
typedef unsigned short abs_offset_t;
/************************* Public functions prototypes ************************/

/**
 * @brief A simple function to return the modulus of a number.
 * @param[in] - the passed number
 * @returns the absolute value of the number
 */
abs_offset_t abs(offset_t);
/******************************************************************************/
#endif /* !COMMON_H */
