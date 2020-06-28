#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdint.h>

/*#define Coordinate_area(self_) ((*(self_)->vptr->area)((self_)))*/
/*#define Coordinate_draw(self_) ((*(self_)->vptr->draw)(self_))*/

/* Coordinate's virtual table */
struct CoordinateVtbl {
	uint32_t(*area)(Coordinate const * const self);
	void(*draw)(Coordinate const * const self);
};

/* Coordinate's attributes... */
typedef struct {
    struct CoordinateVtbl const *vptr; /* Coordinate's Virtual Pointer */
    int x; /* x-coordinate of position */
    int y; /* y-coordinate of position */
} Coordinate;

/* coordinate's operations (interface)... */
void Coordinate_ctor(Coordinate * const self, int x, int y);
void Coordinate_moveBy(Coordinate * const self, int dx, int dy);

static inline uint32_t Coordinate_area(Coordinate const * const self){
	return (*self->vptr->area)(self);
}
static inline void Coordinate_draw(Coordinate const * const self) {
	(*self->vptr->draw)(self);
}

/* generic operations on collections of Coordinates */
Coordinate const *largestCoordinate(Coordinate const *coordinates[], uint32_t nCoordinates);
void drawAllCoordinates(Coordinate const *coordinates[], uint32_t nCoordinates);

#endif /* COORDINATE_H */
