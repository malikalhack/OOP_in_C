#ifndef RECT_H
#define RECT_H
#include "coordinate.h" /* coordinate class interface */

/* Rectangle's prototypes of its virtual functions */
/* NOTE: the "self" pointer has the type of the superclass to fit the vtable */
static uint32_t Rectangle_area_(Coordinate const * const);
static void Rectangle_draw_(Coordinate const * const);

/* Rectangle's attributes... */
typedef struct {
	Coordinate super; /* inherits Coordinate */
	/* attributes added by this subclass... */
	unsigned int width;
	unsigned int length;
} Rectangle;

/* constructor prototype */
void Rectangle_ctor(Rectangle * const, int, int, unsigned int, unsigned int);

#endif /* RECT_H */
