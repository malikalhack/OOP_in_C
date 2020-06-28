#include "coordinate.h" /* coordinate class interface */
#include <assert.h>
#define UPPER_LIMIT  100
#define LOWER_LIMIT -100

/* Coordinate's prototypes of its virtual functions */
static uint32_t Coordinate_area_(Coordinate const * const self);
static void Coordinate_draw_(Coordinate const * const self);

/* constructor implementation */
void Coordinate_ctor(Coordinate * const self, int16_t x, int16_t y) {
    static struct CoordinateVtbl const vtbl = { /* vtbl of the Coordinate class */
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
    return 0U; /* to avoid compiler warnings */
}

static void Coordinate_draw_(Coordinate const * const self) {
    assert(0); /* purely-virtual function should never be called */
}

/* the following code finds the largest-area Coordinate in the collection */
Coordinate const *largestCoordinate(Coordinate const *coordinates[], uint32_t nCoordinates) {
    Coordinate const *s = (Coordinate *)0;
    uint32_t max = 0U;
    uint32_t i;
    for (i = 0U; i < nCoordinates; ++i) {
        uint32_t area = Coordinate_area(coordinates[i]); /* virtual call */
        if (area > max) {
            max = area;
            s = coordinates[i];
        }
    }
    return s; /* the largest Coordinate in the array coordinates[] */
}

/* The following code will draw all Coordinates on the screen */
void drawAllCoordinates(Coordinate const *coordinates[], uint32_t nCoordinates) {
    uint32_t i;
    for (i = 0U; i < nCoordinates; ++i) {
        Coordinate_draw(coordinates[i]); /* virtual call */
    }
}
