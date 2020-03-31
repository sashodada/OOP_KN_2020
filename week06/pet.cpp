#include "pet.h"
#include <cstring>
#include <iostream>

void Pet::_copyName(const char *_name)
{
  if (name != nullptr)
  {
    this->_clear();
  }

  if (_name != nullptr)
  {
    int length = strlen(_name);
    if (length) {
      this->name = new char[length + 1];
      strcpy(this->name, _name);
    }
  }
}

void Pet::_clear()
{
  delete[] this->name;
  this->name = nullptr;
}

Pet::Pet(const char *_name, int _age) : name(nullptr), age(_age)
{
  _copyName(_name);
}

Pet::Pet(const Pet &other) : name(nullptr), age(other.age)
{
  _copyName(other.name);
}

Pet &Pet::operator=(const Pet &other)
{
  if (this != &other)
  {
    this->age = other.age;
    this->_copyName(other.name);
  }

  return *this;
}

Pet::~Pet()
{
  std::cout << "Calling destructor of Pet\n";
  this->_clear();
}
