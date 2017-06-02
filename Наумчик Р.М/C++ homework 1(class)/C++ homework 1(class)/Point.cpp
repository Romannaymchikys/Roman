#include "Point.h"
#include <iostream>

float Point::getX() const { return x; }
float Point::getY() const { return y; }
void Point::setX(const float newx) { x = newx; }
void Point::setY(const float newy) { y = newy; }
void Point::Print() { std::cout << x << std::endl << y << std::endl; }

