public class Main {
// Tekijä Markus Kivinen
    public static void main(String[] args) {
        Zoo zoo = new Zoo();

    // Gender.fromString
        zoo.add(new Tiger("Keijo", new Date(2010, 5, 16), 220.5, Gender.fromString(("Male")), Continent.ASIA));
        zoo.add(new Tiger("Aaro", new Date(2005, 3, 10), 200.0, Gender.MALE, Continent.EUROPE));
        zoo.add(new Shark("Zorro", new Date(2000, 7, 25), 300.0, Gender.FEMALE, Sea.ATLANTIC));

    // Eläimen korvaus
        System.out.println("\nTesting animal replacement:");
        Animal replaced = zoo.add(new Tiger("Keijo", new Date(2010, 5, 16), 210, Gender.MALE, Continent.ASIA));
        if (replaced != null) System.out.println("Replaced existing animal: " + replaced.getName());
        
    // Manuaalinen syntymäpäivä
        Date birthday = new Date(1992, 11, 27);
        birthday.setDay(28);
        zoo.add(new Shark("Make", birthday, 80.0, Gender.MALE, Sea.PACIFIC));
        
    // Kaikkien printtaus
        System.out.println("\nAll animals in the Zoo:");
        zoo.print();


    // Eläimen poistaminen
        System.out.println("\nTesting animal removal:");
        Animal removedAnimal = zoo.remove("Keijo");
        if (removedAnimal != null) {
            System.out.println("Removed animal: " + removedAnimal);
        }
    // Nimi sortattu printtaus
        System.out.println("\nAnimals sorted by name:");
        zoo.printSortedByName();
    // Ikä sortattu printtaus
        System.out.println("\nAnimals sorted by age:");
        zoo.printSortedByAge();
    }
}
