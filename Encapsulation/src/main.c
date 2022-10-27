/**
 * @file    main.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    28/10/2022
 */

/****************************** Included files ********************************/
#include <stdio.h>
#include "coordinate.h" /* coordinate class interface */
/********************************* Entry point ********************************/
int main(void) {
    Coordinate p1, p2; /* multiple instances of Coordinate */
    Coordinate_ctor(&p1, 0, 0);
    Coordinate_ctor(&p2, 0, 0);

    printf(
        "The initial coordinates of the point p1(x: %4u, y: %4u)\n",
        GetXCoordinate(&p1),
        GetYCoordinate(&p1)
    );
    printf(
        "The initial coordinates of the point p2(x: %4u, y: %4u)\n\n",
        GetXCoordinate(&p2),
        GetYCoordinate(&p2)
    );
    getchar();
    return 0;
}
/******************************************************************************/
