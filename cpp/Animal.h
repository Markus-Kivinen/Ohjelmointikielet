#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

#include "Date.h"

enum class Gender { Male, Female, Other };

inline std::string ToString(Gender gender) {
  switch (gender) {
    case Gender::Male:
      return "Male";
    case Gender::Female:
      return "Female";
    case Gender::Other:
      return "Other";
    default:
      return "Unknown";
  }
}

inline std::ostream &operator<<(std::ostream &os, const Gender &gender) {
  os << ToString(gender);
  return os;
}

class Animal {
 protected:
  std::string name;
  Date birth;
  double weight;
  Gender gender;

 public:
  void setName(std::string name) { this->name = name; }
  void setBirth(Date birth) { this->birth = birth; }
  void setWeight(double weight) { this->weight = weight; }
  void setGender(Gender gender) { this->gender = gender; }

  std::string getName() const { return name; }
  Date getBirth() const { return birth; }
  double getWeight() const { return weight; }
  Gender getGender() const { return gender; }

  Animal();
  Animal(std::string name, Date birth, double weight, Gender gender);

  virtual void move() = 0;
  virtual void utter() = 0;
  virtual std::string ToString() const = 0;

  friend std::ostream &operator<<(std::ostream &os, const Animal &animal);
  virtual ~Animal() {}
};

#endif
