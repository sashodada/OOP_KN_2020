#ifndef DOG_H_
#define DOG_H_

#include "pet.h"

enum Color {
  Transparent = 0,
  Red = 1,
  Yellow = 2,
  Black = 3,
  White = 4,
  Brown = 5,
};

class Dog : public Pet
{
private:
  Color color;

public:
  Dog(const char *_name = nullptr, int _age = 0, Color _color = Transparent);
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  virtual ~Dog();

  Color getColor() { return this->color; }
  virtual int getAge() { return this->age / 7; }
};

#endif