//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab quiz 8

#include <iostream>

class Date {
public:
  int year;
  int month;
  int day;
  std::string day_of_week;
};

void printDate(Date* input) {
  std::cout << input->day_of_week << ", " << input->month << "/" << input->day << "/" << input->year << std::endl;
}
