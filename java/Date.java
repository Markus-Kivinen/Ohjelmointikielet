public class Date implements Comparable<Date>  {
    private int y;
    private int m;
    private int d;

    public Date() {
        this(1900, 1,1);
    }

    public Date(int year, int month, int day) {
        if (!setValues(year, month, day)) {
            throw new IllegalArgumentException("Invalid date: " + year + "-" + month + "-" + day);
        }
    }

    public int getYear() {
        return y;
    }

    public void setYear(int year) {
        this.y = year;
    }

    public int getMonth() {
        return m;
    }

    public void setMonth(int month) {
        this.m = month;
    }

    public int getDay() {
        return d;
    }

    public void setDay(int day) {
        this.d = day;
    }

    public boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    public boolean isValid(int year, int month, int day) {
        if (year < 1900 || year > 2030 || month < 1 || month > 12) {
            return false;
        }

        int[] daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxDays = daysInMonth[month - 1];

        if (month == 2 && isLeapYear(year)) {
            maxDays = 29;
        }

        return day >= 1 && day <= maxDays;
    }

    public boolean setValues(int year, int month, int day) {
        if (isValid(year, month, day)) {
            this.y = year;
            this.m = month;
            this.d = day;
            return true;
        } else {
            return false;
        }
    }

    @Override
    public String toString() {
        return String.format("%04d-%02d-%02d", y, m, d);
    }

    @Override
    public int compareTo(Date other) {
        if (this.y != other.y) {
            return Integer.compare(this.y, other.y);
        }
        if (this.m != other.m) {
            return Integer.compare(this.m, other.m);
        }
        return Integer.compare(this.d, other.d);
    }
}
