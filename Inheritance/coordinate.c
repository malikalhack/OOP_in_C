#include "Coordinate.h" /* Coordinate class interface */
/* constructor implementation */
void Coordinate_ctor(Coordinate * const self, int x, int y) {
    self->x = x;
    self->y = y;
}
/* move-by operation implementation */
void Coordinate_moveBy(Coordinate * const self, int dx, int dy) {
    self->x += dx;
    self->y += dy;
}
/* "getter" operations implementation */
int Coordinate_getX(Coordinate * const self) {
    return self->x;
}
int Coordinate_getY(Coordinate * const self) {
    return self->y;
}
