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
 * @brief Function for moving along the specified coordinates.
 * param[in] self - a pointer to the specified object
 * param[in] x - the passed new X-coordinate
 * param[in] y - the passed new Y-coordinate
 * @note The coordinates are limited. You cannot exceed the limit.
 */
void MoveToCoordinate(Coordinate * const, coordinate_t, coordinate_t);

/**
 * @details The function of moving from the current coordinates
 * to the specified offset.
 * param[in] self - a pointer to the specified object
 * param[in] x_offset - the passed X-offset
 * param[in] y_offset - the passed Y-offset
 * @note The coordinates are limited. You cannot exceed the limit.
 */
void MoveFromCurrentPoint(Coordinate * const, offset_t, offset_t);

/**
 * @brief The function of moving to the lower left corner of the area.
 * param[in] self - a pointer to the specified object
 */
void StandInTheLowerLeftCorner(Coordinate * const);

/**
 * @brief The function of moving to the upper left corner of the area.
 * param[in] self - a pointer to the specified object
 */
void StandInTheUpperLeftCorner(Coordinate * const);

/**
 * @brief The function of moving to the lower right corner of the area.
 * param[in] self - a pointer to the specified object
 */
void StandInTheLowerRightCorner(Coordinate * const);

/**
 * @brief The function of moving to the upper right corner of the area.
 * param[in] self - a pointer to the specified object
 */
void StandInTheUpperRightCorner(Coordinate * const);

/**
 * @brief The function of moving to the centre of the area.
 * param[in] self - a pointer to the specified object
 */
void StandInTheCenter(Coordinate * const);

/**
 * @brief The function to return the X-coordinate for the specified object.
 * param[in] self - a pointer to the specified object
 */
coordinate_t GetXCoordinate(Coordinate * const);

/**
 * @brief The function to return the Y-coordinate for the specified object.
 * param[in] self - a pointer to the specified object
 */
coordinate_t GetYCoordinate(Coordinate * const);
/******************************************************************************/
#endif /* !COORDINATE_H */
