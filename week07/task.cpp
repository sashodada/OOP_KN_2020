#include <iostream>
#include <vector>
#include <algorithm>
#include "figure.h"
#include "circle.h"
#include "square.h"
using namespace std;

int main()
{
  // Figure2D *circle = new Circle();
  // cout << circle->getArea() << endl;
  // cout << circle->getPerimeter() << endl;
  // delete circle;

  // Figure2D *square = new Square(5);
  // cout << square->getArea() << endl;
  // cout << square->getPerimeter() << endl;
  // delete square;

  vector<Figure2D *> figures(10);

  for (int i = 0; i < 10; i += 2)
  {
    figures[i] = new Circle(i + 1);
  }

  for (int i = 1; i < 10; i += 2)
  {
    figures[i] = new Square(i + 1);
  }

  sort(figures.begin(), figures.end(), [](Figure2D *left, Figure2D *right) {
    return left->getArea() < right->getArea();
  });

  for (Figure2D *figure : figures)
  {
    cout << figure->getArea() << endl;
    cout << figure->getPerimeter() << endl;
    delete figure;
  }
  // Equivalent
  
  // for (vector<Figure2D *>::iterator it = figures.begin(); it != figures.end(); it++)
  // {
  //   Figure2D *figure = *it;
  //   // Same code here
  // }

  return 0;
}