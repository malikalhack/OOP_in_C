#ifndef CIRCLE_H
#define CIRCLE_H
#include "coordinate.h" /* coordinate class interface */

#define PI 3.14159265359f

/* Circle's prototypes of its virtual functions */
/* NOTE: the "self" pointer has the type of the superclass to fit the vtable */
static uint32_t Circle_area_(Coordinate const * const );
static void Circle_draw_(Coordinate const * const);

/* Circle's attributes... */
typedef struct {
	Coordinate super; /* inherits Coordinate */
	/* attributes added by this subclass... */
	unsigned int radius;
} Circle;

/* constructor prototype */
void Circle_ctor(Circle * const, int, int, unsigned int);

#endif /* CIRCLE_H */
