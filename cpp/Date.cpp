#include "Date.h"

#include <string>

Date::Date() : y(1900), m(1), d(1) {}
Date::Date(int y, int m, int d) : y(y), m(m), d(d) {
  if (!isValid(y, m, d)) {
    this->y = 1900;
    this->m = 1;
    this->d = 1;
  }
}

std::string Date::ToString() const {
  return std::to_string(y) + "-" + std::to_string(m) + "-" + std::to_string(d);
}

bool Date::isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isValid(int year, int month, int day) {
  if (year < 1900 || year > 2030 || month < 1 || month > 12) return false;

  const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int maxDays = daysInMonth[month - 1];

  if (month == 2 && isLeapYear(year)) {
    maxDays = 29;
  }

  return day >= 1 && day <= maxDays;
}

bool Date::setValues(int year, int month, int day) {
  if (isValid(year, month, day)) {
    y = year;
    m = month;
    d = day;
    return true;
  }
  return false;
}

bool Date::operator<(const Date &other) const {
  if (y != other.y) return y < other.y;
  if (m != other.m) return m < other.m;
  return d < other.d;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
  os << date.ToString();
  return os;
}