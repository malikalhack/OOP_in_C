/**
 * @file    coordinate.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    28/10/2022
 */

#ifndef COORDINATE_H
#define COORDINATE_H
/****************************** Included files ********************************/
#include <stdint.h>
/******************************** Definition **********************************/
#define X_LIMIT     (100)
#define Y_LIMIT     (100)
#define X_CENTER    (X_LIMIT/2)
#define Y_CENTER    (Y_LIMIT/2)

typedef struct {
    uint16_t x; ///< x-coordinate of position
    uint16_t y; ///< y-coordinate of position
} Coordinate;
/*************** Application Programming Interface prototypes *****************/
void Coordinate_ctor(Coordinate * const, uint16_t, uint16_t);
void MoveToCoordinate(Coordinate * const, uint16_t, uint16_t);
void MoveFromCurrentPoint(Coordinate * const, int16_t, int16_t);
void StandInTheLowerLeftCorner(Coordinate * const);
void StandInTheUpperLeftCorner(Coordinate * const);
void StandInTheLowerRightCorner(Coordinate * const);
void StandInTheUpperRightCorner(Coordinate * const);
void StandInTheCenter(Coordinate * const);
uint16_t GetXCoordinate(Coordinate * const);
uint16_t GetYCoordinate(Coordinate * const);
/******************************************************************************/
#endif
