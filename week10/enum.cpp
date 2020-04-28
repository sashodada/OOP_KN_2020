#include <iostream>
using namespace std;

// enum типовете са полезни, когато
// - за дадена променлива имаме малък краен брой допустими стойности
// - тези стойности имат повече значение за нас, отколкото за компютъра
enum Season {
  Winter = 1,
  Spring = 2,
  Summer = 3,
  Autumn = 4
};

void printSeason(Season season)
{
  switch (season)
  {
  case Winter:
    cout << "Winter\n";
    break;
  case Spring:
    cout << "Spring\n";
    break;
  case Summer:
    cout << "Summer\n";
    break;
  case Autumn:
    cout << "Autumn\n";
  }
  return;
}

int main()
{
  int monthOfBirth;
  cout << "Enter your month of birht: ";
  cin >> monthOfBirth;

  /**
   * 0, 1, 2 => Winter
   * 3, 4, 5 => Spring
   * 6, 7, 8 => Summer
   * 9, 10, 11 => Autumn
   */

  int season = ((monthOfBirth % 12) / 3) + 1;

  /**
   * 1 => Winter
   * 2 => Spring
   * 3 => Summer
   * 4 => Autumn
   */
  printSeason(static_cast<Season>(season));

  return 0;
}