#include <iostream>
#include "static_class.h"
#include "engines.h"
using namespace std;

// test static variable lifespan
int sum(int arg)
{
  static int result;
  result += arg;
  return result;
}

void sumWithStaticTest()
{
  int sumResult;
  for (int i = 0; i < 10; ++i)
  {
    sumResult = sum(i);
  }

  cout << sumResult << endl;
}

// test static member lifespan and location
void staticMemberTest()
{
  cout << StaticClass::objectCounter << endl;
  StaticClass obj[100];
  cout << sizeof(obj) << endl;
}

// diamond of death
int main()
{
  Engine engine(150);
  cout << sizeof(engine) << endl;
  cout << engine.power << endl;
  cout << endl;

  CombustionEngine combustion(150, 2000);
  cout << sizeof(combustion) << endl;
  cout << combustion.power << endl;
  cout << endl;

  ElectricMotor teslaBattery(600, 2);
  cout << sizeof(teslaBattery) << endl;
  cout << teslaBattery.power << endl;
  cout << endl;

  HybridEngine hybrid(250, 1200, 1, 0.5);
  cout << sizeof(hybrid) << endl;
  cout << hybrid.power << endl;
  return 0;
}