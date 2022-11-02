/**
 * @file    coordinate.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    02/11/2022
 */

/****************************** Included files ********************************/
#include "coordinate.h"
#include <assert.h>
#ifdef POLYMORPHISM
#include <stdio.h>
/************************ Private  functions prototypes ***********************/
static coordinate_t VirtualGetXCoordinate(Coordinate const * const);
static coordinate_t VirtualGetYCoordinate(Coordinate const * const);
static void VirtualMoveToCoordinate(Coordinate * const, coordinate_t, coordinate_t);
static void VirtualMoveFromCurrentPoint(Coordinate * const, offset_t, offset_t);
static void VirtualMoveToTheLowerLeftCorner(Coordinate * const);
static void VirtualMoveToTheUpperLeftCorner(Coordinate * const);
static void VirtualMoveToTheLowerRightCorner(Coordinate * const);
static void VirtualMoveToTheUpperRightCorner(Coordinate * const);
static void VirtualMoveToTheCenter(Coordinate * const);
static float VirtualPerimeter(Coordinate const * const);
static float VirtualArea(Coordinate const * const);

static void SuperMoveToCoordinate(Coordinate * const, coordinate_t, coordinate_t);
static void SuperMoveFromCurrentPoint(Coordinate * const, offset_t, offset_t);
static void SuperMoveToTheLowerLeftCorner(Coordinate * const);
static void SuperMoveToTheUpperLeftCorner(Coordinate * const);
static void SuperMoveToTheLowerRightCorner(Coordinate * const);
static void SuperMoveToTheUpperRightCorner(Coordinate * const);
static void SuperMoveToTheCenter(Coordinate * const);
static coordinate_t SuperGetXCoordinate(Coordinate const * const);
static coordinate_t SuperGetYCoordinate(Coordinate const * const);
#endif
/****************************** Private  functions ****************************/
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
void Coordinate_ctor(
    Coordinate * const self,
    coordinate_t x,
    coordinate_t y
) {
    assert(x <= X_LIMIT && y <= Y_LIMIT);
    self->x = x;
    self->y = y;

#ifdef POLYMORPHISM
    static struct CoordinateAPI const api = {
        .getXcoordinate = &SuperGetXCoordinate,
        .getYcoordinate = &SuperGetYCoordinate,
        .mv2coordinate = &SuperMoveToCoordinate,
        .mvfromcp = &SuperMoveFromCurrentPoint,
        .mv2llc = &SuperMoveToTheLowerLeftCorner,
        .mv2ulc = &SuperMoveToTheUpperLeftCorner,
        .mv2lrc = &SuperMoveToTheLowerRightCorner,
        .mv2urc = &SuperMoveToTheUpperRightCorner,
        .mv2center = &SuperMoveToTheCenter
    };

    static struct CoordinateVtbl const vtbl = {
        .getXcoordinate = &VirtualGetXCoordinate,
        .getYcoordinate = &VirtualGetYCoordinate,
        .mv2coordinate = &VirtualMoveToCoordinate,
        .mvfromcp = &VirtualMoveFromCurrentPoint,
        .mv2llc = &VirtualMoveToTheLowerLeftCorner,
        .mv2ulc = &VirtualMoveToTheUpperLeftCorner,
        .mv2lrc = &VirtualMoveToTheLowerRightCorner,
        .mv2urc = &VirtualMoveToTheUpperRightCorner,
        .mv2center = &VirtualMoveToTheCenter,
        .perimeter = &VirtualPerimeter,
        .area = &VirtualArea
    };

    self->vptr = &vtbl;
    self->api = &api;
#endif /* POLYMORPHISM */
}
/*----------------------------------------------------------------------------*/
DECLARATION void SPECIFIED(MoveToCoordinate)(
    Coordinate * const self,
    coordinate_t x,
    coordinate_t y
) {
    self->x = x < X_LIMIT ? x : X_LIMIT;
    self->y = y < Y_LIMIT ? y : Y_LIMIT;
}
/*----------------------------------------------------------------------------*/
DECLARATION void SPECIFIED(MoveFromCurrentPoint)(
    Coordinate * const self,
    offset_t x_offset,
    offset_t y_offset
) {
    make_move(&self->x, &x_offset, X_LIMIT);
    make_move(&self->y, &y_offset, Y_LIMIT);
}
/*----------------------------------------------------------------------------*/
DECLARATION void SPECIFIED(MoveToTheLowerLeftCorner)(Coordinate * const self) {
    self->x = 0u;
    self->y = 0u;
}
/*----------------------------------------------------------------------------*/
DECLARATION void SPECIFIED(MoveToTheUpperLeftCorner)(Coordinate * const self) {
    self->x = 0u;
    self->y = Y_LIMIT;
}
/*----------------------------------------------------------------------------*/
DECLARATION void SPECIFIED(MoveToTheLowerRightCorner)(Coordinate * const self) {
    self->x = X_LIMIT;
    self->y = 0u;
}
/*----------------------------------------------------------------------------*/
DECLARATION void SPECIFIED(MoveToTheUpperRightCorner)(Coordinate * const self) {
    self->x = X_LIMIT;
    self->y = Y_LIMIT;
}
/*----------------------------------------------------------------------------*/
DECLARATION void SPECIFIED(MoveToTheCenter)(Coordinate * const self) {
    self->x = X_CENTER;
    self->y = Y_CENTER;
}
/*----------------------------------------------------------------------------*/
DECLARATION coordinate_t SPECIFIED(GetXCoordinate)(Coordinate const * const self) {
    return self->x;;
}
/*----------------------------------------------------------------------------*/
DECLARATION coordinate_t SPECIFIED(GetYCoordinate)(Coordinate const * const self) {
    return self->y;
}
#ifdef POLYMORPHISM
/*----------------------------------------------------------------------------*/
void CalculateAllAreas(Coordinate const *  objects[], size_t length) {
    for (size_t index = 0; index < length; index++) {
        printf(
            "The area of %zu object is %7.3f\n", index,
            (*objects[index]->vptr->area)(objects[index]) /* virtual call */
        );
    }
    printf("\n\r");
}
/*----------------------------------------------------------------------------*/
void CalculateAllPerimeters(Coordinate const * objects[], size_t length) {
    for (size_t index = 0; index < length; index++) {
        printf(
            "The perimeter of %zu object is %7.3f\n", index,
            (*objects[index]->vptr->perimeter)(objects[index]) /* virtual call */
        );
    }
    printf("\n\r");
}
/*----------------------------------------------------------------------------*/
void MoveToCoordinate(Coordinate * const self, coordinate_t x, coordinate_t y) {
    (*self->vptr->mv2coordinate)(self, x, y);
}
/*----------------------------------------------------------------------------*/
void MoveFromCurrentPoint(Coordinate * const self, offset_t x, offset_t y) {
    (*self->vptr->mvfromcp)(self, x, y);
}
/*----------------------------------------------------------------------------*/
void MoveToTheLowerLeftCorner(Coordinate * const self) {
    (*self->vptr->mv2llc)(self);
}
/*----------------------------------------------------------------------------*/
void MoveToTheUpperLeftCorner(Coordinate * const self) {
    (*self->vptr->mv2ulc)(self);
}
/*----------------------------------------------------------------------------*/
void MoveToTheLowerRightCorner(Coordinate * const self) {
    (*self->vptr->mv2lrc)(self);
}
/*----------------------------------------------------------------------------*/
void MoveToTheUpperRightCorner(Coordinate * const self) {
    (*self->vptr->mv2urc)(self);
}
/*----------------------------------------------------------------------------*/
void MoveToTheCenter(Coordinate * const self) {
    (*self->vptr->mv2center)(self);
}
/*----------------------------------------------------------------------------*/
coordinate_t GetXCoordinate(Coordinate const * const self) {
    return (*self->vptr->getXcoordinate)(self);
}
/*----------------------------------------------------------------------------*/
coordinate_t GetYCoordinate(Coordinate const * const self) {
    return (*self->vptr->getYcoordinate)(self);
}
/********** Coordinate class implementations of its virtual functions *********/
static coordinate_t VirtualGetXCoordinate(Coordinate const * const self) {
    (void)self;             /* to avoid compiler warnings */
    assert(0);              /* purely-virtual function should never be called */
    return (coordinate_t)0; /* to avoid compiler warnings */
}
/*----------------------------------------------------------------------------*/
static coordinate_t VirtualGetYCoordinate(Coordinate const * const self) {
    (void)self;             /* to avoid compiler warnings */
    assert(0);              /* purely-virtual function should never be called */
    return (coordinate_t)0; /* to avoid compiler warnings */
}
/*----------------------------------------------------------------------------*/
static void VirtualMoveToCoordinate(
    Coordinate * const self,
    coordinate_t x,
    coordinate_t y
) {
    (void)self; /* to avoid compiler warnings */
    (void)x;    /* to avoid compiler warnings */
    (void)y;    /* to avoid compiler warnings */
    assert(0);  /* purely-virtual function should never be called */
}
/*----------------------------------------------------------------------------*/
static void VirtualMoveFromCurrentPoint(
    Coordinate * const self,
    offset_t x_offset,
    offset_t y_offset
) {
    (void)self;     /* to avoid compiler warnings */
    (void)x_offset; /* to avoid compiler warnings */
    (void)y_offset; /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
}
/*----------------------------------------------------------------------------*/
static void VirtualMoveToTheLowerLeftCorner(Coordinate * const self) {
    (void)self;     /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
}
/*----------------------------------------------------------------------------*/
static void VirtualMoveToTheUpperLeftCorner(Coordinate * const self) {
    (void)self;     /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
}
/*----------------------------------------------------------------------------*/
static void VirtualMoveToTheLowerRightCorner(Coordinate * const self) {
    (void)self;     /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
}
/*----------------------------------------------------------------------------*/
static void VirtualMoveToTheUpperRightCorner(Coordinate * const self) {
    (void)self;     /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
}
/*----------------------------------------------------------------------------*/
static void VirtualMoveToTheCenter(Coordinate * const self) {
    (void)self;     /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
}
/*----------------------------------------------------------------------------*/
static float VirtualPerimeter(Coordinate const * const self) {
    (void)self;     /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
    return 0.f;
}
/*----------------------------------------------------------------------------*/
static float VirtualArea(Coordinate const * const self) {
    (void)self;     /* to avoid compiler warnings */
    assert(0);      /* purely-virtual function should never be called */
    return 0.f;
}
#endif
/******************************************************************************/
