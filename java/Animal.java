import java.util.Objects;

public abstract class Animal {
    private String name;
    private Date birth;
    private double weight;
    private Gender gender;
    public static final Gender DEFAULT_GENDER = Gender.OTHER;
    public static final Date DEFAULT_BIRTH = new Date();

    public Animal() {
        this("", DEFAULT_BIRTH, 0.0, DEFAULT_GENDER);
    }

    public Animal(String name, Date birth, double weight, Gender gender) {
        this.name = name;
        this.birth = birth;
        this.weight = weight;
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Date getBirth() {
        return birth;
    }

    public void setBirth(Date birth) {
        this.birth = birth;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public Gender getGender() {
        return gender;
    }

    public void setGender(Gender gender) {
        this.gender = gender;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Animal animal = (Animal) obj;
        return Double.compare(animal.weight, weight) == 0 &&
                name.equals(animal.name) &&
                birth.equals(animal.birth) &&
                gender == animal.gender;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, birth, weight, gender);
    }

    public abstract void move();

    public abstract void utter();

    public abstract String toString();
}
