#include <iostream>
#include <vector>
#include <functional>
#include "dynamic_array.h"
using namespace std;

// Function for testing basic iterator implementation,
// should work with both custom iterators and STL
template <typename T>
int sum(const T& data)
{
  int acc = 0;
  for (int x : data)
  {
    acc += x;
  }

  return acc;
}

int main()
{
  // Testing custom class w/ custom iterator
  DynamicArray myDynamicArray;

  myDynamicArray.push_back(5);
  myDynamicArray.push_back(2);
  myDynamicArray.push_back(3);
  myDynamicArray.push_back(4);
  myDynamicArray.push_back(1);
  cout << sum(myDynamicArray) << endl;
  
  // Testing STL container iteration
  vector<int> myVec{1, 2, 3, 4, 5, 6};
  cout << sum(myVec) << endl;

  // Testing const reference only STL container
  cout << sum(vector<int>{1, 2, 3, 4, 5, 6, 7}) << endl;
  return 0;
}