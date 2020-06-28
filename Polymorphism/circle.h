#ifndef CIRCLE_H
#define CIRCLE_H
#include "coordinate.h" /* coordinate class interface */

/* Rectangle's attributes... */
typedef struct {
    Coordinate super; /* inherits Coordinate */
    /* attributes added by this subclass... */
    unsigned int radius;
} Circle;

/* constructor prototype */
void Circle_ctor (Circle * const, int, int, unsigned int);

#endif /* CIRCLE_H */