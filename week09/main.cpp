#include <iostream>
#include <fstream>
#include "farm.h"
using namespace std;

int main()
{
  Farm farmVille;
  ifstream inf("inFile.txt");
  inf >> farmVille;

  ofstream outf("outFile.txt");
  outf << farmVille << endl;
  return 0;
}

/**
 * 
 * FarmVille

    Задачата ви е да напишете опростена версия на играта FarmVille.
    Да се реализират:
      - клас Crop - абстрактен; да бъде имплементиран от
        - Tomato
        - Potato
        - Rye
        - Tree
        - Coral
        * при събиране на всяка от горните имплементации трябва фермата да получи съответно толкова храна, дървесен материал или камък, колкото е указано в обекта
      - клас Farm
        * да има множество от Crop-ове
        * да има складирани материали (храна, дърво, камък)
        * да има пари (напр. 100 първоначално)
  */