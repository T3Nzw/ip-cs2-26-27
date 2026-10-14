# Седмица 1 - Примерни решения

## Задача 1
```cpp
#include <iostream>

int main() {
    int a, b, c;

    std::cin >> a >> b >> c;

    int sum = a + b;
    bool isSumDevisibleByC = sum % c == 0;

    std::cout << isSumDevisibleByC << std::endl;

    return 0;
}
```

## Задача 4
- В тази задача разглеждаме Short-circuit evaluation
```cpp
unsigned short a = 2, b = 5, c = 6;

// a = 3, b = 5, c = 6, dummyOr = true
bool dummyOr = a == b || a++ ;

// a = 3, b = 4, c = 6, dummyAnd = false
bool dummyAnd = b-- && b == c && a++;

// a = 3, b = 5, c = 5, dummyCheck = true
bool dummyCheck = a == b || b++ && c-- || a++ && b == c; 

std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
std::cout << std::boolalpha;
std::cout << "dummyOr: " << dummyOr << ", dummyAnd: " << dummyAnd;
std::cout << ", dummyCheck: " << dummyCheck << std::endl;
```

## Задача 5
- В тази задача се разглежда основен алгоритъм: Обхождане на число
```cpp
#include <iostream>

int main() {
    unsigned num1, num2;

    std::cin >> num1 >> num2;

    unsigned num1Reversed = 0;
    num1Reversed += (num1 % 10) * 1000;
    num1 /= 10;
    num1Reversed += (num1 % 10) * 100;
    num1 /= 10;
    num1Reversed += (num1 % 10) * 10;
    num1 /= 10;
    num1Reversed += (num1 % 10) * 1;

    bool isPalyndrome = num1Reversed == num2;

    std::cout << isPalyndrome << std::endl;

    return 0;
}
```
- Друг подход за обръщане на число
```cpp
int numReversed = num % 10;
num /= 10;
numReversed = numReversed * 10 + num % 10;
num /= 10;
numReversed = numReversed * 10 + num % 10;
num /= 10;
numReversed = numReversed * 10 + num;
```

## Задача 6
```cpp
#include <iostream>

int main() {
    unsigned number; 

    std::cin >> number;

    bool isUppercaseLatin = number >= 'A' && number <= 'Z';

    std::cout << isUppercaseLatin << std::endl;

    return 0;
}
```

## Задача 7
```cpp
#include <iostream>

int main() {
    const double PI = 3.14;
    double r, h;

    std::cin >> r >> h;

    double B = PI * r * r;
    double S = 2 * PI * r * h;
    double S1 = S + 2 * B;
    double V = B * h;

    std::cout << "Лицето на основата: " << B << ", ";
    std::cout << "Околна повърнина: " << S << ", ";
    std::cout << "Пълна повърхнина: " << S1 << ", ";
    std::cout << "Oбем: " << V << std::endl;

    return 0;
}
```

## Задача 8
```cpp
#include <iostream>
#include <cmath>

int main() {
    double xA, yA, xB, yB, xC, yC;

    std::cin >> xA >> yA;
    std::cin >> xB >> yB;
    std::cin >> xC >> yC;

    double AB = sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
    double AC = sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));
    double BC = sqrt((xB - xC) * (xB - xC) + (yB - yC) * (yB - yC));

    /* Алтернативно решение с pow():

    double AB = sqrt(pow((xA - xB), 2) + pow((yA - yB), 2));
    double AC = sqrt(pow((xA - xC), 2) + pow((yA - yC), 2));
    double BC = sqrt(pow((xB - xC), 2) + pow((yB - yC), 2));

    имайте предвид, че pow() е много по-бавна от умножението 
    и затова не се препоръчва за по-ниски степени!
    */

    bool doesExist = (AB + AC) > BC && (AB + BC) > AC && (AC + BC) > AB;

    std::cout << doesExist << std::endl;

    return 0;
}
``` 

## Задача 9
```cpp
#include <iostream>

int main() {
    double x1, y1, r1, x2, y2, r2;
    double x, y;

    std::cin >> x1 >> y1 >> r1;
    std::cin >> x2 >> y2 >> r2;
    std::cin >> x >> y;

    bool isInCircle1 = (x - x1) * (x - x1) + (y - y1) * (y - y1) <= r1 * r1;
    bool isInCircle2 = (x - x2) * (x - x2) + (y - y2) * (y - y2) <= r2 * r2;
    bool isInIntersection = isInCircle1 && isInCircle2;

    std::cout << isInIntersection << std::endl;

    return 0;
}
```

## Задача 10
```cpp
#include <iostream>

int main() {
    const char PARROT = 'p', CAT = 'c';

    char cage1, cage2, cage3;
    char cage4, cage5, cage6;
    char cage7, cage8, cage9;

    std::cin >> cage1 >> cage2 >> cage3;
    std::cin >> cage4 >> cage5 >> cage6;
    std::cin >> cage7 >> cage8 >> cage9;

    // Има ли папагал на пода
    bool isParrotOnFloor = cage7 == PARROT || cage8 == PARROT || cage9 == PARROT;

    // Има самотен папагал
    bool cage1HasLonelyParrot = cage1 == PARROT && cage2 != PARROT && cage4 != PARROT;
    bool cage2HasLonelyParrot = cage2 == PARROT && (
        cage1 != PARROT &&
        cage4 != PARROT && 
        cage5 != PARROT
    );
    bool cage3HasLonelyParrot = cage3 == PARROT && cage2 != PARROT && cage6 != PARROT;
    bool cage4HasLonelyParrot = cage4 == PARROT && cage1 != PARROT && cage5 != PARROT;
    bool cage5HasLonelyParrot = cage5 == PARROT && (
        cage2 != PARROT && 
        cage4 != PARROT && 
        cage6 != PARROT
    );
    bool cage6HasLonelyParrot = cage6 == PARROT && cage3 != PARROT && cage5 != PARROT;
    bool hasLonelyParrot = (
        cage1HasLonelyParrot || 
        cage2HasLonelyParrot ||
        cage3HasLonelyParrot || 
        cage4HasLonelyParrot ||
        cage5HasLonelyParrot ||
        cage6HasLonelyParrot
    );
    // Няма как да има изолиран папагал на пода

    // Има папагал с две котки за съседи
    bool cage2IsEndangered = cage2 == PARROT && (
        (cage1 == CAT && cage5 == CAT) ||
        (cage3 == CAT && cage5 == CAT)
    );
    bool cage4IsEndangered = cage4 == PARROT && cage7 == CAT && (
        cage1 == CAT || 
        cage5 == CAT
    );
    bool cage5IsEndangered = cage5 == PARROT && (
        (cage2 == CAT && cage8 == CAT) ||
        (cage4 == CAT && cage6 == CAT) ||
        (cage8 == CAT && (cage4 == CAT || cage6 == CAT)) ||
        (cage2 == CAT && (cage4 == CAT || cage6 == CAT))
    );
    bool cage6IsEndangered = cage6 == PARROT && cage9 == CAT && (
        cage3 == CAT || 
        cage5 == CAT
    );

    bool hasEndangeredParrot = (
        cage2IsEndangered ||
        cage4IsEndangered || 
        cage5IsEndangered ||
        cage6IsEndangered
    );
    /* Ако непроверените папагали са застрашени, 
    то те ще са изолирани, за което вече сме проверили! */

    bool isValidOrder = !isParrotOnFloor && !hasLonelyParrot && !hasEndangeredParrot;

    std::cout << std::boolalpha << isValidOrder << std::endl;

    return 0;
}
```