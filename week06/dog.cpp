#include "dog.h"
#include <iostream>

Dog::Dog(const char *_name, int _age, Color _color)
    : Pet(_name, _age), color(_color) {}

Dog::Dog(const Dog &other)
    : Pet(other), color(other.color) {}

Dog &Dog::operator=(const Dog &other)
{
  if (this != &other)
  {
    Pet::operator=(other);
    this->color = other.color;
  }

  return *this;
}

Dog::~Dog() { std::cout << "Dog destructor\n"; }