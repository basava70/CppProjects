/**
 *
 * The following code is part of template practise exercise.
 *  C++ program to swap the data.
 *  Written on 1 June 2023.
 *
 **/
#include <iostream>

template <typename T> void Swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

int main() {
  int i1, i2;
  float f1, f2;
  char c1, c2;

  std::cout << "Template practise problem" << std::endl;
  std::cout << "Swap numbers" << std::endl;

  std::cout << " Enter the two integers " << std::endl;
  std::cin >> i1 >> i2;

  std::cout << " Enter the two floating-point integers " << std::endl;
  std::cin >> f1 >> f2;

  std::cout << " Enter the two characters " << std::endl;
  std::cin >> c1 >> c2;

  std::cout << "Before swapping values " << std::endl;
  std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
  std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
  std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;

  Swap(i1, i2);
  Swap(f1, f2);
  Swap(c1, c2);

  std::cout << "After swapping values " << std::endl;
  std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
  std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
  std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
}
