public enum Gender {
    MALE, FEMALE, OTHER;
    public static final Gender DEFAULT = OTHER;

    @Override
    public String toString() {
        return EnumUtils.toString(name());
    }

    public static Gender fromString(String value) {
        return EnumUtils.fromString(value, Gender.class, DEFAULT);
    }
}