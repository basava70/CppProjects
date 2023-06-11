/**
 *
 * The following code is part of template practise exercise.
 *  C++ program to perform arithmetic operations on the data.
 *  Written on 1 June 2023.
 *
 **/
#include <iostream>

template <typename T> class Calculator {
private:
  T num1;
  T num2;
  bool is_add = false, is_subtract = false, is_multiply = false,
       is_divide = false;

public:
  Calculator(T n1, T n2) : num1(n1), num2(n2) {}

  T add() {
    is_add = true;
    return num1 + num2;
  }
  T subtract() {
    is_subtract = true;
    return num1 - num2;
  }
  T multiply() {
    is_multiply = true;
    return num1 * num2;
  }
  T divide() {
    is_divide = true;
    return num1 / num2;
  }

  void print() {
    std::cout << "Numbers are : " << num1 << " " << num2 << std::endl;
    if (is_add)
      std::cout << "Addition : " << add() << std::endl;
    if (is_subtract)
      std::cout << "Subtraction : " << subtract() << std::endl;
    if (is_add)
      std::cout << "Multiplication : " << multiply() << std::endl;
    if (is_add)
      std::cout << "Division : " << divide() << std::endl;
  }
};

int main() {
  int i1, i2;
  float f1, f2;
  char c1, c2;

  std::cout << "Template practise problem" << std::endl;
  std::cout << "Arithmetic Operations" << std::endl;

  std::cout << " Enter the two integers " << std::endl;
  std::cin >> i1 >> i2;

  std::cout << " Enter the two floating-point integers " << std::endl;
  std::cin >> f1 >> f2;

  Calculator<int> int_calc(i1, i2);
  Calculator<float> float_calc(f1, f2);

  int_calc.add();
  int_calc.subtract();
  int_calc.multiply();
  int_calc.divide();

  float_calc.add();
  float_calc.subtract();
  float_calc.multiply();
  float_calc.divide();

  int_calc.print();
  float_calc.print();
}
