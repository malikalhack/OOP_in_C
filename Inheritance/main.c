#include "coordinate.h" /* coordinate class interface */
#include "rectangle.h"  /* Rectangle class interface */
#include <stdio.h>  /* for printf() */

int main() {
	char answer = 'n';
    Rectangle r1, r2; /* multiple instances of Rectangle */
    /* instantiate rectangles... */
    
    Rectangle_ctor(&r2, 0, 0, 20, 25);
	printf("The test program moves two rectangles defined by the initial coordinates (x, y), height and width.\n");
	printf("WARNING! Coordinates are limited to a range of - 100 to 100\n");
	{
		unsigned int l, w;
		printf("\nEnter the length and width of rectangle r1: ");
		fflush(stdout);
		scanf("%d %d", &l, &w);
		Rectangle_ctor(&r1, 0, 0, w, l);
		printf("Enter the length and width of rectangle r2: ");
		fflush(stdout);
		scanf("%d %d", &l, &w);
		Rectangle_ctor(&r2, 0, 0, w, l);
	}

	printf("\nStarting coordinates of a rectangle r1 with length=%d and width=%d: x=%d,y=%d \n",
		r1.length, r1.width, r1.super.x, r1.super.y);
	printf("Starting coordinates of a rectangle r2 with length=%d and width=%d: x=%d,y=%d \n",
		r2.length, r2.width, r2.super.x, r2.super.y);

	do {
		/* re-use inherited function from the superclass Coordinate... */
		int x, y;
		char temp;
		printf("\nEnter the coordinate offset (x, y) of rectangle r1: ");
		fflush(stdout);
		scanf("%d %d", &x, &y);
		Coordinate_moveBy((Coordinate *)&r1, x, y);

		printf("Enter the coordinate offset (x, y) of rectangle r2: ");
		fflush(stdout);
		scanf("%d %d", &x, &y);
		Coordinate_moveBy(&r2.super, x, y);

		printf("\New coordinates of a rectangle r1 with length=%d and width=%d: x=%d,y=%d \n",
			r1.length, r1.width, r1.super.x, r1.super.y);
		printf("\New coordinates of a rectangle r2 with length=%d and width=%d: x=%d,y=%d \n",
			r2.length, r2.width, r2.super.x, r2.super.y);

		printf("Do you want to continue? (Y):");
		fflush(stdout);
		scanf("%c %c", &temp, &answer);
		printf("\n");

	} while ((answer == 'y') || (answer == 'Y'));

    return 0;
}
