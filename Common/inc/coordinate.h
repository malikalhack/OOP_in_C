/**
 * @file    coordinate.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    02/11/2022
 */

#ifndef COORDINATE_H
#define COORDINATE_H
/****************************** Included files ********************************/
#include "common.h"
/******************************** Definition **********************************/
#define X_LIMIT     (200u)
#define Y_LIMIT     (200u)

#if X_LIMIT < 2 || Y_LIMIT < 2
    #error Field limits are wrong
#endif //Checking limits

#define X_CENTER    (X_LIMIT/2u)
#define Y_CENTER    (Y_LIMIT/2u)

#ifdef POLYMORPHISM
    #define SPECIFIED(name) (Super ## name)
    #define DECLARATION static
#else
    #define SPECIFIED(name) (name)
    #define DECLARATION
#endif // POLYMORPHISM

#ifdef POLYMORPHISM

struct CoordinateVtbl; /* Mandatory forward declaration*/
struct CoordinateAPI;  /* Mandatory forward declaration*/

typedef struct {
    struct CoordinateVtbl const *vptr; ///< Coordinate's Virtual Pointer
    struct CoordinateAPI const *api;   ///< Coordinate's API Pointer
    coordinate_t x; ///< x-coordinate of position
    coordinate_t y; ///< y-coordinate of position
} Coordinate;

/* Coordinate's virtual table */
struct CoordinateVtbl {
    coordinate_t(*getXcoordinate)(Coordinate const * const);
    coordinate_t(*getYcoordinate)(Coordinate const * const);
    void(*mv2coordinate)(Coordinate * const, coordinate_t, coordinate_t);
    void(*mvfromcp)(Coordinate * const, offset_t, offset_t);
    void(*mv2llc)(Coordinate * const);
    void(*mv2ulc)(Coordinate * const);
    void(*mv2lrc)(Coordinate * const);
    void(*mv2urc)(Coordinate * const);
    void(*mv2center)(Coordinate * const);
    float(*perimeter)(Coordinate const * const);
    float(*area)(Coordinate const * const);
};

/* Coordinate's API Pointer */
struct CoordinateAPI {
    coordinate_t(*getXcoordinate)(Coordinate const * const);
    coordinate_t(*getYcoordinate)(Coordinate const * const);
    void(*mv2coordinate)(Coordinate * const, coordinate_t, coordinate_t);
    void(*mvfromcp)(Coordinate * const, offset_t, offset_t);
    void(*mv2llc)(Coordinate * const);
    void(*mv2ulc)(Coordinate * const);
    void(*mv2lrc)(Coordinate * const);
    void(*mv2urc)(Coordinate * const);
    void(*mv2center)(Coordinate * const);
};

#else

typedef struct {
    coordinate_t x; ///< x-coordinate of position
    coordinate_t y; ///< y-coordinate of position
} Coordinate;

#endif // POLYMORPHISM

/*************** Application Programming Interface prototypes *****************/

/**
 * @brief Constructor function
 * @details Initializes the specified object with the passed coordinates.
 * param[in] self - a pointer to the specified object
 * param[in] x - the passed X-coordinate
 * param[in] y - the passed Y-coordinate
 * @note The coordinates are limited. An exception will be thrown if you try to
 * go beyond the limit.
 */
void Coordinate_ctor(Coordinate * const, coordinate_t, coordinate_t);

/**
 * @brief The public function for moving along the specified coordinates.
 * param[in] self - a pointer to the specified object
 * param[in] x - the passed new X-coordinate
 * param[in] y - the passed new Y-coordinate
 * @note The coordinates are limited. You cannot exceed the limit.
 */
void MoveToCoordinate(Coordinate * const, coordinate_t, coordinate_t);

/**
 * @details The public function of moving from the current coordinates
 * to the specified offset.
 * param[in] self - a pointer to the specified object
 * param[in] x_offset - the passed X-offset
 * param[in] y_offset - the passed Y-offset
 * @note The coordinates are limited. You cannot exceed the limit.
 */
void MoveFromCurrentPoint(Coordinate * const, offset_t, offset_t);

/**
 * @brief The public function of moving to the lower left corner of the area.
 * param[in] self - a pointer to the specified object
 */
void MoveToTheLowerLeftCorner(Coordinate * const);

/**
 * @brief The public function of moving to the upper left corner of the area.
 * param[in] self - a pointer to the specified object
 */
void MoveToTheUpperLeftCorner(Coordinate * const);

/**
 * @brief The public function of moving to the lower right corner of the area.
 * param[in] self - a pointer to the specified object
 */
void MoveToTheLowerRightCorner(Coordinate * const);

/**
 * @brief The public function of moving to the upper right corner of the area.
 * param[in] self - a pointer to the specified object
 */
void MoveToTheUpperRightCorner(Coordinate * const);

/**
 * @brief The public function of moving to the centre of the area.
 * param[in] self - a pointer to the specified object
 */
void MoveToTheCenter(Coordinate * const);

/**
 * @brief The public function to return the X-coordinate for the specified object.
 * param[in] self - a pointer to the specified object
 * @returns the value of the x-coordinate
 */
coordinate_t GetXCoordinate(Coordinate const * const);

/**
 * @brief The public function to return the Y-coordinate for the specified object.
 * param[in] self - a pointer to the specified object
 * @returns the value of the y-coordinate
 */
coordinate_t GetYCoordinate(Coordinate const * const);

#ifdef POLYMORPHISM

/**
 * @brief The public function for calculating the values of all perimeters
 * of the specified objects.
 * param[in] objects - an array of pointers to the specified objects
 * param[in] lenght - the length of the array
 */
void CalculateAllPerimeters(Coordinate const *[], size_t);

/**
 * @brief The public function for calculating the values of all areas
 * of the specified objects.
 * param[in] objects - an array of pointers to the specified objects
 * param[in] lenght - the length of the array
 */
void CalculateAllAreas(Coordinate const *[], size_t);

#endif /* POLYMORPHISM */
/******************************************************************************/
#endif /* !COORDINATE_H */
