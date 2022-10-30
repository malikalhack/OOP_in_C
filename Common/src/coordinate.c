/**
 * @file    coordinate.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    29/10/2022
 */

/****************************** Included files ********************************/
#include "coordinate.h"
#include <assert.h>
/****************************** Private  functions ****************************/
static abs_offset_t abs(offset_t num) {
    return (num < 0 ? num *= -1 : (abs_offset_t)num);
}
/*----------------------------------------------------------------------------*/
static void make_move(
    coordinate_t * cc,
    offset_t * offset,
    coordinate_t const limit
) {
    if (*offset) {
        abs_offset_t abs_offset = abs(*offset);
        if (*offset < 0 && abs_offset >= *cc) { *cc = 0u; }
        else if (*offset > 0 && (limit - *cc) <= abs_offset) { *cc = limit; }
        else { *cc += *offset; }
    }
}
/********************* Application Programming Interface **********************/
void Coordinate_ctor(Coordinate * const self, coordinate_t x, coordinate_t y) {
    assert(x <= X_LIMIT && y <= Y_LIMIT);
    self->x = x;
    self->y = y;
}
/*----------------------------------------------------------------------------*/
void MoveToCoordinate(Coordinate * const self, coordinate_t x, coordinate_t y) {
    self->x = x < X_LIMIT ? x : X_LIMIT;
    self->y = y < Y_LIMIT ? y : Y_LIMIT;
}
/*----------------------------------------------------------------------------*/
void MoveFromCurrentPoint(
    Coordinate * const self,
    offset_t x_offset,
    offset_t y_offset
) {
    make_move(&self->x, &x_offset, X_LIMIT);
    make_move(&self->y, &y_offset, Y_LIMIT);
}
/*----------------------------------------------------------------------------*/
void StandInTheLowerLeftCorner(Coordinate * const self) {
    self->x = 0u;
    self->y = 0u;
}
/*----------------------------------------------------------------------------*/
void StandInTheUpperLeftCorner(Coordinate * const self) {
    self->x = 0u;
    self->y = Y_LIMIT;
}
/*----------------------------------------------------------------------------*/
void StandInTheLowerRightCorner(Coordinate * const self) {
    self->x = X_LIMIT;
    self->y = 0u;
}
/*----------------------------------------------------------------------------*/
void StandInTheUpperRightCorner(Coordinate * const self) {
    self->x = X_LIMIT;
    self->y = Y_LIMIT;
}
/*----------------------------------------------------------------------------*/
void StandInTheCenter(Coordinate * const self) {
    self->x = X_CENTER;
    self->y = Y_CENTER;
}
/*----------------------------------------------------------------------------*/
coordinate_t GetXCoordinate(Coordinate * const self) {
    return self->x;;
}
/*----------------------------------------------------------------------------*/
coordinate_t GetYCoordinate(Coordinate * const self) {
    return self->y;
}
/******************************************************************************/
