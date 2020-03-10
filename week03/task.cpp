#include <iostream>
#include <cstring>
using namespace std;

class DynamicArray
{
private:
  char *arr;
  int length;

  void copy(const char *_arr)
  {
    this->length = 0;
    if (this->arr != nullptr)
    {
      delete[] this->arr;
      this->arr = nullptr;
    }

    if (_arr != nullptr && strlen(_arr) > 0)
    {
      this->length = strlen(_arr);
      this->arr = new char[this->length + 1];
      strcpy(this->arr, _arr);
    }
  }

public:
  // DynamicArray a;
  DynamicArray() : arr(nullptr), length(0) {}

  // DynamicArray a("this is a test");
  DynamicArray(const char *_arr) : arr(nullptr)
  {
    this->copy(_arr);
  }

  // DynamicArray a;
  // DynamicArray b = a;
  // OR
  // when calling a function
  DynamicArray(const DynamicArray &other) : arr(nullptr)
  {
    this->copy(other.arr);
  }

  // DynamicArray a("nqkva stoinost"), b;
  // b = a;
  // a = a;
  DynamicArray &operator=(const DynamicArray &other)
  {
    if (this != &other)
    {
      this->copy(other.arr);
    }

    return *this;
  }

  ~DynamicArray()
  {
    delete[] this->arr;
  }

  void setArr(const char *_arr)
  {
    this->copy(arr);
  }

  void setCharAt(int index, char symbol)
  {
    this->arr[index] = symbol;
  }

  char *getArr()
  {
    return this->arr;
  }
};

int main()
{
  DynamicArray a;
  a.setArr("tova e test");

  DynamicArray b = a;
  b.setCharAt(5, '=');
  cout << a.getArr() << endl;

  return 0;
}
