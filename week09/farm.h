#ifndef FARM_H_
#define FARM_H_

#include <iostream>
#include "crop.h"

class Farm
{
private:
  long food, wood, stone, money;
  int cropsSize;
  Crop *crops;
public:
  Farm(int _money = 0, int _food = 0, int _wood = 0, int _stone = 0);
  Farm(const Farm &other);
  Farm &operator=(const Farm &other);
  ~Farm();

  friend std::istream &operator>>(std::istream &in, Farm &farm);
  friend std::ostream &operator<<(std::ostream &out, const Farm &farm);
};

#endif

// cin >> x >> y >> z >> k >> t >> ...;