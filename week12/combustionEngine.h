#ifndef COMBUSTION_ENGINE_H_
#define COMBUSTION_ENGINE_H_

#include <iostream>
#include "engine.h"

class CombustionEngine : virtual public Engine
{
protected:
  int engineSize;
  char *serialNumber;

public:
  CombustionEngine(
    int _power = 0, const char *_manufacturer = nullptr,
    int _engineSize = 0, const char *_serialNumber = nullptr)
    : Engine(_power, _manufacturer), engineSize(_engineSize), serialNumber(nullptr)
  {
    std::cout << "Combustion Engine\n";
    this->setSerialNumber(_serialNumber);
  };

  CombustionEngine(const CombustionEngine &other)
    : Engine(other), engineSize(other.engineSize), serialNumber(nullptr)
  {
    std::cout << "Combustion Engine COPY\n";
    this->setSerialNumber(other.serialNumber);
  }

  CombustionEngine &operator=(const CombustionEngine &other)
  {
    if (this != &other)
    {
      Engine::operator=(other);
      this->engineSize = other.engineSize;
      this->setSerialNumber(other.serialNumber);
    }

    return *this;
  }

  ~CombustionEngine()
  {
    delete[] serialNumber;
    serialNumber = nullptr;
    std::cout << "Delete combustion engine\n";
  }

  int getEngineSize() const { return this->engineSize; }
  char *getSerialNumber() const { return this->serialNumber; }

  void setSerialNumber(const char *_serialNumber)
  {
    copyString(this->serialNumber, _serialNumber);
  }
};

#endif // COMBUSTION_ENGINE_H_