#include "farm.h"

Farm::Farm(int _money, int _food, int _wood, int _stone)
    : money(_money), food(_food), wood(_wood), stone(_stone), cropsSize(0), crops(nullptr) {}

Farm::Farm(const Farm &other)
    : money(other.money), food(other.food),
      wood(other.wood), stone(other.stone),
      cropsSize(other.cropsSize), crops(nullptr)
{
  if (other.crops != nullptr && other.cropsSize > 0)
  {
    crops = new Crop[other.cropsSize];
    for (int i = 0; i < other.cropsSize; ++i)
    {
      crops[i] = other.crops[i];
    }
  }
}

Farm &Farm::operator=(const Farm &other)
{
  if (this != &other)
  {
    if (crops)
    {
      delete[] crops;
    }

    cropsSize = other.cropsSize;
    if (other.crops != nullptr && other.cropsSize > 0)
    {
      crops = new Crop[other.cropsSize];
      for (int i = 0; i < other.cropsSize; ++i)
      {
        crops[i] = other.crops[i];
      }
    }
    money = other.money;
    food = other.food;
    wood = other.wood;
    stone = other.stone;
  }
}

Farm::~Farm()
{
  delete[] crops;
}

std::istream &operator>>(std::istream &in, Farm &farm)
{
  in >> farm.money;
  in >> farm.food;
  in >> farm.wood;
  in >> farm.stone;
  in >> farm.cropsSize;
  if (farm.crops != nullptr)
  {
    delete[] farm.crops;
  }

  if (farm.cropsSize > 0)
  {
    farm.crops = new Crop[farm.cropsSize];
    for (int i = 0; i < farm.cropsSize; ++i)
    {
      in >> farm.crops[i];
    }
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const Farm &farm)
{
  out << farm.money << " ";
  out << farm.food << " ";
  out << farm.wood << " ";
  out << farm.stone << "\n";
  out << farm.cropsSize << "\n";
  for (int i = 0; i < farm.cropsSize; ++i)
  {
    out << farm.crops[i] << "\n";
  }
  return out;
}