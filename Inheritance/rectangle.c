#include "rectangle.h"
/* constructor implementation */
void Rectangle_ctor(Rectangle * const self, int x, int y,
                    unsigned int width, unsigned int height)
{
    /* first call superclass’ ctor */
	Coordinate_ctor(&self->super, x, y);
    /* next, you initialize the attributes added by this subclass... */
    self->width = width;
    self->height = height;
}
