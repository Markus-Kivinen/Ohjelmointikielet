public enum Sea {
    ATLANTIC, PACIFIC, INDIAN, ARCTIC, ANTARCTIC, MEDITERRANEAN, CARIBBEAN,
    RED_SEA, ARABIAN_SEA, CORAL_SEA, BERING_SEA, SOUTH_CHINA_SEA, UNKNOWN;
    public static final Sea DEFAULT = UNKNOWN;

    @Override
    public String toString() {
        return EnumUtils.toString(name());
    }

    public static Sea fromString(String value) {
        return EnumUtils.fromString(value, Sea.class, DEFAULT);
    }
}
