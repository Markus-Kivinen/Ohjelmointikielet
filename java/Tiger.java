public class Tiger extends Animal implements Comparable<Tiger> {
    private Continent continent;
    public static final Continent DEFAULT_CONTINENT = Continent.UNKNOWN;

    public Tiger() {
        super();
        this.continent = Continent.UNKNOWN;
    }

    public Tiger(String name) {
        this(name, DEFAULT_BIRTH, 0.0, DEFAULT_GENDER, DEFAULT_CONTINENT);
    }

    public Tiger(String name, Date birth, double weight, Continent continent) {
        this(name, birth, weight, DEFAULT_GENDER, continent);
    }

    public Tiger(String name, Date birth, double weight, Gender gender, Continent continent) {
        super(name, birth, weight, gender);
        this.continent = continent;
    }

    public Continent getContinent() {
        return continent;
    }

    public void setContinent(Continent continent) {
        this.continent = continent;
    }

    @Override
    public void move() {
        System.out.println("Tiger " + getName() + " is moving.");
    }

    @Override
    public void utter() {
        System.out.println("Tiger " + getName() + " is roaring.");
    }

    @Override
    public String toString() {
        return "Name: " + getName() + ", Birth: " + getBirth() + ", Weight: " + getWeight() +
                "kg, Gender: " + getGender() + ", Continent: " + continent;
    }

    @Override
    public int compareTo(Tiger other) {
        return this.getName().compareTo(other.getName());
    }
}
