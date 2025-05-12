import java.util.Comparator;
import java.util.TreeMap;
import java.util.Map;

public class Zoo {
    private Map<String, Animal> animals;

    public Zoo() {
        animals = new TreeMap<>();
    }

    public Animal add(Animal animal) {
        Animal replaced = animals.put(animal.getName(), animal);
        return replaced;
    }

    public Animal remove(String name) {
        return animals.remove(name);
    }

    public void print() {
        for (Animal animal : animals.values()) {
            System.out.println(animal);
        }
    }

    public void printSortedByName() {
        for (Animal animal : animals.values()) {
            System.out.println("Key: [" + animal.getName() +
                    "], Value: [" + animal + "]");
        }
    }

    // 5. Add a method in Zoo to find animals by name.
    public Animal findByName(String name) {
        return animals.get(name);
    }

    public void printSortedByAge() {
        animals.values().stream()
                .sorted(Comparator.comparing(Animal::getBirth)
                        .thenComparing(Animal::getWeight)
                        .thenComparing(Animal::getName))
                .forEach(System.out::println);
    }
}
