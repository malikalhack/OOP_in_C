#include "coordinate.h" /* coordinate class interface */
#include <stdio.h>  /* for printf() */

int main() {
    Coordinate p1, p2; /* multiple instances of Shape */
    Coordinate_ctor(&p1, 0, 1);
    Coordinate_ctor(&p2, -1, 2);

    printf("Coordinate p1(x=%d,y=%d)\n", Coordinate_getX(&p1), Coordinate_getY(&p1));
    printf("Coordinate p2(x=%d,y=%d)\n", Coordinate_getX(&p2), Coordinate_getY(&p2));

    Coordinate_moveBy(&p1, 2, -4);
    Coordinate_moveBy(&p2, 1, -2);

    printf("Coordinate p1(x=%d,y=%d)\n", Coordinate_getX(&p1), Coordinate_getY(&p1));
    printf("Coordinate p2(x=%d,y=%d)\n", Coordinate_getX(&p2), Coordinate_getY(&p2));
	
	getchar();
    return 0;
}