/**
 * @file    main.c
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    29/10/2022
 * @date    06/11/2022
 */

/****************************** Included files ********************************/
#include "test.h"
#include "rectangle.h" /* rectangle class interface */
/******************************** Definition **********************************/
#define ENABLE_QUICK_TEST   (1)
#define ENABLE_MOVE_TEST    (1)
#define ENABLE_OFFSET_TEST  (1)

#define SUPER_UPCAST(ptr_) ((Coordinate *)(ptr_))
/************************ Private  functions prototypes ***********************/
static void PrintCoordinatesOfBothRectangles(Rectangle * const, Rectangle * const);
/********************************* Entry point ********************************/
int main(void) {
    Rectangle r1, r2; /* multiple instances of Rectangle */
    printf("[INFO] X-coordinates limited by range [0 : %3u]\n", X_LIMIT);
    printf("[INFO] Y-coordinates limited by range [0 : %3u]\n", Y_LIMIT);
    printf("[INFO] Length limited by %3u\n", LENGTH_LIMIT);
    printf("[INFO] Width limited by %3u\n", WIDTH_LIMIT);
    {
        params_t l, w;
        printf("\nEnter the width of rectangle r1: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &w));
        printf("Enter the length of rectangle r1: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &l));
        Rectangle_ctor(&r1, w, l);

        printf("\nEnter the width of rectangle r2: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &w));
        printf("Enter the length of rectangle r2: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &l));
        Rectangle_ctor(&r2, w, l);
    }
    printf(
        "\nInitial coordinates of the center point of r1(x: %3u, y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(&r1)),
        GetYCoordinate(SUPER_UPCAST(&r1))
    );
    printf(
        "Initial coordinates of the center point of r2(x: %3u, y: %3u)\n\n",
        GetXCoordinate(SUPER_UPCAST(&r2)),
        GetYCoordinate(SUPER_UPCAST(&r2))
    );
/*----------------------------------------------------------------------------*/
#if ENABLE_QUICK_TEST
    TEST_START("moving to the lower left corner of the area");
    MoveToTheLowerLeftCorner(SUPER_UPCAST(&r1));
    MoveToTheLowerLeftCorner(SUPER_UPCAST(&r2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    TEST_FINISH;
    /*----------------------------------------------------------------------------*/
    TEST_START("moving to the upper left corner of the area");
    MoveToTheUpperLeftCorner(SUPER_UPCAST(&r1));
    MoveToTheUpperLeftCorner(SUPER_UPCAST(&r2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    TEST_FINISH;
    /*----------------------------------------------------------------------------*/
    TEST_START("moving to the lower right corner of the area");
    MoveToTheLowerRightCorner(SUPER_UPCAST(&r1));
    MoveToTheLowerRightCorner(SUPER_UPCAST(&r2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    TEST_FINISH;
    /*----------------------------------------------------------------------------*/
    TEST_START("moving to the upper right corner of the area");
    MoveToTheUpperRightCorner(SUPER_UPCAST(&r1));
    MoveToTheUpperRightCorner(SUPER_UPCAST(&r2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    TEST_FINISH;
    /*----------------------------------------------------------------------------*/
    TEST_START("returning to the centre of the area");
    MoveToTheCenter(SUPER_UPCAST(&r1));
    MoveToTheCenter(SUPER_UPCAST(&r2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    TEST_FINISH;
#endif // ENABLE_QUICK_TEST
    /*----------------------------------------------------------------------------*/
    do {
#if ENABLE_MOVE_TEST
        coordinate_t x, y;
        TEST_START("moving to specified coordinates");
        printf("Enter coordinates for center point of the rectangle r1:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &x));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &y));
        MoveToCoordinate(SUPER_UPCAST(&r1), x, y);
        printf("\nEnter coordinates for center point of the rectangle r2:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &x));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &y));
        MoveToCoordinate(SUPER_UPCAST(&r2), x, y);
        PrintCoordinatesOfBothRectangles(&r1, &r2);
        TEST_FINISH;
#endif // ENABLE_MOVE_TEST
        /*----------------------------------------------------------------------------*/
#if ENABLE_OFFSET_TEST
        offset_t xof, yof;
        TEST_START("moving to the specified offset");
        printf("Enter offset for center point of the rectangle r1:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &xof));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &yof));
        MoveFromCurrentPoint(SUPER_UPCAST(&r1), xof, yof);
        printf("\nEnter offset for center point of the rectangle r2:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &xof));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &yof));
        MoveFromCurrentPoint(SUPER_UPCAST(&r2), xof, yof);
        PrintCoordinatesOfBothRectangles(&r1, &r2);
        TEST_FINISH;
#endif // ENABLE_OFFSET_TEST
    } while (DoRepeat());
/*----------------------------------------------------------------------------*/
    return 0;
}
/****************************** Private  functions ****************************/
static void PrintCoordinatesOfBothRectangles(
    Rectangle * const r1,
    Rectangle * const r2
) {
    printf("\nThe rectangle r1 with length %2u and width %2u\n",
        GetLength(r1),
        GetWidth(r1)
    );
    printf(
        "Current coordinates of its centre are (x: %3u; y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(r1)),
        GetYCoordinate(SUPER_UPCAST(r1))
    );
    printf("\nThe rectangle r2 with length %2u and width %2u\n",
        GetLength(r2),
        GetWidth(r2)
    );
    printf(
        "Current coordinates of its centre are (x: %3u; y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(r2)),
        GetYCoordinate(SUPER_UPCAST(r2))
    );
}
/******************************************************************************/
