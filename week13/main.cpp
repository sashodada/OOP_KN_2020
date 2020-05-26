#include <iostream>
#include <vector>
using namespace std;

class Thrower
{
public:
  Thrower() { throw runtime_error("kek"); }
  ~Thrower() { cout << "Destructor called\n"; }
};

double division(double x, double y)
{
  if (y == 0)
  {
    throw "Division by 0 not allowed";
  }
  return x / y;
}

double someStrangeFunction(double x, double y, double z)
{
  return division(division(z * z, x) * y, z);
}

int nestedErrorTest()
{
  double x, y, z;
  double res = 0;
  int isCalculationSuccessful = false;

  while (!isCalculationSuccessful)
  {
    cin >> x >> y >> z;
    try
    {
      res = someStrangeFunction(x, y, z);
      isCalculationSuccessful = true;
    }
    catch (runtime_error e)
    {
      cout << e.what() << endl;
      cout << "Please, try again\n";
    }
    catch (const char *e)
    {
      cout << e << endl;
      cout << "Please, try again\n";
    }
  }
  cout << res << endl;
  cout << "Success!\n";
}

void constructorErrorHandling()
{
  Thrower *pThrower;
  try
  {
    pThrower = new Thrower();
  }
  catch (runtime_error e)
  {
    pThrower = nullptr;
    cout << "Error: " << e.what() << endl;
    cout << "Could not initialize object\n";
  }

  if (pThrower == nullptr)
  {
    cout << "Cannot work with null object, nothing to do\n";
  }

  cout << 2 + 2 << endl;
}

int main()
{
  nestedErrorTest();
  constructorErrorHandling();
  return 0;
}