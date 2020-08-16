#include "coordinate.h" /* coordinate class interface */
#include "rectangle.h"  /* Rectangle class interface */
#include "circle.h" /* Circle class interface */
#include <stdio.h>  /* for printf() */

int main() {
	Rectangle r1, r2; /* multiple instances of Rectangle */
	Circle    c1, c2; /* multiple instances of Circle */
	Coordinate const *coordinates[] = { // collection of coordinates
		&c1.super,
		&r1.super,
		&c2.super,
		&r2.super
	};
	/* instantiate rectangles... */
	Rectangle_ctor(&r1, 0, 0, 10, 15);
	Rectangle_ctor(&r2, 0, 0, 5, 8);
	/* instantiate circles... */
	Circle_ctor(&c1, 0, 0, 12);
	Circle_ctor(&c2, 0, 0, 6);

	drawAllCoordinates(coordinates, sizeof(coordinates) / sizeof(coordinates[0]));

	getchar();
    return 0;
}
