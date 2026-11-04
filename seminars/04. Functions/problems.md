# Задачи

## Задача 00

Задачите от миналия път, понеже всичките бяха за функции. :(

## Задача 01

Какво ще изведе следният кодов фрагмент:

```cpp
#include <iostream>

int foo(int const &x) {
  return x+3;
}

int main() {
  int x = 10;
  std::cout << foo(x+1) << std::endl;
  std::cout << foo(x)   << std::endl;
}
```

## Задача 02

Какви са (потенциалните) проблеми в следния кодов фрагмент:

```cpp
 1. short& square(int n) {
 2.  return n^2;
 3. }
 4.
 5. void add1(int& x) {
 6.   return x++;
 7. }
 8.
 9. int main() {
10.   std::cout << square(256) << std::endl;
11.   int const x = 20;
12.   int& y = x;
13.   add1(y);
14.
```

Запишете редовете, в които виждате проблем, и какъв е той.
