#include "circle.h"
#include <iostream>

Circle::Circle(double _radius) : radius(_radius) {}

double Circle::getArea() const
{
  return 3.1415 * radius * radius;
}

double Circle::getPerimeter() const
{
  return 2 * 3.1415 * radius;
}

Circle::~Circle()
{
  std::cout << "Deleting circle\n";
}