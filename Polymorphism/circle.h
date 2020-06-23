#ifndef CIRCLE_H
#define CIRCLE_H
#include "coordinate.h" /* coordinate class interface */
/* Rectangle's attributes... */
typedef struct {
    Coordinate super; /* <== inherits Shape */
    /* attributes added by this subclass... */
    unsigned int width;
    unsigned int height;
} Circle;
/* constructor prototype */
void Circle_ctor(Circle * const self, int x, int y,
                    unsigned int width, unsigned int height);
#endif /* CIRCLE_H */