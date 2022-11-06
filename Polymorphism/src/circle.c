/**
 * @file    circle.c
 * @version 1.1.0
 * @authors Anton Chernov
 * @date    01/11/2022
 * @date    06/11/2022
 */

 /****************************** Included files ********************************/
#include "circle.h"      /* circle class interface */
#include <assert.h>
/************************ Private  functions prototypes ***********************/
static coordinate_t CircleGetXCoordinate_(Coordinate const * const);
static coordinate_t CircleGetYCoordinate_(Coordinate const * const);
static void CircleMoveToCoordinate_(Coordinate * const, coordinate_t, coordinate_t);
static void CircleMoveFromCurrentPoint_(Coordinate * const, offset_t, offset_t);
static void CircleMoveToTheLowerLeftCorner_(Coordinate * const);
static void CircleMoveToTheUpperLeftCorner_(Coordinate * const);
static void CircleMoveToTheLowerRightCorner_(Coordinate * const);
static void CircleMoveToTheUpperRightCorner_(Coordinate * const);
static void CircleMoveToTheCenter_(Coordinate * const);
static float Circumference_(Coordinate const * const);
static float CircleArea_(Coordinate const * const);
/****************************** Private  functions ****************************/
static void make_move(
    coordinate_t * cc,
    offset_t * offset,
    radius_t *param,
    coordinate_t const limit
) {
    if (*offset) {
        coordinate_t lower_limit = HALF_PARAMETER(*param);
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
    radius_t *param,
    coordinate_t const limit
) {
    coordinate_t result;
    coordinate_t lower_limit = HALF_PARAMETER(*param);
    coordinate_t higher_limit = limit - lower_limit;

    if (*new_coordinate < lower_limit) { result = lower_limit; }
    else if (*new_coordinate > higher_limit) { result = higher_limit; }
    else { result = *new_coordinate; }

    return result;
}
/********************* Application Programming Interface **********************/
void Circle_ctor(Circle * const self, radius_t radius) {
    assert(radius <= RADIUS_LIMIT);
    Coordinate_ctor(
        &self->super,
        X_CENTER,
        Y_CENTER
    );                      /* call the superclass' constructor */
    self->radius = radius;  /* radius initializations */

    static struct CoordinateVtbl const vtbl = {
        .getXcoordinate = &CircleGetXCoordinate_,
        .getYcoordinate = &CircleGetYCoordinate_,
        .mv2coordinate = &CircleMoveToCoordinate_,
        .mvfromcp = &CircleMoveFromCurrentPoint_,
        .mv2llc = &CircleMoveToTheLowerLeftCorner_,
        .mv2ulc = &CircleMoveToTheUpperLeftCorner_,
        .mv2lrc = &CircleMoveToTheLowerRightCorner_,
        .mv2urc = &CircleMoveToTheUpperRightCorner_,
        .mv2center = &CircleMoveToTheCenter_,
        .perimeter = &Circumference_,
        .area = &CircleArea_
    };
    self->super.vptr = &vtbl;   /* override the vptr */
}
/*----------------------------------------------------------------------------*/
radius_t GetRadius(Circle const * const self) {
    return self->radius;
}
/*********** Circle's class implementations of its virtual functions **********/
static coordinate_t CircleGetXCoordinate_(Coordinate const * const self) {
    return (*self->api->getXcoordinate)(self);
}
/*----------------------------------------------------------------------------*/
static coordinate_t CircleGetYCoordinate_(Coordinate const * const self) {
    return (*self->api->getYcoordinate)(self);
}
/*----------------------------------------------------------------------------*/
static void CircleMoveToCoordinate_(
    Coordinate * const self,
    coordinate_t x,
    coordinate_t y
) {
    Circle * const _self = (Circle *)self; /* explicit downcast */
    self->x = make_rebase(&x, &_self->radius, X_LIMIT);
    self->y = make_rebase(&y, &_self->radius, Y_LIMIT);
}
/*----------------------------------------------------------------------------*/
static void CircleMoveFromCurrentPoint_(
    Coordinate * const self,
    offset_t x_offset,
    offset_t y_offset
) {
    Circle * const _self = (Circle *)self; /* explicit downcast */
    make_move(&_self->super.x, &x_offset, &_self->radius, X_LIMIT);
    make_move(&_self->super.y, &y_offset, &_self->radius, Y_LIMIT);
}
/*----------------------------------------------------------------------------*/
static void CircleMoveToTheLowerLeftCorner_(Coordinate * const self) {
    Circle * const _self = (Circle *)self; /* explicit downcast */
    radius_t temp = HALF_PARAMETER(_self->radius);
    _self->super.x = temp;
    _self->super.y = temp;
}
/*----------------------------------------------------------------------------*/
static void CircleMoveToTheUpperLeftCorner_(Coordinate * const self) {
    Circle * const _self = (Circle *)self; /* explicit downcast */
    _self->super.x = HALF_PARAMETER(_self->radius);
    _self->super.y = Y_LIMIT - _self->super.x;
}
/*----------------------------------------------------------------------------*/
static void CircleMoveToTheLowerRightCorner_(Coordinate * const self) {
    Circle * const _self = (Circle *)self; /* explicit downcast */
    _self->super.y = HALF_PARAMETER(_self->radius);
    _self->super.x = X_LIMIT - _self->super.y;
}
/*----------------------------------------------------------------------------*/
static void CircleMoveToTheUpperRightCorner_(Coordinate * const self) {
    Circle * const _self = (Circle *)self; /* explicit downcast */
    radius_t temp = HALF_PARAMETER(_self->radius);
    _self->super.x = X_LIMIT - temp;
    _self->super.y = Y_LIMIT - temp;
}
/*----------------------------------------------------------------------------*/
static void CircleMoveToTheCenter_(Coordinate * const self) {
    (*self->api->mv2center)(self);
}
/*----------------------------------------------------------------------------*/
static float Circumference_(Coordinate const * const self) {
    Circle const * const _self = (Circle const *)self; /* explicit downcast */
    return (2 * PI * _self->radius);
}
/*----------------------------------------------------------------------------*/
static float CircleArea_(Coordinate const * const self) {
    Circle const * const _self = (Circle const *)self; /* explicit downcast */
    return (PI * _self->radius * _self->radius);
}
/******************************************************************************/
