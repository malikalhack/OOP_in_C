#include "coordinate.h" /* coordinate class interface */
#include "rectangle.h"  /* Rectangle class interface */
#include "circle.h" /* Circle class interface */
#include <stdio.h>  /* for printf() */
int main() {
    Rectangle r1, r2; /* multiple instances of Rectangle */
    Circle    c1, c2; /* multiple instances of Circle */
    Coordinate const *coordinates[] = { /* collection of coordinates */
        &c1.super,
        &r2.super,
        &c2.super,
        &r1.super
    };
    Coordinate const *s;
    /* instantiate rectangles... */
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);
    /* instantiate circles... */
    Circle_ctor(&c1, 1, -2, 12);
    Circle_ctor(&c2, 1, -3, 6);
    s = largestCoordinate(coordinates, sizeof(coordinates)/sizeof(coordinates[0]));
    printf("largetsCoordinate s(x=%d,y=%d)\n",
           Coordinate_getX(&s), Coordinate_getY(&s));
    drawAllCoordinates(coordinates, sizeof(coordinates)/sizeof(coordinates[0]));
	getchar();
    return 0;
}
