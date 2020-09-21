#include <stdio.h>
#include <assert.h>		/*for displaying an error message and terminating the program*/
#include "coordinate.h" /* coordinate class interface */

#define UPPER_LIMIT  100
#define LOWER_LIMIT -100

/* constructor implementation */
void Coordinate_ctor(Coordinate * const self, int16_t x, int16_t y) {
	static struct CoordinateVtbl const vtbl = { //vtbl of the Coordinate class
		&Coordinate_area_,
		&Coordinate_draw_
	};
	self->vptr = &vtbl; /* "hook" the vptr to the vtbl */
	self->x = x;
	self->y = y;
}

/* move-by operation implementation */
void Coordinate_moveBy(Coordinate * const self, int16_t dx, int16_t dy) {
	uint8_t act = 1;

	if (dx < 0) {
		if (self->x < 0) {
			if ((LOWER_LIMIT - dx) > self->x) {
				self->x = LOWER_LIMIT;
				act = 0;
			}
		}
		else {
			if ((dx + self->x) < LOWER_LIMIT) {
				self->x = LOWER_LIMIT;
				act = 0;
			}
		}
	}
	else {
		if (self->x < 0) {
			if ((dx + self->x) > UPPER_LIMIT) {
				self->x = UPPER_LIMIT;
				act = 0;
			}
		}
		else {
			if ((UPPER_LIMIT - dx) < self->x) {
				self->x = UPPER_LIMIT;
				act = 0;
			}
		}
	}
	if (act) self->x += dx;

	act = 1;

	if (dy < 0) {
		if (self->y < 0) {
			if ((LOWER_LIMIT - dy) > self->y) {
				self->y = LOWER_LIMIT;
				act = 0;
			}
		}
		else {
			if ((dy + self->y) < LOWER_LIMIT) {
				self->y = LOWER_LIMIT;
				act = 0;
			}
		}
	}
	else {
		if (self->y < 0) {
			if ((dy + self->y) > UPPER_LIMIT) {
				self->y = UPPER_LIMIT;
				act = 0;
			}
		}
		else {
			if ((UPPER_LIMIT - dy) < self->y) {
				self->y = UPPER_LIMIT;
				act = 0;
			}
		}
	}
	if (act) self->y += dy;
}

/* Coordinate class implementations of its virtual functions... */
static uint32_t Coordinate_area_(Coordinate const * const self) {
	assert(0); /* purely-virtual function should never be called */
	return 0; /* to avoid compiler warnings */
}

static void Coordinate_draw_(Coordinate const * const self) {
	assert(0); /* purely-virtual function should never be called */
}

/* The following code will draw all Coordinates on the screen */
void drawAllCoordinates(Coordinate const *coordinates[], uint32_t length) {
	for (uint8_t i = 0; i < length; ++i) {
		Coordinate_draw(coordinates[i]); /* virtual call */
	}
}

/* The following code will draw all the area values of the figures on the screen. */
void drawAllAreas(Coordinate const *coordinates[], uint32_t length) {
	for (uint8_t i = 0; i < length; ++i) {
		printf("The area of %d figure is %i\n", i, Coordinate_area(coordinates[i])); /* virtual call */	
	}
}
