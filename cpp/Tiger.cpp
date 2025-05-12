#include "Tiger.h"

#include <cmath>
#include <iostream>
#include <sstream>

Tiger::Tiger()
    : Animal("", Date(), 0.0, ::Gender::Other), continent(Continent::Unknown) {}

Tiger::Tiger(std::string name)
    : Animal(name, Date(), 0.0, ::Gender::Other),
      continent(Continent::Unknown) {}

Tiger::Tiger(std::string name, Date birth, double weight, ::Continent continent)
    : Animal(name, birth, weight, ::Gender::Other), continent(continent) {}

Tiger::Tiger(std::string name, Date birth, double weight, ::Gender gender,
             ::Continent continent)
    : Animal(name, birth, weight, gender), continent(continent) {}

std::string Tiger::ToString() const {
  std::stringstream ss;
  ss << "Name: " << name << ", Birth " << birth.ToString()
     << ", Weight: " << weight << "kg"
     << ", Gender: " << gender << ", Continent: " << continent;
  return ss.str();
}
void Tiger::move() {
  std::cout << "Tiger " << name << " is moving." << std::endl;
}

void Tiger::utter() {
  std::cout << "Tiger " << name << " is roaring." << std::endl;
}