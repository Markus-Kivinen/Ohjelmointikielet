#ifndef SHARK_H
#define SHARK_H

#include <string>

#include "Animal.h"

enum class Sea {
  Atlantic,
  Pacific,
  Indian,
  Arctic,
  Antarctic,
  Mediterranean,
  Caribbean,
  RedSea,
  ArabianSea,
  CoralSea,
  BeringSea,
  SouthChinaSea,
  Unknown
};

inline std::string ToString(Sea sea) {
  switch (sea) {
    case Sea::Atlantic:
      return "Atlantic";
    case Sea::Pacific:
      return "Pacific";
    case Sea::Indian:
      return "Indian";
    case Sea::Arctic:
      return "Arctic";
    case Sea::Antarctic:
      return "Antarctic";
    case Sea::Mediterranean:
      return "Mediterranean";
    case Sea::Caribbean:
      return "Caribbean";
    case Sea::RedSea:
      return "Red Sea";
    case Sea::ArabianSea:
      return "Arabian Sea";
    case Sea::CoralSea:
      return "Coral Sea";
    case Sea::BeringSea:
      return "Bering Sea";
    case Sea::SouthChinaSea:
      return "South China Sea";
    default:
      return "Unknown";
  }
}

inline std::ostream &operator<<(std::ostream &os, Sea sea) {
  os << ToString(sea);
  return os;
}

class Shark : public Animal {
 private:
  Sea sea;

 public:
  void setSea(Sea sea) { this->sea = sea; }
  Sea getSea() const { return sea; }

  Shark();
  Shark(std::string name);
  Shark(std::string name, Date birth, double weight, Sea sea);
  Shark(std::string name, Date birth, double weight, Gender gender, Sea sea);

  std::string ToString() const override;

  void move() override;
  void utter() override;

  virtual ~Shark() {}
};

#endif