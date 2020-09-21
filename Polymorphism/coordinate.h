#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdint.h>

struct CoordinateVtbl; /* Mandatory preliminary structure declaration */

/* Coordinate's attributes... */
typedef struct {
	struct CoordinateVtbl const *vptr; /* Coordinate's Virtual Pointer */
	int x; /* x-coordinate of position */
	int y; /* y-coordinate of position */
} Coordinate;

/* Coordinate's virtual table */
struct CoordinateVtbl {
	uint32_t(*area)(Coordinate const * const);
	void(*draw)(Coordinate const * const);
};

/* Coordinate's prototypes of its virtual functions */
static uint32_t Coordinate_area_(Coordinate const * const);
static void Coordinate_draw_(Coordinate const * const);

/* coordinate's operations (interface)... */
void Coordinate_ctor(Coordinate * const, int16_t, int16_t);
void Coordinate_moveBy(Coordinate * const, int16_t, int16_t);

static inline uint32_t Coordinate_area(Coordinate const * const self) {
	return (*self->vptr->area)(self);
}
static inline void Coordinate_draw(Coordinate const * const self) {
	(*self->vptr->draw)(self);
}

/* generic operations on collections of Coordinates */
void drawAllCoordinates(Coordinate const * coordinates[], uint32_t);

/* generic operations on collections of areas */
void drawAllAreas(Coordinate const * coordinates[], uint32_t);

#endif /* COORDINATE_H */
