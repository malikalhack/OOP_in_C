/**
 * @file    main.c
 * @version 1.1.0
 * @authors Anton Chernov
 * @date    27/10/2022
 * @date    06/11/2022
 */

/****************************** Included files ********************************/
#include "test.h"
#include "coordinate.h" /* coordinate class interface */
/******************************** Definition **********************************/
#define ENABLE_QUICK_TEST   (1)
#define ENABLE_MOVE_TEST    (1)
#define ENABLE_OFFSET_TEST  (1)
/************************ Private  functions prototypes ***********************/
static void PrintCoordinatesOfBothPoints(Coordinate * const, Coordinate * const);
/********************************* Entry point ********************************/
int main(void) {
    Coordinate p1, p2; /* multiple instances of Coordinate */
    Coordinate_ctor(&p1, X_CENTER, Y_CENTER);
    Coordinate_ctor(&p2, X_CENTER, Y_CENTER);
    printf("[INFO] X-coordinates limited by range [0 : %3u]\n", X_LIMIT);
    printf("[INFO] Y-coordinates limited by range [0 : %3u]\n", Y_LIMIT);
    printf(
        "\nThe initial coordinates of the point p1(x: %3u, y: %3u)\n",
        GetXCoordinate(&p1),
        GetYCoordinate(&p1)
    );
    printf(
        "The initial coordinates of the point p2(x: %3u, y: %3u)\n\n",
        GetXCoordinate(&p2),
        GetYCoordinate(&p2)
    );
/*----------------------------------------------------------------------------*/
#if ENABLE_QUICK_TEST
    TEST_START("moving to the lower left corner of the area");
    MoveToTheLowerLeftCorner(&p1);
    MoveToTheLowerLeftCorner(&p2);
    PrintCoordinatesOfBothPoints(&p1, &p2);
    TEST_FINISH;
/*----------------------------------------------------------------------------*/
    TEST_START("moving to the upper left corner of the area");
    MoveToTheUpperLeftCorner(&p1);
    MoveToTheUpperLeftCorner(&p2);
    PrintCoordinatesOfBothPoints(&p1, &p2);
    TEST_FINISH;
/*----------------------------------------------------------------------------*/
    TEST_START("moving to the lower right corner of the area");
    MoveToTheLowerRightCorner(&p1);
    MoveToTheLowerRightCorner(&p2);
    PrintCoordinatesOfBothPoints(&p1, &p2);
    TEST_FINISH;
/*----------------------------------------------------------------------------*/
    TEST_START("moving to the upper right corner of the area");
    MoveToTheUpperRightCorner(&p1);
    MoveToTheUpperRightCorner(&p2);
    PrintCoordinatesOfBothPoints(&p1, &p2);
    TEST_FINISH;
/*----------------------------------------------------------------------------*/
    TEST_START("returning to the centre of the area");
    MoveToTheCenter(&p1);
    MoveToTheCenter(&p2);
    PrintCoordinatesOfBothPoints(&p1, &p2);
    TEST_FINISH;
#endif // ENABLE_QUICK_TEST
/*----------------------------------------------------------------------------*/
    do {
#if ENABLE_MOVE_TEST
        coordinate_t x, y;
        TEST_START("moving to specified coordinates");
        printf("Enter coordinates for point p1:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &x));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &y));
        MoveToCoordinate(&p1, x, y);
        printf("\nEnter coordinates for point p2:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &x));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &y));
        MoveToCoordinate(&p2, x, y);
        PrintCoordinatesOfBothPoints(&p1, &p2);
        TEST_FINISH;
#endif // ENABLE_MOVE_TEST
/*----------------------------------------------------------------------------*/
#if ENABLE_OFFSET_TEST
        offset_t xof, yof;
        TEST_START("moving to the specified offset");
        printf("Enter offset for point p1:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &xof));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &yof));
        MoveFromCurrentPoint(&p1, xof, yof);
        printf("\nEnter coordinates for point p2:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &xof));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &yof));
        MoveFromCurrentPoint(&p2, xof, yof);
        PrintCoordinatesOfBothPoints(&p1, &p2);
        TEST_FINISH;
#endif // ENABLE_OFFSET_TEST
    } while (DoRepeat());
/*----------------------------------------------------------------------------*/
    return 0;
}
/****************************** Private  functions ****************************/
static void PrintCoordinatesOfBothPoints(
    Coordinate * const p1,
    Coordinate * const p2
) {
    printf(
        "\nThe current coordinates of point p1 are (x: %3u; y: %3u)\n",
        GetXCoordinate(p1),
        GetYCoordinate(p1)
    );
    printf(
        "The current coordinates of point p2 are (x: %3u; y: %3u)\n\n",
        GetXCoordinate(p2),
        GetYCoordinate(p2)
    );
}
/******************************************************************************/
