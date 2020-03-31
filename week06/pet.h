#ifndef PET_H_
#define PET_H_

class Pet
{
private:
  char *name;

  void _copyName(const char *_name);
  void _clear();

protected:
  int age;

public:
  Pet(const char *name = nullptr, int age = 0);
  Pet(const Pet &other);
  Pet &operator=(const Pet &other);
  virtual ~Pet();

  char *getName() { return this->name; }
  virtual int getAge() { return this->age; }
};

#endif