#include "coordinate.h" /* coordinate class interface */

#define UPPER_LIMIT  100
#define LOWER_LIMIT -100

/* constructor implementation */
void Coordinate_ctor(Coordinate * const self, int x, int y) {
	self->x = x;
	self->y = y;
}
/* move-by operation implementation */
void Coordinate_moveBy(Coordinate * const self, int dx, int dy) {
	unsigned char act = 1;

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

/* "getter" operations implementation */
int Coordinate_getX(Coordinate * const self) {
	return self->x;
}

int Coordinate_getY(Coordinate * const self) {
	return self->y;
}
