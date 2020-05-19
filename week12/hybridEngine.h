#ifndef HYBRID_ENGINE_H_
#define HYBRID_ENGINE_H_

#include <iostream>
#include "combustionEngine.h"
#include "electricMotor.h"

class HybridEngine : public CombustionEngine, public ElectricMotor
{
private:
  double enginesRatio;

public:
  HybridEngine(
      int _power = 0, const char *_manufacturer = nullptr,
      int _engineSize = 0, const char *_serialNumber = nullptr,
      int _batteryCount = 1, const char *_batteryManufacturer = nullptr,
      double _enginesRatio = 1)
      : Engine(_power, _manufacturer), CombustionEngine(_power, _manufacturer, _engineSize, _serialNumber),
        ElectricMotor(_power, _manufacturer, _batteryCount, _batteryManufacturer), enginesRatio(_enginesRatio)
  {
    std::cout << "Hybrid Engine\n";
  };

  HybridEngine(const HybridEngine &other)
      : Engine(other), CombustionEngine(other), ElectricMotor(other), enginesRatio(other.enginesRatio)
  {
    std::cout << "Hybrid Engine COPY\n";
  }

  HybridEngine &operator=(const HybridEngine &other)
  {
    if (this != &other)
    {
      Engine::operator=(other);
      CombustionEngine::operator=(other);
      ElectricMotor::operator=(other);
      this->enginesRatio = other.enginesRatio;
    }

    return *this;
  }

  ~HybridEngine() { std::cout << "Delete hybrid engine\n"; }

  double getEngineseRation() const { return this->enginesRatio; }
};

#endif // HYBRID_ENGINE_H_