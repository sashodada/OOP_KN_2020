#include "square.h"
#include <iostream>

Square::Square(double _side) : side(_side) {}

double Square::getPerimeter() const {
  return 4 * side;
}

double Square::getArea() const {
  return side * side;
}

Square::~Square()
{
  std::cout << "Deleting square\n";
}
