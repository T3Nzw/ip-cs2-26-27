#include <ios>
#include <iostream>

// f(x)

// декларация
unsigned int absValue(int x) {
  // тяло
  return x < 0 ? -x : x;
}

// '0'
bool isDigit(char c) {
  // c >= 48 && c <= 57
  return c >= '0' && c <= '9';
}

bool isUpper(char c) {
  return c >= 'A' && c <= 'Z';
}

bool isLower(char c) {
  return c >= 'a' && c <= 'z';
}

bool isLetter(char c) {
  return isUpper(c) || isLower(c);
}

int main() {

  std::cout << std::boolalpha;

  std::cout << absValue(-10) << '\n';

  std::cout << isDigit('7') << '\n';

  std::cout << isLetter(']') << '\n';

  return 0;
}
