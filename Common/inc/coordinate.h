/**
 * @file    coordinate.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    29/10/2022
 */

#ifndef COORDINATE_H
#define COORDINATE_H
/****************************** Included files ********************************/
#include <stdint.h>
/******************************** Definition **********************************/
#define X_LIMIT     (200u)
#define Y_LIMIT     (200u)

#if X_LIMIT < 2 || Y_LIMIT < 2
    #error Field limits are wrong
#endif //Checking limits

#define X_CENTER    (X_LIMIT/2u)
#define Y_CENTER    (Y_LIMIT/2u)

typedef uint16_t coordinate_t;
typedef signed short offset_t;
typedef unsigned short abs_offset_t;

typedef struct {
    coordinate_t x; ///< x-coordinate of position
    coordinate_t y; ///< y-coordinate of position
} Coordinate;
/*************** Application Programming Interface prototypes *****************/
void Coordinate_ctor(Coordinate * const, coordinate_t, coordinate_t);
void MoveToCoordinate(Coordinate * const, coordinate_t, coordinate_t);
void MoveFromCurrentPoint(Coordinate * const, offset_t, offset_t);
void StandInTheLowerLeftCorner(Coordinate * const);
void StandInTheUpperLeftCorner(Coordinate * const);
void StandInTheLowerRightCorner(Coordinate * const);
void StandInTheUpperRightCorner(Coordinate * const);
void StandInTheCenter(Coordinate * const);
coordinate_t GetXCoordinate(Coordinate * const);
coordinate_t GetYCoordinate(Coordinate * const);
/******************************************************************************/
#endif
