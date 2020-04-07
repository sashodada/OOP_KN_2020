#ifndef FIGURE_H_
#define FIGURE_H_

class Figure2D
{
public:
  virtual ~Figure2D() {};

  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;
};

#endif