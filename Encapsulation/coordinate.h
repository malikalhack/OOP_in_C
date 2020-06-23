#ifndef COORDINATE_H
#define COORDINATE_H
/* coordinate's attributes... */
typedef struct {
    int x; /* x-coordinate of position */
    int y; /* y-coordinate of position */
} Coordinate;
/* coordinate's operations (interface)... */
void Coordinate_ctor(Coordinate * const self, int x, int y);
void Coordinate_moveBy(Coordinate * const self, int dx, int dy);
int Coordinate_getX(Coordinate * const self);
int Coordinate_getY(Coordinate * const self);
#endif /* COORDINATE_H */