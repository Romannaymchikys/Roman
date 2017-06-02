#include "Triangle.h"
#include <iostream>
#include <cmath>


double Triangle::getTriangleA() const { return a; }
double Triangle::getTriangleB() const { return b; }
double Triangle::getTriangleC() const { return c; }
double Triangle::getTriangleH() const { return h; }
double Triangle::getTriangleAngle() const { return angle; }
double Triangle::getTriangleArea() const { return angle; }
void Triangle::setABCHAngleTriangle(const unsigned newa, const unsigned newb, const unsigned newc, const unsigned newh, const unsigned newangle)
{
	a = newa * 0.01;
	b = newb * 0.01;
	c = newc * 0.01;
	h = newh * 0.01;
	angle = newangle * 0.01;
}
void Triangle::setTriangleHeightArea(const double h, const double a) { triangleArea = 0.5 * a * h; }
void Triangle::setTriangleAngleArea(const double a, const double b, const double angle) { triangleArea = 0.5 * a * b * sin(angle); }
void Triangle::setTriangleABCArea(const double a, const double b, const double c)
{
	double p = (a + b + c) / 2;
	triangleArea = sqrt(p * (p - a) * (p - b) * (p - c));
}
void Triangle::PrintArea() { std::cout << triangleArea << std::endl; }

