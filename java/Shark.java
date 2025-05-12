public class Shark extends Animal implements Comparable<Shark> {
    private Sea sea;
    public static final Sea DEFAULT_SEA = Sea.UNKNOWN;

    public Shark() {
        super();
        this.sea = DEFAULT_SEA;
    }

    public Shark(String name) {
        this(name, new Date(), 0.0, Gender.OTHER, DEFAULT_SEA);
    }
    
    public Shark(String name, Date birth, double weight, Sea sea) {
        this(name, birth, weight, Gender.OTHER, sea);
    }

    public Shark(String name, Date birth, double weight, Gender gender, Sea sea) {
        super(name, birth, weight, gender);
        this.sea = sea;
    }

    public Sea getSea() {
        return sea;
    }

    public void setSea(Sea sea) {
        this.sea = sea;
    }

    @Override
    public void move() {
        System.out.println("Shark " + getName() + " is moving.");
    }

    @Override
    public void utter() {
        System.out.println("Shark " + getName() + " is gargling.");
    }

    @Override
    public String toString() {
        return "Name: " + getName() + ", Birth: " + getBirth() + ", Weight: " + getWeight() +
                "kg, Gender: " + getGender() + ", Sea: " + sea;
    }

    @Override
    public int compareTo(Shark other) {
        return this.getName().compareTo(other.getName());
    }
}
