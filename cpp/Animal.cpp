#include "Animal.h"

#include <cmath>
#include <sstream>

Animal::Animal()
    : name(""), birth(Date()), weight(0.0), gender(::Gender::Other) {}

Animal::Animal(std::string name, Date birth, double weight, ::Gender gender)
    : name(name), birth(birth), weight(weight), gender(gender) {}

std::string Animal::ToString() const {
  std::stringstream ss;
  ss << "Name: " << name << ", Birth " << birth << ", Weight: " << weight
     << "kg, Gender: " << gender;
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Animal &animal) {
  os << animal.ToString();
  return os;
}