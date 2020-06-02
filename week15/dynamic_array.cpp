#include <iostream>
#include "dynamic_array.h"

using namespace std;

DynamicArray::DynamicArray(int size, int *data)
    : size(size), data(nullptr), capacity(size)
{
  if (this->capacity)
  {
    this->data = new int[this->capacity];
  }

  if (data != nullptr)
  {
    for (int i = 0; i < size; ++i)
    {
      this->data[i] = data[i];
    }
  }
}

DynamicArray::DynamicArray(const DynamicArray &other)
    : size(other.size), data(nullptr), capacity(other.capacity)
{
  if (this->capacity)
  {
    this->data = new int[this->capacity];
  }

  if (other.data != nullptr)
  {
    for (int i = 0; i < size; ++i)
    {
      this->data[i] = other.data[i];
    }
  }
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other)
{
  if (this != &other)
  {
    if (this->data)
    {
      delete[] this->data;
      this->data = nullptr;
    }

    if (this->capacity)
    {
      this->data = new int[this->capacity];
    }

    if (other.data != nullptr)
    {
      for (int i = 0; i < size; ++i)
      {
        this->data[i] = other.data[i];
      }
    }
  }

  return *this;
}

DynamicArray::~DynamicArray()
{
  delete[] this->data;
  this->data = nullptr;
}

void DynamicArray::push_back(int entry)
{
  if (data == nullptr)
  {
    if (!capacity)
    {
      capacity = 10;
      size = 0;
    }

    this->data = new int[capacity];
  }

  if (size == capacity)
  {
    capacity *= 2;
    int *temp = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
      temp[i] = this->data[i];
    }
    temp[size] = entry;
    delete[] this->data;
    this->data = temp;
  }
  else
  {
    this->data[size] = entry;
  }

  size++;
}

void DynamicArray::print()
{
  for (int i = 0; i < size; ++i)
  {
    cout << this->data[i] << " ";
  }
  cout << endl;
}

DynamicArrayIterator::DynamicArrayIterator(int pos, const DynamicArray *arr)
    : currentIndex(pos), arr(arr) {}

DynamicArrayIterator::DynamicArrayIterator(const DynamicArrayIterator &other)
    : currentIndex(other.currentIndex), arr(other.arr) {}
DynamicArrayIterator &DynamicArrayIterator::operator=(const DynamicArrayIterator &other)
{
  if (this != &other)
  {
    this->currentIndex = other.currentIndex;
    this->arr = other.arr;
  }

  return *this;
}

void DynamicArrayIterator::operator++()
{
  this->currentIndex++;
}

int DynamicArrayIterator::operator-(const DynamicArrayIterator &other)
{
  return this->currentIndex - other.currentIndex;
}

bool DynamicArrayIterator::operator==(const DynamicArrayIterator &other)
{
  return this->arr == other.arr && this->currentIndex == other.currentIndex;
}

bool DynamicArrayIterator::operator!=(const DynamicArrayIterator &other)
{
  return !(*this == other);
}

int DynamicArrayIterator::operator*()
{
  return this->arr->data[currentIndex];
}
