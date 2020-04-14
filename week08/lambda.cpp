#include <iostream>
#include <functional>
#include <vector>
using namespace std;

template <typename T, typename K>
K foo(T);

template <typename T, typename K>
vector<K> map(const vector<T> &target, const function<K(T)> &mapFunction)
{
  // arr1[10]
  // => arr2[10]
  // arr2[i] = mapFunc(arr1[i]), for every "i" between 0 and 9
  vector<K> result;

  for (T element : target)
  {
    result.push_back(mapFunction(element));
  }

  return result;
}

template <typename T>
vector<T> filter(const vector<T> &target, const function<bool(T)> &predicate)
{
  vector<T> result;
  for (T elem : target)
  {
    if (predicate(elem))
    {
      result.push_back(elem);
    }
  }
  return result;
}

template <typename T, typename K>
K reduce(const vector<T> &target, const function<K(T, K)> reducer, const K &initialValue)
{
  K result = initialValue;

  for (T elem : target)
  {
    result = reducer(elem, result);
  }

  return result;
}

// composition example
int sumOfSquaresOfEvens(const vector<int> &target)
{
  return
    reduce<int, int>(
      map<int, int>(
        filter<int>(
          target,
          [](int x) { return x % 2 == 0; }),
        [](int x) { return x * x; }),
      [](int elem, int res) { return elem + res; },
      0);
}

int main()
{
  vector<int> integers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> squares = map<int, int>(integers, [](int x) { return x * x; });
  vector<int> result = filter<int>(squares, [](int x) { return x % 2 == 0; });
  int sum = reduce<int, int>(
      result, [](int elem, int res) { return elem + res; }, 0);
  cout << "Sum of even squares is " << sum << endl;

  for (int elem : result)
  {
    cout << elem << endl;
  }

  result = filter<int>(squares, [](int x) { return x % 2 != 0; });
  int product = reduce<int, int>(
      result, [](int elem, int res) { return elem * res; }, 1);
  cout << "Product of odd squares is " << product << endl;

  for (int elem : result)
  {
    cout << elem << endl;
  }

  int mySum = sumOfSquaresOfEvens(integers);
  cout << "My sum is " << mySum << endl;
}
