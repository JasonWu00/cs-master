//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 10a

#include <cmath>
#include <iostream>

class Time {
public:
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
public:
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

int minutesSinceMidnight(Time time) {
  //calculates total minutes since last midnight
  return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later) {
  //calculates difference in minutes between two times
  return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min) {
  //increments time
  time0.m += min;
  while (time0.m >= 60) {//accounting for multiple hours added
    time0.h += 1;
    time0.m -= 60;
  }
  return time0;
}

void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts) {
  printMovie(ts.movie);
  Time endTime = addMinutes(ts.startTime, ts.movie.duration);
  std::cout << "[starts at "
            << ts.startTime.h << ":"
            << ts.startTime.m
            << ", ends by "
            << endTime.h << ":"
            << endTime.m
            << "]" << std::endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
  return {nextMovie, addMinutes(ts.startTime, ts.movie.duration)};
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
  int earlier_end, later_start;
  if (minutesUntil(ts1.startTime, ts2.startTime) >= 0) {//if ts1 is earlier
     earlier_end = minutesSinceMidnight(ts1.startTime) + ts1.movie.duration;
     later_start = minutesSinceMidnight(ts2.startTime);
  }
  else {//ts2 is earlier
     later_start = minutesSinceMidnight(ts1.startTime);
     earlier_end = minutesSinceMidnight(ts2.startTime) + ts2.movie.duration;
  }
  //print debugs
  std::cout << "earlier end and later start: " << earlier_end << " " << later_start << std::endl;
  if (earlier_end > later_start) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot night = {{"End of the War to End All Wars", ACTION, 125}, {19, 30}};//not a real movie
  TimeSlot closing = {{"STAR WARS Episode III: Revenge of the Sith", ACTION, 140}, {22, 00}};

  printTimeSlot(morning);
  printTimeSlot(daytime);
  printTimeSlot(evening);
  printTimeSlot(night);
  printTimeSlot(closing);

  TimeSlot three_am = scheduleAfter(closing, {"Expiration Date", COMEDY, 15});
  //technically a movie
  printTimeSlot(three_am);
  std::cout <<timeOverlap({{"The Wolf of Wall Street", COMEDY, 180}, {10, 30}},
                          {{"5 Centimeters Per Second", DRAMA, 63}, {11, 30}}) << std::endl;
  return 0;
}
