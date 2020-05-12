#ifndef ENGINES_H_
#define ENGINES_H_

class Engine
{
public:
  int power;
  Engine(int _power = 0) : power(_power) {}
};

class CombustionEngine : virtual public Engine
{
public:
  int reservoirSize;
  CombustionEngine(int _power = 0, int _reservoirSize = 0) : Engine(_power), reservoirSize(_reservoirSize) {}
};

class ElectricMotor : virtual public Engine
{
public:
  int batteryCount;
  ElectricMotor(int _power = 0, int _batteryCount = 0) : Engine(_power), batteryCount(_batteryCount) {}
};

class HybridEngine : public CombustionEngine, public ElectricMotor
{
public:
  double combustionToElectricPowerRatio;
  HybridEngine(int _power = 0, int _reservoirSize = 0, int _batteryCount = 0, double _ratio = 1.0) :
    Engine(_power),
    CombustionEngine(_power, _reservoirSize),
    ElectricMotor(_power, _batteryCount),
    combustionToElectricPowerRatio(_ratio) {}

  // NB!: When a base class was virtually extended subclasses must always manually handle the base's initialization themselves
  HybridEngine(const HybridEngine &ohter) { /* ... */ }
  HybridEngine &operator = (const HybridEngine &other) { /* ... */ }
};

#endif // ENGINES_H_