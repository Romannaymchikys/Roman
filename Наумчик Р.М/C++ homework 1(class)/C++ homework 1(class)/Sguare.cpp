#include "Sguare.h"
#include <cmath>
#include <iostream>

double Sguare::getSguareSide() const { return side; }
double Sguare::getSguaresArea() const { return sguareArea; }
void Sguare::setSguareSide(const unsigned newside) { side = newside * 0.01; }
void Sguare::setSguaresArea(const double side) { sguareArea = side * side; }
void Sguare::PrintSguares() { std::cout << sguareArea << std::endl; };

