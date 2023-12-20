#include "Person.h"

#include <iostream>

void Person::SayHello() const
{
  std::cout << "Hello, my name is " << GetName() << " and I am " << GetAge() << std::endl;
}