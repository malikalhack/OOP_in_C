#include "circle.h" /* Rectangle class interface */
#include <stdio.h> /* for printf() */

/* constructor implementation */
void Circle_ctor(Circle * const self, int x, int y, unsigned int radius) {
	static struct CoordinateVtbl const vtbl = { //vtbl of the Rectangle class
		&Circle_area_,
		&Circle_draw_
	};
	Coordinate_ctor(&self->super, x, y); /* call the superclass' ctor */
	self->super.vptr = &vtbl; /* override the vptr */
	self->radius = radius;
}

/* Rectangle's class implementations of its virtual functions... */
static uint32_t Circle_area_(Coordinate const * const self) {
	Circle const * const self_ = (Circle const *)self; /* explicit downcast */
	return (uint32_t)self_->radius * PI;
}

static void Circle_draw_(Coordinate const * const self) {
	Circle const * const self_ = (Circle const *)self; /* explicit downcast */
	printf("Rectangle_draw_(x=%d,y=%d,radius=%d)\n",
		self_->super.x, self_->super.y, self_->radius);
}
