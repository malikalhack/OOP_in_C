#ifndef COORDINATE_H
#define COORDINATE_H

/* coordinate's attributes... */
typedef struct {
    int x; /* x-coordinate of position */
    int y; /* y-coordinate of position */
} Coordinate;

/* coordinate's operations (interface)... */
void Coordinate_ctor(Coordinate *, int, int);
void Coordinate_moveBy(Coordinate *, int, int);
int Coordinate_getX(Coordinate *);
int Coordinate_getY(Coordinate *);

#endif /* COORDINATE_H */
