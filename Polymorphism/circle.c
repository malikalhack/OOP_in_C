#include "circle.h" /* Rectangle class interface */
#include <stdio.h> /* for printf() */

void Circle_ctor(Circle * const self, int x, int y, unsigned int radius) {
	Coordinate_ctor(&self->super, x, y); /* call the superclass' ctor */
	//self->super.vptr = &vtbl; /* override the vptr */
	self->radius = radius;
}
