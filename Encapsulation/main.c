#include "coordinate.h" /* coordinate class interface */
#include <stdio.h>  /* for printf() */

int main() {
	char answer = 'n';
    Coordinate p1, p2; /* multiple instances of Coordinate */
    Coordinate_ctor(&p1, 0, 0);
    Coordinate_ctor(&p2, 0, 0);
	printf("Test program moving two points given by x and y coordinates\n");
	printf("WARNING! Coordinates are limited to a range of - 100 to 100\n");
	printf("\nStarting coordinates p1(x=%d,y=%d)\n", Coordinate_getX(&p1), Coordinate_getY(&p1));
	printf("Starting coordinates p2(x=%d,y=%d)\n\n", Coordinate_getX(&p2), Coordinate_getY(&p2));

	do {
		int x, y;
		char temp;
		printf("\nEnter the coordinate offset (x, y) of point p1: ");
		fflush(stdin);
		scanf("%d %d", &x, &y);
		Coordinate_moveBy(&p1, x, y);		
		
		printf("Enter the coordinate offset (x, y) of point p2: ");
		fflush(stdin);
		scanf("%d %d", &x, &y);
		Coordinate_moveBy(&p2, x, y);

		printf("New coordinate p1(x=%d,y=%d)\n", Coordinate_getX(&p1), Coordinate_getY(&p1));
		printf("New coordinate p2(x=%d,y=%d)\n\n", Coordinate_getX(&p2), Coordinate_getY(&p2));
		

		printf("Do you want to continue? (Y):");
		fflush(stdin);
		scanf("%c %c", &temp, &answer);
		printf("\n");
	} while ((answer=='y')||(answer == 'Y'));

    return 0;
}