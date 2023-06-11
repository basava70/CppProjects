/**
 *
 * The following code is part of template practise exercise.
 *  C++ program to find the largest number.
 *  Written on 1 June 2023.
 *
 **/
#include <iostream>

template <class T> T LargestNumber(T a, T b) { return (a > b) ? a : b; }

int main() {
  int i1, i2;
  float f1, f2;
  char c1, c2;

  std::cout << "Template Practise problem" << std::endl;
  std::cout << "Calculate Largest Number" << std::endl;
  std::cout << "Enter two integers" << std::endl;
  std::cin >> i1 >> i2;
  std::cout << "Largest integer is " << LargestNumber(i1, i2) << std::endl;

  std::cout << "Enter two floating-point integers" << std::endl;
  std::cin >> f1 >> f2;
  std::cout << "Largest floating-point integer is " << LargestNumber(f1, f2)
            << std::endl;

  std::cout << "Enter two characters" << std::endl;
  std::cin >> c1 >> c2;
  std::cout << "Largest ASCII valued character is " << LargestNumber(c1, c2)
            << std::endl;
}
