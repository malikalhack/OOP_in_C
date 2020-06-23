#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdint.h>

//#define Coordinate_area(self_) ((*(self_)->vptr->area)((self_)))

/* Coordinate's attributes... */
struct CoordinateVtbl; /* forward declaration */
typedef struct {
    struct CoordinateVtbl const *vptr; /* <== Coordinate's Virtual Pointer */
    int x; /* x-coordinate of position */
    int y; /* y-coordinate of position */
} Coordinate;
/* Coordinate's virtual table */
struct ShapeVtbl {
    uint32_t (*area)(Coordinate const * const self);
    void (*draw)(Coordinate const * const self);
};
/* coordinate's operations (interface)... */
void coordinate_ctor(Coordinate * const self, int x, int y);
void coordinate_moveBy(Coordinate * const self, int dx, int dy);

static inline uint32_t Coordinate_area(Coordinate const * const self){
    return (*self->vptr->area)(self);
}
static inline void Coordinate_draw(Coordinate const * const self) {
    (*self->vptr->draw)(self);
}
/* generic operations on collections of Coordinates */
Coordinate const *largestCoordinate(Coordinate const *coordinates[], uint32_t nCoordinates);
void drawAllCoordinate(Coordinate const *coordinates[], uint32_t nCoordinates);

#endif /* COORDINATE_H */
