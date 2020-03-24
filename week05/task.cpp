#include <iostream>
#include <cstring>
using namespace std;

class Employee;
Employee *findBoss(Employee *);

class Employee
{
private:
  char *name;
  int salary;
  Employee *manager;

  void _clearName()
  {
    cout << "Deleting name for " << this->name << endl;
    delete[] this->name;
    this->name = nullptr;
  }

  void _clearManager()
  {
    cout << "Deleting manager for " << this->name << endl;
    delete this->manager;
    this->manager = nullptr;
  }

  void _clear()
  {
    cout << "Deleting object at adress " << this << endl;
    _clearManager();
    _clearName();
  }

  void _copyName(const char *_name)
  {
    if (name != nullptr)
    {
      _clearName();
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

  // Рекурсивно копиране на списък от мениджъри
  void _copyManager(Employee *_manager)
  {
    if (this->manager != nullptr)
    {
      _clearManager();
    }

    if (_manager != nullptr)
    {
      cout << "Copying " << _manager->getName() << endl;
      this->manager = new Employee(_manager->name, _manager->salary);
      this->manager->_copyManager(_manager->getManager());
    }
  }

public:
  Employee(const char *_name = nullptr, int _salary = 0, Employee *_manager = nullptr) : name(nullptr), salary(_salary), manager(_manager)
  {
    _copyName(_name);
  }

  Employee(const Employee &other) : name(nullptr), salary(other.salary), manager(nullptr)
  {
    _copyName(other.name);
    _copyManager(other.manager);
  }

  Employee &operator=(const Employee &other)
  {
    if (this != &other)
    {
      this->salary = other.salary;
      _copyName(other.name);
      _copyManager(other.manager);
    }

    return *this;
  }

  ~Employee()
  {
    _clear();
  }

  Employee &operator+=(Employee *other)
  {
    // Employee kasier;
    // kasier += new Employee("bai petar", 3);
    // => this == &kasier;

    Employee *boss = findBoss(this);
    boss->manager = other;
  }

  char *getName() { return name; }
  int getSalary() { return salary; }
  Employee *getManager() { return manager; }

  bool hasManager() { return manager != nullptr; }
};

Employee *findBossRec(Employee *begin)
{
  if (begin == nullptr || !begin->hasManager())
  {
    return begin;
  }

  return findBossRec(begin->getManager());
}

Employee *findBoss(Employee *begin)
{
  // for (begin; begin != nullptr && begin->hasManager(); begin = begin->getManager()) {}
  // return begin;

  while (begin != nullptr && begin->hasManager())
  {
    begin = begin->getManager();
  }
  return begin;
}

int main()
{
  // Test initialization and copying
  cout << "Init kasier1\n";
  Employee kasier1("kasiera spas", 13, new Employee("upravitelq tosho", 4000, new Employee("bai ivan", 1000000, nullptr)));
  cout << "Init kasier2\n";
  Employee kasier2 = kasier1;

  // Test addition of last node
  kasier1 += new Employee("bai petar", 3);
  cout << "NAME OF BIG BOSS " << findBoss(&kasier1)->getName() << endl;
  return 0;
}