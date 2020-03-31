#include <iostream>
#include "pet.h"
#include "dog.h"
using namespace std;

int main()
{
	Pet pet1("ribka", 1);
	Pet *pet2 = new Dog("sharo", 42, Black);
	Dog pet3("charli", 70, White);

	cout << pet1.getAge() << endl;
	cout << pet2->getAge() << endl;
	cout << pet3.getAge() << endl;

	delete pet2;
	cout << endl;
	return 0;
}
