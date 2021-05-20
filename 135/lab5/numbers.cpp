//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab 5a

#include <iostream>

bool isDivisibleBy(int n, int d) {
  if (d == 0) {//no division by zero
    return false;
  }
  else if (n % d == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  for(int d = 2; d < n; d++) {

    if (isDivisibleBy(n, d)) {//if divisible; thus not prime
      return false;
    }

  }
  return true;//not divisible at any point, thus prime
}

int nextPrime(int n) {
  int next = n;
  bool breaker = false;
  while (breaker == false) {
    next++;
    breaker = isPrime(next);
  }
  return next;
}

int countPrimes(int a, int b) {
  int totalPrimes = 0;
  for (int tick = a; tick <= b; tick++){

    if (isPrime(tick)) {
      totalPrimes++;
    }

  }
  return totalPrimes;
}

bool isTwinPrime(int n) {
  if (isPrime(n)) {
    if (isPrime(n+2) || isPrime(n-2)) {
      return true;
    }
  }
  else {
    return false;
  }
  return false;
}

int nextTwinPrime(int n) {
  int next = n;
  bool breaker = false;
  while (breaker == false) {
    next++;
    breaker = isTwinPrime(next);
  }
  return next;
}

int largestTwinPrime(int a, int b) {
  int outcome = -1;
  for(int tick = a; tick <= b; tick++) {
    if (isPrime(tick)) {
      if (isTwinPrime(tick)) {
        outcome = tick;
      }
    }
  }
  return outcome;
}

int main() {
  int divided, divisor;
  //int prime;//set up vars

  //std::cout << "Enter a number: ";
  //std::cin >> prime;

  //bool outcome = isPrime(prime);
  //int next = nextPrime(prime);

  //std::cout << next << std::endl;

  std::cout << "Enter two numbers" << std::endl;
  std::cout << "First number: ";
  std::cin >> divided;
  std::cout << "Second number: ";
  std::cin >> divisor;

  //take in info

  //bool outcome = isTwinPrime(prime);//find outcome
  int next = largestTwinPrime(divided, divisor);

  std::cout << next << std::endl;
  /*
  if (outcome) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }//decisions: yes or no?
  */

  return 0;
}
