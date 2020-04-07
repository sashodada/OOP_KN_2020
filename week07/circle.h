#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "figure.h"

class Circle : public Figure2D
{
private:
  double radius;
public:
  Circle(double _radius = 1);
  ~Circle();

  virtual double getPerimeter() const;
  virtual double getArea() const;
};


#endif