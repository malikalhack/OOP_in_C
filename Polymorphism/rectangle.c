#include <stdio.h>
#include "rectangle.h"	/* Rectangle class interface */

/* constructor implementation */
void Rectangle_ctor(Rectangle * const self, int x, int y,
	unsigned int width, unsigned int length) {
	static struct CoordinateVtbl const vtbl = {	//vtbl of the Rectangle class
		&Rectangle_area_,
		&Rectangle_draw_
	};
	Coordinate_ctor(&self->super, x, y); /* call the superclass' ctor */
	self->super.vptr = &vtbl; /* override the vptr */
	self->width = width;
	self->length = length;
}

/* Rectangle's class implementations of its virtual functions... */
static uint32_t Rectangle_area_(Coordinate const * const self) {
	Rectangle const * const self_ = (Rectangle const *)self; /* explicit downcast */
	return (uint32_t)self_->width * (uint32_t)self_->length;
}

static void Rectangle_draw_(Coordinate const * const self) {
	Rectangle const * const self_ = (Rectangle const *)self; /* explicit downcast */
	printf("Rectangle_draw_(x=%d,y=%d,width=%d,height=%d)\n",
		self_->super.x, self_->super.y, self_->width, self_->length);
}
