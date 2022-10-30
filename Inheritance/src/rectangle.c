/**
 * @file    rectangle.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    29/10/2022
 * @date    30/10/2022
 */

 /****************************** Included files ********************************/
#include "rectangle.h"
#include <assert.h>
/********************* Application Programming Interface **********************/
void Rectangle_ctor(
    Rectangle * const self,
    coordinate_t x,
    coordinate_t y,
    params_t width,
    params_t length
) {
    assert(width <= WIDTH_LIMIT && length <= LENGTH_LIMIT);
    Coordinate_ctor(&self->super, x, y);
    self->width = width;
    self->length = length;
}
/*----------------------------------------------------------------------------*/
params_t GetLength(Rectangle * const self) {
    return self->length;
}
/*----------------------------------------------------------------------------*/
params_t GetWidth(Rectangle * const self) {
    return self->width;
}
/******************************************************************************/
