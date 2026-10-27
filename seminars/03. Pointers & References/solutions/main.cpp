#include <iostream>

int main() {

  // дерефенциране при указатели
  // nullptr при указатели
  // указателите могат да сочат към различни адреси

  // &a взима адреса на a
  // *ptr взима стойността, която сочи ptr

  // nullptr
  int a = 42;
  int b = 10;
  int *ptr = &a;

  if (ptr)
    std::cout << *ptr << std::endl;

  int &ref = a;
  // ref = b;

  ptr = &b;

  std::cout << *ptr << std::endl;

  std::cout << a << std::endl;
  std::cout << ref << std::endl;

  const int c = 5;

  return 0;
}
