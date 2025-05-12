#include <iostream>
#include <string>

#include "Animal.h"
#include "Date.h"
#include "Shark.h"
#include "Tiger.h"
#include "Zoo.h"

int main() {
  Zoo zoo;

  zoo.add(new Tiger("Keijo", Date(2010, 5, 16), 220.5, Gender::Male, Continent::Asia));
  zoo.add(new Tiger("Aaro", Date(2005, 3, 10), 200.0, Gender::Male, Continent::Europe));
  zoo.add(new Shark("Zorro", Date(2000, 7, 25), 300.0, Gender::Female, Sea::Atlantic));

// Eläimen korvaus
  std::cout << "\nTesting animal replacement:" << std::endl;
  auto replaced = zoo.add(new Tiger("Keijo", Date(2010, 5, 16), 210, Gender::Male, Continent::Asia));
  if (replaced != nullptr) {
    std::cout << "Replaced existing animal: " << replaced->getName() << std::endl;
    delete replaced;
  }
 
// Manuaalinen syntymäpäivä
  Date birthday = Date(1992, 12, 27);
  birthday.setDay(28);
  zoo.add(new Shark("Make", birthday, 80.0, Gender::Male, Sea::Pacific));

// Kaikkien printtaus
  std::cout << "\nAll animals in the Zoo:" << std::endl;
  zoo.print();

// Eläimen poistaminen
  std::cout << "\nTesting animal removal:" << std::endl;
  Animal *removedAnimal = zoo.remove("Keijo");
  if (removedAnimal) {
    std::cout << "Removed animal: " << *removedAnimal << std::endl;
    delete removedAnimal;
  }

// Nimi sortattu printtaus
  std::cout << "\nAnimals sorted by name:" << std::endl;
  zoo.printSortedByName();

// Ikä sortattu printtaus
  std::cout << "\nAnimals sorted by age:" << std::endl;
  zoo.printSortedByAge();

  return 0;
}