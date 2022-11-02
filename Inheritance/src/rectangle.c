/**
 * @file    rectangle.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    29/10/2022
 * @date    02/11/2022
 */

/****************************** Included files ********************************/
#include "rectangle.h"      /* rectangle class interface */
#include <assert.h>
/************************ Private  functions prototypes ***********************/
#ifdef POLYMORPHISM
static coordinate_t RectangleGetXCoordinate_(Coordinate const * const);
static coordinate_t RectangleGetYCoordinate_(Coordinate const * const);
static void RectangleMoveToCoordinate_(Coordinate * const, coordinate_t, coordinate_t);
static void RectangleMoveFromCurrentPoint_(Coordinate * const, offset_t, offset_t);
static void RectangleMoveToTheLowerLeftCorner_(Coordinate * const);
static void RectangleMoveToTheUpperLeftCorner_(Coordinate * const);
static void RectangleMoveToTheLowerRightCorner_(Coordinate * const);
static void RectangleMoveToTheUpperRightCorner_(Coordinate * const);
static void RectangleMoveToTheCenter_(Coordinate * const);
static float RectanglePerimeter_(Coordinate const * const );
static float RectangleArea_(Coordinate const * const);
#endif // POLYMORPHISM
/****************************** Private  functions ****************************/
static void make_move(
    coordinate_t * cc,
    offset_t * offset,
    params_t *param,
    coordinate_t const limit
) {
    if (*offset) {
        coordinate_t lower_limit = *param / 2;
        coordinate_t higher_limit = limit - lower_limit;
        abs_offset_t abs_offset = abs(*offset);

        if (*offset < 0 && abs_offset >= *cc - lower_limit) {
            *cc = lower_limit;
        }
        else if (*offset > 0 && (higher_limit - *cc) <= abs_offset) {
            *cc = higher_limit;
        }
        else {
            *cc += *offset;
        }
    }
}
/*----------------------------------------------------------------------------*/
static coordinate_t make_rebase(
    coordinate_t * new_coordinate,
    params_t *param,
    coordinate_t const limit
) {
    coordinate_t result;
    coordinate_t lower_limit = *param / 2;
    coordinate_t higher_limit = limit - lower_limit;

    if (*new_coordinate < lower_limit) { result = lower_limit; }
    else if (*new_coordinate > higher_limit) { result = higher_limit; }
    else { result = *new_coordinate; }

    return result;
}
/********************* Application Programming Interface **********************/
void Rectangle_ctor(
    Rectangle * const self,
    params_t width,
    params_t length
) {
    assert(width <= WIDTH_LIMIT && length <= LENGTH_LIMIT);
    Coordinate_ctor(
        &self->super,
        X_CENTER,
        Y_CENTER
    );                          /* call the superclass' constructor */
    self->width = width;        /* width initializations */
    self->length = length;      /* length initializations */
#ifdef POLYMORPHISM
    static struct CoordinateVtbl const vtbl = {
        .getXcoordinate = &RectangleGetXCoordinate_,
        .getYcoordinate = &RectangleGetYCoordinate_,
        .mv2coordinate = &RectangleMoveToCoordinate_,
        .mvfromcp = &RectangleMoveFromCurrentPoint_,
        .mv2llc = &RectangleMoveToTheLowerLeftCorner_,
        .mv2ulc = &RectangleMoveToTheUpperLeftCorner_,
        .mv2lrc = &RectangleMoveToTheLowerRightCorner_,
        .mv2urc = &RectangleMoveToTheUpperRightCorner_,
        .mv2center = &RectangleMoveToTheCenter_,
        .perimeter = &RectanglePerimeter_,
        .area = &RectangleArea_
    };
    self->super.vptr = &vtbl;   /* override the vptr */
#endif // POLYMORPHISM
}
/*----------------------------------------------------------------------------*/
params_t GetLength(Rectangle const * const self) {
    return self->length;
}
/*----------------------------------------------------------------------------*/
params_t GetWidth(Rectangle const * const self) {
    return self->width;
}
#ifdef POLYMORPHISM

/********* Rectangle's class implementations of its virtual functions *********/
static float RectangleArea_(Coordinate const * const self) {
    Rectangle const * const _self = (Rectangle const *)self; /* explicit downcast */
    return (float)(_self->width * _self->length);
}
/*----------------------------------------------------------------------------*/
static float RectanglePerimeter_(Coordinate const * const self) {
    Rectangle const * const _self = (Rectangle const *)self; /* explicit downcast */
    return (float)(2 * (_self->length + _self->width));
}
/*----------------------------------------------------------------------------*/
static void RectangleMoveToCoordinate_(
    Coordinate * const self,
    coordinate_t x,
    coordinate_t y
) {
    Rectangle * const _self = (Rectangle *)self; /* explicit downcast */
    self->x = make_rebase(&x, &_self->length, X_LIMIT);
    self->y = make_rebase(&y, &_self->width, Y_LIMIT);
}
/*----------------------------------------------------------------------------*/
static void RectangleMoveFromCurrentPoint_(
    Coordinate * const self,
    offset_t x_offset,
    offset_t y_offset
) {
    Rectangle * const _self = (Rectangle *)self; /* explicit downcast */
    make_move(&_self->super.x, &x_offset, &_self->length, X_LIMIT);
    make_move(&_self->super.y, &y_offset, &_self->width, Y_LIMIT);
}
/*----------------------------------------------------------------------------*/
static void RectangleMoveToTheLowerLeftCorner_(Coordinate * const self) {
    Rectangle * const _self = (Rectangle *)self; /* explicit downcast */
    _self->super.x = _self->length / 2;
    _self->super.y = _self->width / 2;
}
/*----------------------------------------------------------------------------*/
static void RectangleMoveToTheUpperLeftCorner_(Coordinate * const self) {
    Rectangle * const _self = (Rectangle *)self; /* explicit downcast */
    _self->super.x = _self->length / 2;
    _self->super.y = Y_LIMIT - _self->width / 2;
}
/*----------------------------------------------------------------------------*/
static void RectangleMoveToTheLowerRightCorner_(Coordinate * const self) {
    Rectangle * const _self = (Rectangle *)self; /* explicit downcast */
    _self->super.x = X_LIMIT - _self->length / 2;
    _self->super.y = _self->width / 2;
}
/*----------------------------------------------------------------------------*/
static void RectangleMoveToTheUpperRightCorner_(Coordinate * const self) {
    Rectangle * const _self = (Rectangle *)self; /* explicit downcast */
    _self->super.x = X_LIMIT - _self->length / 2;
    _self->super.y = Y_LIMIT - _self->width / 2;
}
/*----------------------------------------------------------------------------*/
static void RectangleMoveToTheCenter_(Coordinate * const self) {
    (*self->api->mv2center)(self);
}
/*----------------------------------------------------------------------------*/
static coordinate_t RectangleGetXCoordinate_(Coordinate const * const self) {
    return (*self->api->getXcoordinate)(self);
}
/*----------------------------------------------------------------------------*/
static coordinate_t RectangleGetYCoordinate_(Coordinate const * const self) {
    return (*self->api->getYcoordinate)(self);
}

#endif // POLYMORPHISM
/******************************************************************************/
