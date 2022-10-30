/**
 * @file    rectangle.h
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    29/10/2022
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H
/****************************** Included files ********************************/
#include "coordinate.h" /* coordinate class interface */
/******************************** Definition **********************************/
#define WIDTH_LIMIT     (50u)
#define LENGTH_LIMIT    (50u)

#if !(WIDTH_LIMIT && LENGTH_LIMIT)
    #error Rectangle limits are wrong
#endif //Checking limits

typedef uint16_t params_t;

/* Rectangle's attributes... */
typedef struct {
    Coordinate super;   ///< Inheritance of the coordinate functional
    /* attributes added by this subclass... */
    params_t width;     ///< the width of a rectangle
    params_t length;    ///< the length of a rectangle
} Rectangle;
/*************** Application Programming Interface prototypes *****************/

/**
 * @brief Constructor function
 * @details Initializes the specified object with the passed coordinates,
 * length and width
 * param[in] self - a pointer to the specified object
 * param[in] x - the passed X-coordinate
 * param[in] y - the passed Y-coordinate
 * param[in] y - the passed width
 * param[in] y - the passed length
 * @note The coordinates are limited. An exception will be thrown if you try to
 * go beyond the limit.
 */
void Rectangle_ctor(
    Rectangle * const, coordinate_t, coordinate_t, params_t, params_t
);

/**
 * @brief The function to return the length for the specified object.
 * param[in] self - a pointer to the specified object
 */
params_t GetLength(Rectangle * const);

/**
 * @brief The function to return the width for the specified object.
 * param[in] self - a pointer to the specified object
 */
params_t GetWidth(Rectangle * const);
/******************************************************************************/
#endif /* !RECTANGLE_H */
