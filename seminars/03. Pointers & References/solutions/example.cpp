#include <iostream>

int main() {

  int a = 10;
  int const b = 20;

  int const *aptr = &a;

  int const &aref = a;

  // aref += 5;
  a += 5;

  std::cout << aref << '\n';

  return 0;
}
