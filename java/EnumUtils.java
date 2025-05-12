public class EnumUtils {

    public static String toString(String name) {
        name = name.toLowerCase();
        return name.substring(0, 1).toUpperCase() + name.substring(1);
    }

    public static <T extends Enum<T>> T fromString(String value, Class<T> enumType, T defaultValue) {
        try {
            return Enum.valueOf(enumType, value.toUpperCase());
        } catch (IllegalArgumentException e) {
            return defaultValue;
        }
    }
}