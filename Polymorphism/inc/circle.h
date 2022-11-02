/**
 * @file    circle.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    01/11/2022
 * @date    02/11/2022
 */

#ifndef CIRCLE_H
#define CIRCLE_H
/****************************** Included files ********************************/
#include "coordinate.h" /* coordinate class interface */
/******************************** Definition **********************************/
#define PI 3.14159265359f

#define RADIUS_LIMIT     (50u)

#if (RADIUS_LIMIT > X_LIMIT-2) || (RADIUS_LIMIT > Y_LIMIT-2) || !(RADIUS_LIMIT)
    #error Circle limit is wrong
#endif //Checking limits
/*----------------------------------------------------------------------------*/
typedef uint16_t radius_t;

/* Circle's attributes... */
typedef struct {
    Coordinate super;   ///< Inheritance of the coordinate functional
    /* attributes added by this subclass... */
    radius_t radius;     ///< the radius of a circle
} Circle;
/*************** Application Programming Interface prototypes *****************/

/**
 * @brief Constructor function
 * @details Initializes the specified object with the passed radius
 * param[in] self - a pointer to the specified object
 * param[in] radius - the passed radius
 * @note The coordinates are limited. An exception will be thrown if you try
 * to go beyond the limit.
 */
void Circle_ctor(Circle * const, radius_t);

/**
 * @brief The function to return the length for the specified object.
 * param[in] self - a pointer to the specified object
 * @returns the value of the radius
 */
radius_t GetRadius(Circle const * const);

/******************************************************************************/
#endif /* !CIRCLE_H */
