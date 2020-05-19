#ifndef ELECTRIC_MOTOR_H_
#define ELECTRIC_MOTOR_H_

#include <iostream>
#include "engine.h"

class ElectricMotor : virtual public Engine
{
private:
  int batteryCount;
  char *batteryManufacturer;

public:
  ElectricMotor(int _power = 0, const char *_manufacturer = nullptr, int _batteryCount = 1, const char *_batteryManufacturer = nullptr)
    : Engine(_power, _manufacturer), batteryCount(_batteryCount), batteryManufacturer(nullptr)
    {
      std::cout << "Electric motor\n";
      this->setBatteryManufacturer(_batteryManufacturer);
    };

  ElectricMotor(const ElectricMotor &other)
    : Engine(other), batteryCount(other.batteryCount), batteryManufacturer(nullptr)
    {
      std::cout << "Electric motor COPY\n";
      this->setBatteryManufacturer(other.batteryManufacturer);
    }

  ElectricMotor &operator=(const ElectricMotor &other)
  {
    if (this != &other)
    {
      Engine::operator=(other);
      this->batteryCount = other.batteryCount;
      this->setBatteryManufacturer(other.batteryManufacturer);
    }

    return *this;
  }

  ~ElectricMotor()
  {
    delete[] this->batteryManufacturer;
    this->batteryManufacturer = nullptr;
    std::cout << "Delete electric motor\n";
  }

  int getBatteryCount() const { return this->batteryCount; }
  char *getBatteryManufacturer() const { return this->batteryManufacturer; }

  void setBatteryManufacturer(const char *_batteryManufacturer)
  {
    this->copyString(this->batteryManufacturer, _batteryManufacturer);
  }
};

#endif //ELECTRIC_MOTOR_H_