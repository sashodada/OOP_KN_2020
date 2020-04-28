#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
  fstream myBinFile("numbers.bin", ios::binary | ios::in | ios::out | ios::trunc);
  int x = 42;
  myBinFile.write((char *)&x, sizeof(int));

  int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  myBinFile.write((char *)arr, 10 * sizeof(int));

  const char *charArr = "primer s char masiv\n";
  myBinFile.write(charArr, strlen(charArr));

  myBinFile.seekg(0, myBinFile.beg);
  for (int i = 0; i < 11; ++i) {
    int temp;
    myBinFile.read((char *)&temp, sizeof(int));
    cout << temp << endl;
  }
  cout << endl;

  // искаме да променим числото 4 от масива arr
  // знаем началото на arr
  // знаем и на коя позиция в arr се намира числото

  // преместваме в началото на файла
  myBinFile.seekp(0, myBinFile.beg);
  // преместваме до началото на масива
  myBinFile.seekp(sizeof(int), myBinFile.cur);
  // преместваме до позицията на 4-ката
  myBinFile.seekp(3 * sizeof(int), myBinFile.cur);

  int newData = 1984;
  myBinFile.write((char *)&newData, sizeof(int));

  myBinFile.seekg(0, myBinFile.beg);
  for (int i = 0; i < 11; ++i) {
    int temp;
    myBinFile.read((char *)&temp, sizeof(int));
    cout << temp << endl;
  }

  return 0;
}
