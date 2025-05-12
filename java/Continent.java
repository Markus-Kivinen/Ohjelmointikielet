public enum Continent {
    AFRICA, ASIA, EUROPE, NORTH_AMERICA, SOUTH_AMERICA, AUSTRALIA, ANTARCTICA, UNKNOWN;
    public static final Continent DEFAULT = UNKNOWN;

    @Override
    public String toString() {
        return EnumUtils.toString(name());
    }

    public static Continent fromString(String value) {
        return EnumUtils.fromString(value, Continent.class, DEFAULT);
    }
}
