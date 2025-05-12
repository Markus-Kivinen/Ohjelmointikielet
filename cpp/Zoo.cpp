#include "Zoo.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Animal.h"
#include "Date.h"
#include "Tiger.h"

Animal *Zoo::add(Animal *a) {
  Animal *replaced = nullptr;
  auto it = animals.find(a->getName());
  if (it != animals.end()) {
    replaced = it->second;
  }
  animals[a->getName()] = a;
  return replaced;
}

Animal *Zoo::remove(const std::string &name) {
  auto it = animals.find(name);
  if (it != animals.end()) {
    Animal *removed = it->second;
    animals.erase(it);
    return removed;
  }
  return nullptr;
}

void Zoo::print() {
  for (const auto &pair : animals) {
    std::cout << pair.second->ToString() << std::endl;
  }
}

void Zoo::printSortedByName() {
  for (const auto &pair : animals) {
    std::cout << "Key: [" << pair.first << "], Value: ["
              << pair.second->ToString() << "]" << std::endl;
  }
}

void Zoo::printSortedByAge() {
  // Date sisältää operator< järjestämistä varten
  // Multimap mahdollistaa usean eläimen samalla syntymäpäivällä
  std::multimap<Date, Animal *> sortedAnimals;
  for (const auto &pair : animals) {
    sortedAnimals.insert(std::make_pair(pair.second->getBirth(), pair.second));
  }
  for (const auto &pair : sortedAnimals) {
    std::cout << pair.second->ToString() << std::endl;
  }
}

Zoo::~Zoo() {
  for (auto &pair : animals) {
    delete pair.second;
  }
  animals.clear();
}