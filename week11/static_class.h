#ifndef STATIC_CLASS_H_
#define STATIC_CLASS_H_

#include <iostream>
using namespace std;

class StaticClass
{
public:
  static int objectCounter;
  int x;
  StaticClass() : x(0)
  {
    cout << "StaticClass constructor called\n";
    objectCounter++;
    cout << objectCounter << endl;
  }
};

int StaticClass::objectCounter = 0;

#endif // STATIC_CLASS_H_