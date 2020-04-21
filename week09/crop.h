#ifndef CROP_H_
#define CROP_H_

#include <iostream>
#include "material_type.h"

class Crop
{
private:
  MaterialType type;
  int income;

public:
  Crop(MaterialType _type = Food, int _income = 0) : type(_type), income(_income) {}

  MaterialType getType() { return type; }
  int getIncome() { return income; }

  friend std::istream &operator>>(std::istream &in, Crop &crop)
  {
    int type;
    in >> type;
    crop.type = static_cast<MaterialType>(type);
    in >> crop.income;
  }

  friend std::ostream &operator<<(std::ostream &out, Crop &crop)
  {
    out << crop.type << " " << crop.income;
  }
};

#endif