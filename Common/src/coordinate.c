/**
 * @file    coordinate.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    28/10/2022
 */
/****************************** Included files ********************************/
#include "coordinate.h"
/********************* Application Programming Interface **********************/
void Coordinate_ctor(Coordinate * const self, uint16_t x, uint16_t y) {

}
/*----------------------------------------------------------------------------*/
void MoveToCoordinate(Coordinate * const self, uint16_t x, uint16_t y) {

}
/*----------------------------------------------------------------------------*/
void MoveFromCurrentPoint(
    Coordinate * const self,
    int16_t x_offset,
    int16_t y_ofset
) {

}
/*----------------------------------------------------------------------------*/
void StandInTheLowerLeftCorner(Coordinate * const self) {

}
/*----------------------------------------------------------------------------*/
void StandInTheUpperLeftCorner(Coordinate * const self) {

}
/*----------------------------------------------------------------------------*/
void StandInTheLowerRightCorner(Coordinate * const self) {

}
/*----------------------------------------------------------------------------*/
void StandInTheUpperRightCorner(Coordinate * const self) {

}
/*----------------------------------------------------------------------------*/
void StandInTheCenter(Coordinate * const self) {

}
/*----------------------------------------------------------------------------*/
uint16_t GetXCoordinate(Coordinate * const self) {
    return 0;
}
/*----------------------------------------------------------------------------*/
uint16_t GetYCoordinate(Coordinate * const self) {
    return 0;
}
/******************************************************************************/
