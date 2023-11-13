/**
 * @file    main.c
 * @version 1.1.1
 * @authors Anton Chernov
 * @date    01/11/2022
 * @date    06/11/2022
 */

 /****************************** Included files ********************************/
#include "test.h"
#include "rectangle.h"  /* rectangle class interface */
#include "circle.h"     /* circle class interface */
/******************************** Definition **********************************/
#define ENABLE_QUICK_TEST   (1)
#define ENABLE_COMMON_TEST  (1)
#define ENABLE_MOVE_TEST    (1)
#define ENABLE_OFFSET_TEST  (1)

#define SUPER_UPCAST(ptr_) ((Coordinate *)(ptr_))
/************************ Private  functions prototypes ***********************/
static void PrintCoordinatesOfBothRectangles(
    Rectangle const * const, Rectangle const * const
);
static void PrintCoordinatesOfBothCircles(
    Circle const * const, Circle const * const
);
/********************************* Entry point ********************************/
int main(void) {
    Rectangle r1, r2; /* multiple instances of Rectangle */
    Circle c1, c2; /* multiple instances of Circle */
    printf("[INFO] X-coordinates limited by range [0 : %3u]\n", X_LIMIT);
    printf("[INFO] Y-coordinates limited by range [0 : %3u]\n", Y_LIMIT);
    printf("[INFO] Radius limited by %3u\n", RADIUS_LIMIT);
    printf("[INFO] Length limited by %3u\n", LENGTH_LIMIT);
    printf("[INFO] Width limited by %3u\n", WIDTH_LIMIT);
/*----------------------------------------------------------------------------*/
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
    } {
        radius_t r;
        printf("\nEnter the radius of circle c1: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &r));
        Circle_ctor(&c1, r);

        printf("\nEnter the radius of circle c2: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &r));
        Circle_ctor(&c2, r);
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
    printf(
        "\nInitial coordinates of the center point of c1(x: %3u, y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(&c1)),
        GetYCoordinate(SUPER_UPCAST(&c1))
    );
    printf(
        "Initial coordinates of the center point of c2(x: %3u, y: %3u)\n\n",
        GetXCoordinate(SUPER_UPCAST(&c2)),
        GetYCoordinate(SUPER_UPCAST(&c2))
    );
/*----------------------------------------------------------------------------*/
#if ENABLE_COMMON_TEST
    {
        Coordinate const *objects[4]; /* collection of coordinates */
        objects[0] = SUPER_UPCAST(&r1);
        objects[1] = SUPER_UPCAST(&r2);
        objects[2] = SUPER_UPCAST(&c1);
        objects[3] = SUPER_UPCAST(&c2);
        size_t len = sizeof(objects) / sizeof(objects[0]);
        CalculateAllAreas(objects, len);
        CalculateAllPerimeters(objects, len);
    }
#endif // ENABLE_QUICK_TEST
/*----------------------------------------------------------------------------*/
#if ENABLE_QUICK_TEST
    TEST_START("moving to the lower left corner of the area");
    MoveToTheLowerLeftCorner(SUPER_UPCAST(&r1));
    MoveToTheLowerLeftCorner(SUPER_UPCAST(&r2));
    MoveToTheLowerLeftCorner(SUPER_UPCAST(&c1));
    MoveToTheLowerLeftCorner(SUPER_UPCAST(&c2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    PrintCoordinatesOfBothCircles(&c1, &c2);
    TEST_FINISH;
/*----------------------------------------------------------------------------*/
    TEST_START("moving to the upper left corner of the area");
    MoveToTheUpperLeftCorner(SUPER_UPCAST(&r1));
    MoveToTheUpperLeftCorner(SUPER_UPCAST(&r2));
    MoveToTheUpperLeftCorner(SUPER_UPCAST(&c1));
    MoveToTheUpperLeftCorner(SUPER_UPCAST(&c2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    PrintCoordinatesOfBothCircles(&c1, &c2);
    TEST_FINISH;
    /*----------------------------------------------------------------------------*/
    TEST_START("moving to the lower right corner of the area");
    MoveToTheLowerRightCorner(SUPER_UPCAST(&r1));
    MoveToTheLowerRightCorner(SUPER_UPCAST(&r2));
    MoveToTheLowerRightCorner(SUPER_UPCAST(&c1));
    MoveToTheLowerRightCorner(SUPER_UPCAST(&c2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    PrintCoordinatesOfBothCircles(&c1, &c2);
    TEST_FINISH;
/*----------------------------------------------------------------------------*/
    TEST_START("moving to the upper right corner of the area");
    MoveToTheUpperRightCorner(SUPER_UPCAST(&r1));
    MoveToTheUpperRightCorner(SUPER_UPCAST(&r2));
    MoveToTheUpperRightCorner(SUPER_UPCAST(&c1));
    MoveToTheUpperRightCorner(SUPER_UPCAST(&c2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    PrintCoordinatesOfBothCircles(&c1, &c2);
    TEST_FINISH;
/*----------------------------------------------------------------------------*/
    TEST_START("returning to the centre of the area");
    MoveToTheCenter(SUPER_UPCAST(&r1));
    MoveToTheCenter(SUPER_UPCAST(&r2));
    MoveToTheCenter(SUPER_UPCAST(&c1));
    MoveToTheCenter(SUPER_UPCAST(&c2));
    PrintCoordinatesOfBothRectangles(&r1, &r2);
    PrintCoordinatesOfBothCircles(&c1, &c2);
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

        printf("\nEnter coordinates for center point of the circle c1:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &x));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &y));
        MoveToCoordinate(SUPER_UPCAST(&c1), x, y);

        printf("\nEnter coordinates for center point of the circle c2:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &x));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hu", &y));
        MoveToCoordinate(SUPER_UPCAST(&c2), x, y);

        PrintCoordinatesOfBothRectangles(&r1, &r2);
        PrintCoordinatesOfBothCircles(&c1, &c2);
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

        printf("\nEnter offset for center point of the circle c1:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &xof));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &yof));
        MoveFromCurrentPoint(SUPER_UPCAST(&c1), xof, yof);

        printf("\nEnter offset for center point of the circle c2:\nx: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &xof));
        printf("y: ");
        fflush(stdout);
        DISCARD_RETURN(scanf(" %hd", &yof));
        MoveFromCurrentPoint(SUPER_UPCAST(&c2), xof, yof);

        PrintCoordinatesOfBothRectangles(&r1, &r2);
        PrintCoordinatesOfBothCircles(&c1, &c2);
        TEST_FINISH;
#endif // ENABLE_OFFSET_TEST
    } while (DoRepeat());
    return 0;
}
/****************************** Private  functions ****************************/
static void PrintCoordinatesOfBothRectangles(
    Rectangle const * const r1,
    Rectangle const * const r2
) {
    printf("\nThe rectangle r1 with width %2u and length %2u\n",
        GetWidth(r1),
        GetLength(r1)
    );
    printf(
        "Current coordinates of its centre are (x: %3u; y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(r1)),
        GetYCoordinate(SUPER_UPCAST(r1))
    );
    printf("\nThe rectangle r2 with width %2u and length %2u\n",
        GetWidth(r2),
        GetLength(r2)
    );
    printf(
        "Current coordinates of its centre are (x: %3u; y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(r2)),
        GetYCoordinate(SUPER_UPCAST(r2))
    );
}
/*----------------------------------------------------------------------------*/
static void PrintCoordinatesOfBothCircles(
    Circle const * const c1,
    Circle const * const c2
) {
    printf("\nThe circle c1 with radius %2u\n", GetRadius(c1));
    printf(
        "Current coordinates of its centre are (x: %3u; y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(c1)),
        GetYCoordinate(SUPER_UPCAST(c1))
    );
    printf("\nThe circle c1 with radius %2u\n", GetRadius(c2));
    printf(
        "Current coordinates of its centre are (x: %3u; y: %3u)\n",
        GetXCoordinate(SUPER_UPCAST(c2)),
        GetYCoordinate(SUPER_UPCAST(c2))
    );
}
/******************************************************************************/
