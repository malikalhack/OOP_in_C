#ifndef RECT_H
#define RECT_H
#include "coordinate.h" /* coordinate class interface */

/* Rectangle's attributes... */
typedef struct {
    Coordinate super; /* <== inherits Shape */
    /* attributes added by this subclass... */
    unsigned int width;
    unsigned int height;
} Rectangle;

/* constructor prototype */
void Rectangle_ctor(Rectangle *, int, int, unsigned int, unsigned int);

#endif /* RECT_H */
