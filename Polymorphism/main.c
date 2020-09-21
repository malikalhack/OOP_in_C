#include <stdio.h>
#include "coordinate.h"					/* coordinate class interface */
#include "rectangle.h"					/* Rectangle class interface */
#include "circle.h"						/* Circle class interface */

int main() {
	printf("WARNING! Coordinates are limited to a range of - 100 to 100\n");
	Rectangle r1, r2;					/* multiple instances of Rectangle */
	Circle    c1, c2;					/* multiple instances of Circle */
	Coordinate const *coordinates[] = { // collection of coordinates
		&r1.super,
		&r2.super,
		&c1.super,
		&c2.super,
	};
	uint32_t len = sizeof(coordinates) / sizeof(coordinates[0]);
	{
		unsigned int l, w;
		/* instantiate rectangles... */
		printf("\nEnter the length and width of rectangle r1: ");
		fflush(stdout);
		scanf("%d %d", &l, &w);
		fflush(stdin);
		Rectangle_ctor(&r1, 0, 0, w, l);
		printf("Enter the length and width of rectangle r2: ");
		fflush(stdout);
		scanf("%d %d", &l, &w);
		fflush(stdin);
		Rectangle_ctor(&r2, 0, 0, w, l);
		
		/* instantiate circles... */
		printf("\nEnter the radius of circle c1: ");
		fflush(stdout);
		scanf("%d", &l);
		fflush(stdin);
		Circle_ctor(&c1, 0, 0, l);
		printf("\nEnter the radius of circle c2: ");
		fflush(stdout);
		scanf("%d", &l);
		fflush(stdin);
		Circle_ctor(&c2, 0, 0, l);
	}
	printf("\nDrawing all coordinates: \n");
	drawAllCoordinates(coordinates, len);

	printf("\nDrawing all areas: \n");
	drawAllAreas(coordinates, len);
	fflush(stdout);

	getchar();
	getchar();
    return 0;
}
