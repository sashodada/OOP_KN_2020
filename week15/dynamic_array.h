#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

class DynamicArray;
class DynamicArrayIterator
{
private:
  int currentIndex;
  const DynamicArray *arr;

public:
  DynamicArrayIterator(int pos, const DynamicArray *arr);
  DynamicArrayIterator(const DynamicArrayIterator &other);
  DynamicArrayIterator& operator=(const DynamicArrayIterator &other);

  void operator++();
  int operator-(const DynamicArrayIterator &other);
  bool operator==(const DynamicArrayIterator &other);
  bool operator!=(const DynamicArrayIterator &other);
  int operator*();
};

class DynamicArray
{
private:
  int *data;
  int size;
  int capacity;

public:
  friend class DynamicArrayIterator;

  DynamicArray(int size = 0, int *data = nullptr);
  DynamicArray(const DynamicArray &other);
  DynamicArray &operator=(const DynamicArray &other);
  ~DynamicArray();

  void push_back(int entry);
  void print();

  // NB: begin and end require "const" qualifier to work after a const reference has been passed as a function argument
  DynamicArrayIterator begin() const { return DynamicArrayIterator(0, this); }
  DynamicArrayIterator end() const{ return DynamicArrayIterator(size, this); }
};

#endif // DYNAMIC_ARRAY_H_