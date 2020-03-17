#include <iostream>
#include <functional>
#include <cstring>
using namespace std;

/**
 * CALLABLE:
 * - lambda functions
 * - function pointers
 * - structs w/ operator ()
 */

/**
 * - name holds pointer to DYNAMIC memory
 * - facultyNumber is MANDATORY
 */
class Student
{
private:
  int facultyNumber;
  char *name;

  void _clear()
  {
    delete[] name;
    name = nullptr;
  }

  void _copyName(const char *_name)
  {
    if (name != nullptr)
    {
      _clear();
    }

    if (_name != nullptr)
    {
      int l = strlen(_name);
      if (l > 0)
      {
        name = new char[l + 1];
        strcpy(name, _name);
      }
    }
  }

public:
  Student(int _facultyNumber, const char *_name = "") : facultyNumber(_facultyNumber), name(nullptr)
  {
    _copyName(_name);
  }

  Student(const Student &other) : facultyNumber(other.facultyNumber), name(nullptr)
  {
    _copyName(other.name);
  }

  Student &operator=(const Student &other)
  {
    if (this != &other)
    {
      facultyNumber = other.facultyNumber;
      _copyName(other.name);
    }

    return *this;
  }

  ~Student()
  {
    _clear();
  }

  const char *getName() { return name; }
  int getFacultyNumber() { return facultyNumber; }
};

// Pseudo grades container
class Grades
{
private:
  double grades[10][10];

public:
  Grades()
  {
    for (int i = 0; i < 10; ++i)
    {
      for (int j = 0; j < 10; ++j)
      {
        grades[i][j] = (13 * i + j) % 4 + 2;
      }
    }
  };

  double getAverageGrade(int facultyNumber)
  {
    const double *studentGrades = grades[facultyNumber];

    double averageGrade = 0;
    for (int i = 0; i < 10; ++i)
    {
      averageGrade += studentGrades[i];
    }

    return averageGrade / 10.0;
  }
};

template <typename T>
void sort(T *arr, int size, function<bool(const T &, const T &)> comp)
{
  for (int i = 1; i < size; ++i)
  {
    for (int j = 0; j < size - i; ++j)
    {
      if (comp(arr[j], arr[j + 1]))
      {
        T helper = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = helper;
      }
    }
  }
}

int main()
{
  Student *students[10];
  for (int i = 0; i < 10; ++i)
  {
    char name[101];
    cout << "Input student name: ";
    cin.getline(name, 100);
    students[i] = new Student(i, name);
  }

  // Sort by name
  sort<Student *>(students, 10, [](Student *left, Student *right) {
    return strcmp(left->getName(), right->getName()) > 0;
  });

  for (int i = 0; i < 10; ++i)
  {
    cout << students[i]->getName() << endl;
  }


  // Sort by average grade
  Grades pseudoGrades;
  sort<Student *>(students, 10, [&pseudoGrades](Student *left, Student *right) {
    return pseudoGrades.getAverageGrade(left->getFacultyNumber()) > pseudoGrades.getAverageGrade(right->getFacultyNumber());
  });
  for (int i = 0; i < 10; ++i)
  {
    cout << students[i]->getName() << " " << pseudoGrades.getAverageGrade(students[i]->getFacultyNumber()) << endl;
  }

  return 0;
}
