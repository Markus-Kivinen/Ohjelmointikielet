#ifndef ZOO_H
#define ZOO_H

#include <map>

#include "Animal.h"

class Zoo {
 protected:
  std::map<std::string, Animal *> animals;

 public:
  Animal *add(Animal *a);
  Animal *remove(const std::string &name);
  void print();
  void printSortedByName();
  void printSortedByAge();
  ~Zoo();
};

#endif