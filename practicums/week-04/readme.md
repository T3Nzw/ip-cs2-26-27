# Седмица 4 - Функции

## 1. Декларация на фунцкия
```
<return-type> <function-name>([<param_1>, ..., <param_n>]);
```

- `<return-type>` - типът, който фунцкия ще връща. Това може да е всеки един тип или `void` (нищо)
- `void` пример:
```cpp
void printSum(double a, double b);
```

- `<function-name>` - името на фунцкията. Използва се за извикване на функцията: `<function-name>(<arg_1>, ..., <arg_n>);`
- `<param_1>, ..., <param_n>` - параметри на фунцкията. При извикване на фунцкия, тя очаква да получи същия брой аргументи от съответните типове.
- Пример:
```cpp
void printResult(unsigned short number, char colour);
/* ... */
printResult(17, 'b');
```

## 2. Дефиниция
```
<return-type> <function-name>([<param_1>, ..., <param_n>]) {
    // тяло
}
```
- Дефинираното тяло на фунцкията се изпълнява, когато фунцкията бъде извикана.
- Ако извикаме фунцкия, която не е дефинирана, ще получим грешка.
- Ако фунцкията не е с тип на връщане `void`, тя **задължително** трябва да връща съответната стойност с ключовата дума `return`.
- `return` пример:
```cpp
double sum(double a, double b) {
    return a + b;
}
```

## 3. Програмен стек, стекови рамки и области на идентификаторите

- Пример:
```cpp
#include <iostream>

// GLOBAL
const unsigned aUpdate = 5;

void byValue(unsigned a) {
    // LOCAL
    a += aUpdate;
}

void byPointer(unsigned* a) {
    // LOCAL
    *a += aUpdate;
}

void byReference(unsigned& a) {
    // LOCAL
    a += aUpdate;
}

int main(){
    // LOCAL
    unsigned a = 0;

    byValue(a);
    std::cout << a << " ";
    byPointer(&a);
    std::cout << a << " ";
    byReference(a);
    std::cout << a << std::endl;

    return 0;
}
```


# Зaдачи
## Задача 0 - Храна за размисъл
### 1.1. Размяна по стойност
```cpp
void swap(unsigned a, unsigned b) {
    unsigned temp = a;
    a = b;
    b = a;
}
```

### 1.2. Размяна с указател
```cpp
void swap(unsigned* a, unsigned* b) {
    unsigned temp = *a;
    *a = *b;
    *b = temp;
}
```

### 1.3. Размяна с псевдоним
```cpp
void swap(unsigned& a, unsigned& b) {
    unsigned temp = a;
    a = b;
    b = temp;
}
```

### 2. Разпределяне на задачите
```cpp
double division(double a, double b) {
    if (b == 0) 
        return a;

    return a / b; 
}

void printDivision(double a, double b) {
    double result = division(a, b);
    if (result == a && b != 1) {
        std::cout << "Invalid operation!" << std::endl;
        return;
    }

    std::cout << result << std::endl;
}

int main(){
    for (unsigned short num = 0; num <= 2; ++num) {
        printDivision(2, num);
    }
    
    return 0;
}
```

### 3. Връщане на указател
```cpp
double* sum(double a, double b) {
    double result = a + b;
    return &result;
}

int main(){
    double* resultPtr = sum(4, 5);
    double* differentResultPtr = sum(6, 7);

    std::cout << *resultPtr << std::endl;
    
    return 0;
}
```

### 4. Типове
```cpp
double divide(double a, int b) {
    return a / b;
}

int main(){
    char result = divide('a', 2.89);

    std::cout << result << std::endl;
    
    return 0;
}
```

### 5. Кое е `a`?
```cpp
int a = 10;

void printA(bool condition = true) {
    if (condition) {
        int a = 20;
        if (condition){
            int a = 30;
            std::cout << a << std::endl;
        }

        if (condition) {
            std::cout << a << std::endl;
        }
    }

    std::cout << a << std::endl;
}
```
## Задача 1
Напишете функция, която пресмята модула на число.

## Задача 2
Напишете фунцкия, която получава цифра, като символ, и я преобразува в цяло число.

## Задача 3
Напишете фунцкия, която получава малка латинска буква и я преобразува в голяма латинска буква. Реализирайте функцията както с предаване по стойност, така и с предаване по указател.

## Задача 4
Напишете фунцкия, която получава цяло положително число и връща броя на цифрите му.
- Примери:
```cpp
std::cout << digitAmount(1234) << std::endl; // 4
std::cout << digitAmount(0) << std::endl; // 1
std::cout << digitAmount(1234567890) << std::endl; // 10
```

## Задача 5
Напишете фунцкия, която получава цяло число и връща броя на "1"-те в двоичното му представяне.
- Примери:
```cpp
std::cout << flagsUpAmount(15) << std::endl; // 4
std::cout << flagsUpAmount(64) << std::endl; // 1
std::cout << flagsUpAmount(2027) << std::endl; // 9
```

## Задача 6
Напишете функция, която получава число и цяло положително число, съответно `a` и `n`, и връща `a` на степен `n`.
- Примери:
```cpp
std::cout << myPow(2, 11) << std::endl; // 2048
std::cout << myPow(3, 0) << std::endl; // 1
std::cout << myPow(2027, 1) << std::endl; // 2027
```

Note: Нека приемем, че подадените данни са вече валидирани. За решението не може да се използват вградени функции!

## Задача 7
Напишете фунцкия, която получава три числа, коефициентите `a`, `b` и `c` на квадратно уравнение, и връща дали то има реален корен.

## Задача 8
Напишете функция, която получава цяло положително число и връща сумата на цифрите му.
```cpp
std::cout << sumDigits(1234) << std::endl; // 10
std::cout << sumDigits(123456789) << std::endl; // 45
std::cout << sumDigits(235563224) << std::endl; // 32
```

## Задача 9 - Несложен калкулатор Част 2
Напишете функции, които приемат две числа и изпълняват основните операции `+`, `-`, `*` и `\`. С помощта на функциите реализирайте несложен калкулатор.

## Задача 10 - Четириъгълници
Напишете функции, които пресмятат и връщат лицата на изброените фигури. С помощта на функциите, реализирайте програма, която приема символ и спрямо него отпечатва лицето на избраната фигура.
|Символ|Фигура|Прочетени данни|Формула за лице|
|------|------|---------------|---------------|
|S|Квадрат|а - страна| S = a * a|
|R|Правоъгълник|a, b - страни| S = a * b |
|T|Трапец| a, b - основи, h - височина | S = (a + b) / 2 * h|
|К|Хвърчило| d1, d2 - диагонали | S = (d1 * d2) / 2|
|C|Кръг| r - радиус | S = π * r * r |
