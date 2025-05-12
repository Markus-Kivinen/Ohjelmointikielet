#ifndef TIGER_H
#define TIGER_H

#include <string>

#include "Animal.h"

enum class Continent {
  Africa,
  Asia,
  Europe,
  NorthAmerica,
  SouthAmerica,
  Australia,
  Antarctica,
  Unknown
};

inline std::string ToString(Continent continent) {
  switch (continent) {
    case Continent::Africa:
      return "Africa";
    case Continent::Asia:
      return "Asia";
    case Continent::Europe:
      return "Europe";
    case Continent::NorthAmerica:
      return "North America";
    case Continent::SouthAmerica:
      return "South America";
    case Continent::Australia:
      return "Australia";
    case Continent::Antarctica:
      return "Antarctica";
    default:
      return "Unknown";
  }
}

inline std::ostream &operator<<(std::ostream &os, Continent continent) {
  os << ToString(continent);
  return os;
}

class Tiger : public Animal {
 private:
  Continent continent;

 public:
  void setContinent(Continent continent) { this->continent = continent; }
  Continent getContinent() const { return continent; }

  Tiger();
  Tiger(std::string name);
  Tiger(std::string name, Date birth, double weight, Continent continent);
  Tiger(std::string name, Date birth, double weight, Gender gender, Continent continent);
  std::string ToString() const override;

  void move() override;
  void utter() override;

  virtual ~Tiger() {}
};

#endif