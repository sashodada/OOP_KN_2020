#include <iostream>
#include "engine.h"
#include "combustionEngine.h"
#include "electricMotor.h"
#include "hybridEngine.h"

using namespace std;

// Engine           --> int power
// CombustionEngine --> int engineSize
// ElectricMotor    --> int batteryCount
// HybridEngine     --> double enginesRatio

int main()
{
  HybridEngine hybrid(130, "Toyota", 1000, "FMI00666", 1, "Duracel", 1.1);
  cout << endl;
  cout << hybrid.getBatteryManufacturer() << endl;
  cout << hybrid.getSerialNumber() << endl;
  cout << hybrid.getManufacturer() << endl;
  cout << endl;

  HybridEngine hybrid2 = hybrid;
  cout << endl;
  cout << hybrid2.getBatteryManufacturer() << endl;
  cout << hybrid2.getSerialNumber() << endl;
  cout << hybrid2.getManufacturer() << endl;
  cout << endl;

  HybridEngine hybrid3;
  hybrid3 = hybrid;
  cout << endl;
  cout << hybrid3.getBatteryManufacturer() << endl;
  cout << hybrid3.getSerialNumber() << endl;
  cout << hybrid3.getManufacturer() << endl;
  cout << endl;
  return 0;
}