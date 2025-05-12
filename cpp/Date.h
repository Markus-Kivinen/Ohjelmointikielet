#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
 protected:
  int y;
  int m;
  int d;

  bool isLeapYear(int year);
  bool isValid(int year, int month, int day);

 public:
  int getYear() const { return y; }
  int getMonth() const { return m; }
  int getDay() const { return d; }

  void setYear(int year) { y = year; }
  void setMonth(int month) { m = month; }
  void setDay(int day) { d = day; }

  Date();
  Date(int y, int m, int d);

  std::string ToString() const;
  bool setValues(int y, int m, int d);

  bool operator<(const Date &other) const;

  friend std::ostream &operator<<(std::ostream &os, const Date &date);
};
#endif