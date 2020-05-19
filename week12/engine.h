#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <cstring>

class Engine
{
protected:
  int power;
  char *manufacturer;

  void copyString(char *&field, const char *newValue)
  {
    if (field != nullptr)
    {
      delete[] field;
      field = nullptr;
    }

    if (newValue != nullptr)
    {
      int length = strlen(newValue);
      if (length > 0)
      {
        field = new char[length + 1];
        strcpy(field, newValue);
      }
    }
  }

public:
  Engine(int _power = 0, const char *_manufacturer = nullptr) : power(_power), manufacturer(nullptr)
  {
    std::cout << "Engine constructor\n";
    this->setManufacturer(_manufacturer);
  };

  Engine(const Engine &other) : power(other.power), manufacturer(nullptr)
  {
    std::cout << "Engine COPY constructor\n";
    this->setManufacturer(other.manufacturer);
  }

  Engine &operator=(const Engine &other)
  {
    std::cout << "Engine OPERATOR=\n";
    if (this != &other)
    {
      this->power = other.power;
      this->setManufacturer(other.manufacturer);
    }

    return *this;
  }

  virtual ~Engine()
  {
    delete[] this->manufacturer;
    this->manufacturer = nullptr;
    std::cout << "Destroying engine\n";
  }

  int getPower() const { return this->power; }
  char *getManufacturer() const { return this->manufacturer; }

  void setManufacturer(const char *_manufacturer)
  {
    copyString(this->manufacturer, _manufacturer);
  }
};

#endif // ENGINE_H_