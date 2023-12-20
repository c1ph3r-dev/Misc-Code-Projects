#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include "../class_utils.h"

class Person
{
private:
  std::string Name;
  int Age;
public:
  Person() = default;
  ~Person() = default;

  void SayHello() const;

  MAKE_ACCESSORS(std::string, Name)
  MAKE_ACCESSORS(int, Age)
};


#endif // PERSON_H_