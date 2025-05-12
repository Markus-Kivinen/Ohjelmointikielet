#include "Shark.h"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

Shark::Shark() : Animal("", Date(), 0.0, ::Gender::Other), sea(Sea::Unknown) {}

Shark::Shark(std::string name)
    : Animal(name, Date(), 0.0, ::Gender::Other), sea(Sea::Unknown) {}

Shark::Shark(std::string name, Date birth, double weight, ::Sea sea)
    : Animal(name, birth, weight, ::Gender::Other), sea(sea) {}

Shark::Shark(std::string name, Date birth, double weight, ::Gender gender,
             ::Sea sea)
    : Animal(name, birth, weight, gender), sea(sea) {}

std::string Shark::ToString() const {
  std::stringstream ss;
  ss << "Name: " << name << ", Birth " << birth.ToString()
     << ", Weight: " << weight << "kg"
     << ", Gender: " << gender << ", Sea: " << sea;
  return ss.str();
}

void Shark::move() {
  std::cout << "Shark " << name << " is moving." << std::endl;
}

void Shark::utter() {
  std::cout << "Shark " << name << " is gargling." << std::endl;
}