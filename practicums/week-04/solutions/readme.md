# Седмица 4 - Примерни решения

## Задача 1
```cpp
unsigned myAbs(int num) {
    return num < 0 ? -num : num;
}
```

## Задача 2
```cpp
unsigned short charToNum(char num) {
    return num - '0';
}
```

## Задача 3
```cpp
// По стойност
char upper(char letter) {
    return letter + 'A' - 'a';
}

// Чрез указател
void upper(char* letter) {
    *letter += 'A' - 'a';
}

// По референция
void upper(char& letter) {
    letter += 'A' - 'a';
}
```

## Задача 4
```cpp
unsigned digitAmount(unsigned num) {
    if (!num) return 1;

    unsigned count = 0;
    while (num) {
        num /= 10;
        count++;
    }

    return count;
}
```

## Задача 5
```cpp
unsigned flagsUpAmount(unsigned num) {
    unsigned count = 0;
    while (num) {
        if (num %2 != 0) count++;

        num /= 2;
    }

    return count;
}
```

## Задача 6
```cpp
int myPow(int a, unsigned n) {
    int result = 1;
    for (unsigned i = 1; i <= n; ++i) {
        result *= a;
    }

    return result;
}
```

## Задача 7
```cpp
bool hasRealZero(double a, double b, double c) {
    if (a == 0) {
        std::cout << "Това уравнение не е квадратно!" << std::endl;

        return false;
    }

    return (b * b - 4 * a * c) >= 0;
}
```

## Задача 8
```cpp
unsigned sumDigits(unsigned num) {
    unsigned sum = 0;
    while (num) {
        sum += num %10;

        num /= 10;
    }

    return sum;
}
```

## Задача 9
```cpp
#include <iostream>

double add(double lhs, double rhs) {
    return lhs + rhs;
}

double subtract(double lhs, double rhs) {
    return lhs - rhs;
}

double multiply(double lhs, double rhs) {
    return lhs * rhs;
}

double divide(double lhs, double rhs) {
    // Данните идват проверени!
    return lhs / rhs;
}


int main() {
    double lhsOperand, rhsOperand;
    char operation;

    std::cin >> lhsOperand >> operation >> rhsOperand;
    double result;

    switch (operation) {
        case '+': result = add(lhsOperand, rhsOperand); break;
        case '-': result = subtract(lhsOperand, rhsOperand); break;
        case '*': result = multiply(lhsOperand, rhsOperand); break;
        case '/':
            if (rhsOperand == 0) {
                std::cout << "Невалидна операция!" << std::endl;

                return 0;
            }

            result = divide(lhsOperand, rhsOperand);
            break;
        default:
            std::cout << "Невалидна операция!" << std::endl;
            return 0;
    }

    std::cout << lhsOperand << " ";
    std::cout << operation << " ";
    std::cout << rhsOperand << " ";
    std::cout << "=" << " ";
    std::cout << result << std::endl;

    return 0;
}
```

## Задача 10
```cpp
#include <iostream>
#include <cmath>

char upper(char letter) {
    if (letter <= 'Z') 
        return letter;

    return letter + 'A' - 'a';
}

double rectArea(double a, double b) {
    return a * b;
}

double trapezoidArea(double a, double b, double h) {
    return (a + b) / 2 * h;
}

double kiteArea(double d1, double d2) {
    return (d1 * d2) / 2;
}

double circleArea(double r) {
    return M_PI * r * r;
}

double getLength() {
    double num;
    std::cout << "Въведете дължина: ";
    std::cin >> num;

    while (num < 0) {
        std::cout << "Въведете ВАЛИДНА дължина: ";
        std::cin >> num;
    }
    
    return num;
}

int main() {
    char shape;
    double a, S;

    std::cin >> shape;

    switch (upper(shape)) {
        case 'S': 
            a = getLength();
            S = rectArea(a, a);
            break;
        case 'R': 
            S = rectArea(getLength(), getLength());
            break;
        case 'T':
            S = trapezoidArea(getLength(), getLength(), getLength());
            break;
        case 'K':
            S = kiteArea(getLength(), getLength());
            break;
        case 'C':
            S = circleArea(getLength());
            break;

        default:
            std::cout << "Невалидна фигура" << std::endl;
            return 0;
    }

    std::cout << "S = " << S << std::endl;

    return 0;
}
```