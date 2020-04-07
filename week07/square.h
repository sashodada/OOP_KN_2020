#ifndef SQUARE_H_
#define SQUARE_H_

#include "figure.h"

class Square : public Figure2D
{
private:
  double side;
public:
  Square(double _side = 1);
  virtual ~Square();

  virtual double getPerimeter() const;
  virtual double getArea() const;
};

#endif