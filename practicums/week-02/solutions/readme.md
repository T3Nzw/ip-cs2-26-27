# Седмица 2 - Примерни решения

## Задача 1
```cpp
#include <iostream>

int main() {
    int num;
    std::cin >> num; 
    std::cout << (num %2 == 0 ? "Да" : "Не") << std::endl;

    return 0;
}
```

## Задача 2
```cpp
#include <iostream>

int main() {
    int num;
    std::cin >> num; 

    unsigned abs_num = num < 0 ? -num : num;
    std::cout << abs_num << std::endl;

    return 0;
}
```

## Задача 3
```cpp
#include <iostream>

int main() {
    unsigned short num;
    std::cin >> num;

    unsigned short digit3 = num % 10;
    num /= 10;
    unsigned short digit2 = num % 10;
    num /= 10;
    unsigned short digit1 = num % 10;

    unsigned short temp_swap;
    if (digit1 > digit2) {
        temp_swap = digit1;
        digit1 = digit2;
        digit2 = temp_swap;
    }

    if (digit2 > digit3) {
        temp_swap = digit2;
        digit2 = digit3;
        digit3 = temp_swap;
    }

    if (digit1 > digit2) {
        temp_swap = digit1;
        digit1 = digit2;
        digit2 = temp_swap;
    }

    std::cout << digit1 << digit2 << digit3 << std::endl;

    return 0;
}
```

## Задача 4
```cpp
#include <iostream>

int main() {
    float x, y;
    std::cin >> x >> y;

    if (x == 0 || y == 0)
        std::cout << "Не принадлежи на квадрант!" << std::endl;
    else
        if (y > 0)
            if (x > 0)
                std::cout << "I квадрант" << std::endl;
            else
                std::cout << "II квадрант" << std::endl;
        else
            if (x < 0)
                std::cout << "III квадрант" << std::endl;
            else
                std::cout << "IV квадрант" << std::endl;

    return 0;
}
```

## Задача 5
```cpp
#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        std::cout << "Невалидна дължина!" << std::endl;

        return 0;
    }

    bool isValid = b + c > a && a + c > b && a + b > c;

    if (isValid) {
        std::cout << "съществува: ";
    } else {
        std::cout << "не съществува" << std::endl;

        return 0;
    }

    
    if (a == b && b == c) std::cout << "равностранен" << std::endl;
    else if (a == b || b == c || a == c) std::cout << "равнобедрен" << std::endl;
    else std::cout << "разностранен" << std::endl;

    return 0;
}
```

## Задача 6
- Пример за switch оператор без break-ове на всеки case
```cpp
#include <iostream>
#include <cmath>

int main() {
    char figure;
    std::cin >> figure;
    
    double V, a, b, c, r, h;
    bool isAThird = false; // Reusing logic: Prism <-> Pyramid and Cylinder <-> Cone

    switch (figure){
        case 'C':
            std::cin >> a;
            if (a < 0) {
                std::cout << "Невалидна дължина!" << std::endl;

                return 0;
            }
            V = a * a * a;
            break;
        case 'P':
            std::cin >> a >> b >> c;
            if (a < 0 || b < 0 || c < 0) {
                std::cout << "Невалидна дължина!" << std::endl;

                return 0;
            }
            V = a * b * c;
            break;
        case 'S':
            std::cin >> r;
            if (r < 0) {
                std::cout << "Невалидна дължина!" << std::endl;

                return 0;
            }
            V = (M_PI * r * r * r) * 4/3;
            break;
        case 'E': isAThird = true;
        case 'N':
            std::cin >> a >> h;
            if (a < 0 || h < 0) {
                std::cout << "Невалидна дължина!" << std::endl;

                return 0;
            }
            V = isAThird ? (a * a * h) * 1/3 : (a * a * h);
            break;
        case 'T': isAThird = true;
        case 'H':
            std::cin >> r >> h;
            if (r < 0 || h < 0) {
                std::cout << "Невалидна дължина!" << std::endl;

                return 0;
            }
            V = isAThird ? (M_PI * r * r * h) * 1/3 : (M_PI * r * r * h);
            break;
        default: 
            std::cout << "Символът не е поддържан!" << std::endl; 
            return 0;
    }

    std::cout << "V = " << V << std::endl;

    return 0;
}
```

## Задача 7
```cpp
#include <iostream>

int main() {
    int num1, num2;
    std::cin >> num1 >> num2;

    unsigned short num1_abs = num1 < 0 ? -num1 : num1;
    unsigned short num2_abs = num2 < 0 ? -num2 : num2;

    if (num1_abs < num2_abs) std::cout << num1 << std::endl;
    else std::cout << num2 << std::endl;

    return 0;
}
```

## Задача 8
```cpp
#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "Уравнението не е квадратно!" << std::endl;

        return 0;
    }

    double D = b * b - 4 * a * c;

    if (D < 0) {
        std::cout << "Няма реални корени" << std::endl;

        return 0;
    }

    double x1 = (-b + sqrt(D)) / (2 * a);

    if (D == 0) {
        std::cout << "x_1,2 = " << x1 << std::endl;

        return 0;
    }

    double x2 = (-b - sqrt(D)) / (2 * a);

    std::cout << "x_1 = " << x1 << "; x_2 = " << x2 << std::endl;

    return 0;
}
```

## Задача 9
```cpp
#include <iostream>

int main() {
    unsigned num;
    std::cin >> num;

    unsigned short week_num = num % 7;
    unsigned week_amount = num / 7;

    switch (week_num) {
        case 1: std::cout << "Понделник"; break;
        case 2: std::cout << "Вторник"; break;
        case 3: std::cout << "Сряда"; break;
        case 4: std::cout << "Четвъртък"; break;
        case 5: std::cout << "Петък"; break;
        case 6: std::cout << "Събота"; break;
        case 0: std::cout << "Неделя"; break;
    }

    if (week_num != 0) // Ако не е неделя, week_amount ще изостава с 1 седмица
        week_amount += 1; 

    if (week_amount > 1) std::cout << " #" << week_amount;

    std::cout << std::endl;

    return 0;
}
```

## Задача 10 - Несложен калкулатор
```cpp
#include <iostream>

int main() {
    double lhsOperand, rhsOperand, result;
    char operation;

    std::cin >> lhsOperand >> operation >> rhsOperand;

    switch (operation) {
        case '+': result = lhsOperand + rhsOperand; break;
        case '-': result = lhsOperand - rhsOperand; break;
        case '*': result = lhsOperand * rhsOperand; break;
        case '/':
            if (rhsOperand == 0) {
                std::cout << "Невалидна операция!" << std::endl;

                return 0;
            }
            result = lhsOperand / rhsOperand;
            break;
        default:
            std::cout << "Невалидна операция!" << std::endl;
            return 0;
    }

    std::cout << lhsOperand << " " << operation << " " << rhsOperand;
    std::cout << " = " << result << std::endl;

    return 0;
}
```

## Задача 11 - Бикове и крави
```cpp
#include <iostream>

int main(){
    unsigned short number, guess;
    std::cin >> number >> guess;

    unsigned short nDigit1 = number % 10;
    number /= 10;
    unsigned short nDigit2 = number % 10;
    number /= 10;
    unsigned short nDigit3 = number % 10;
    number /= 10;
    unsigned short nDigit4 = number % 10;

    unsigned short gDigit1 = guess % 10;
    guess /= 10;
    unsigned short gDigit2 = guess % 10;
    guess /= 10;
    unsigned short gDigit3 = guess % 10;
    guess /= 10;
    unsigned short gDigit4 = guess % 10;

    bool digit1Match = nDigit1 == gDigit1;
    bool digit2Match = nDigit2 == gDigit2;
    bool digit3Match = nDigit3 == gDigit3;
    bool digit4Match = nDigit4 == gDigit4;

    unsigned short bullsAmount = 0, cowsAmount = 0;

    bool gDigit1InNum = gDigit1 == nDigit2 || gDigit1 == nDigit3 || gDigit1 == nDigit4;
    bool gDigit2InNum = gDigit2 == nDigit1 || gDigit2 == nDigit3 || gDigit2 == nDigit4;
    bool gDigit3InNum = gDigit3 == nDigit1 || gDigit3 == nDigit2 || gDigit3 == nDigit4;
    bool gDigit4InNum = gDigit4 == nDigit1 || gDigit4 == nDigit2 || gDigit4 == nDigit3;
    
    if (!digit1Match) {
        if (gDigit1InNum) cowsAmount++;
    } else bullsAmount++;

    if (!digit2Match) {
        if (gDigit2InNum) cowsAmount++;
    } else bullsAmount++;

    if (!digit3Match) {
        if (gDigit3InNum) cowsAmount++;
    } else bullsAmount++;
    
    if (!digit4Match) {
        if (gDigit4InNum) cowsAmount++;
    } else bullsAmount++;

    if (bullsAmount) {
        std::cout << bullsAmount << " бик";
        std::cout << (bullsAmount > 1 ? "a " : " ");

        std::cout << (cowsAmount ? "и " : "");
    }

    if (cowsAmount) {
        std::cout << cowsAmount << " крав";
        std::cout << (cowsAmount > 1 ? "и" : "a");
    }

    std::cout << std::endl;

    return 0;
}
```

## Задача 12 - Римски цифри
```cpp
#include <iostream>

int main() {
    unsigned short num;
    std::cin >> num;

    if (num == 0 && num > 1000) {
        std::cout << "Невалиден вход!" << std::endl;

        return 0;
    }

    if (num == 1000) {
        std::cout << "M" << std::endl;

        return 0;
    }

    unsigned short ones = num % 10;
    num /= 10;
    unsigned short tens = num % 10;
    num /= 10;
    unsigned short hundreds = num % 10;
    
    switch (hundreds) {
        case 1: std::cout << "C"; break;
        case 2: std::cout << "CC"; break;
        case 3: std::cout << "CCC"; break;
        case 4: std::cout << "CD"; break;
        case 5: std::cout << "D"; break;
        case 6: std::cout << "DC"; break;
        case 7: std::cout << "DCC"; break;
        case 8: std::cout << "DCCC"; break;
        case 9: std::cout << "CM"; break;
    }

    switch (tens) {
        case 1: std::cout << "X"; break;     
        case 2: std::cout << "XX"; break;
        case 3: std::cout << "XXX"; break;
        case 4: std::cout << "XL"; break;
        case 5: std::cout << "L"; break;
        case 6: std::cout << "LX"; break;
        case 7: std::cout << "LXX"; break;
        case 8: std::cout << "LXXX"; break;
        case 9: std::cout << "XC"; break;
    }

    switch (ones) {
        case 1: std::cout << "I"; break;
        case 2: std::cout << "II"; break;
        case 3: std::cout << "III"; break;
        case 4: std::cout << "IV"; break;
        case 5: std::cout << "V"; break;
        case 6: std::cout << "VI"; break;
        case 7: std::cout << "VII"; break;
        case 8: std::cout << "VIII"; break;
        case 9: std::cout << "IX"; break;
    }

    std::cout << std::endl;

    return 0;
}
```

## Задача 13 - Бакалия
```cpp
#include <iostream>
#include <cmath>

int main() {
    unsigned code;
    unsigned daysOnShelf;

    std::cin >> code >> daysOnShelf;
    
    unsigned short digit6 = code % 10;
    code /= 10;
    unsigned short digit5 = code % 10;
    code /= 10;
    unsigned short digit4 = code % 10;
    code /= 10;
    unsigned short digit3 = code % 10;
    code /= 10;
    unsigned short digit2 = code % 10;
    code /= 10;
    unsigned short digit1 = code % 10;

    unsigned shelfLife;

    switch (digit1) {
        case 1: 
            shelfLife = abs(((digit2 * 10) + digit4) - digit3 * digit5); 
            break;
        case 2:
            shelfLife = floor(((digit3 + digit5) / 2) + digit2);
            break;
        case 3:
            shelfLife = abs(digit2 + digit4 - digit6);
            break;
        case 4:
            shelfLife = floor((digit3 + digit4 + digit6) / 3);
        default:
            std::cout << "Invalid code!" << std::endl;
            return 0;
    }

    bool hasExpired = shelfLife < daysOnShelf;

    std::cout << (hasExpired ? "Не" : "Да") << std::endl;

    return 0;
}
```

## Задача 14 - Числа в думи
```cpp
#include <iostream>

int main() {
    short num;
    std::cin >> num;

    if (num < -999 || num > 999) {
        std::cout << "Невалиден вход!" << std::endl;

        return 0;
    }

    if (num == 0) {
        std::cout << "нула :)" << std::endl;

        return 0;
    }

    bool hasMinus = num < 0;
    num = num < 0 ? -num : num;
    unsigned short ones = num % 10;
    num /= 10;
    unsigned short tens = num % 10;
    num /= 10;
    unsigned short hundreds = num % 10;

    if (hasMinus)
        std::cout << "минус ";
    
    switch (hundreds) {
        case 1: std::cout << "сто "; break;
        case 2: std::cout << "двеста "; break;
        case 3: std::cout << "триста "; break;
        case 4: std::cout << "четиристотин "; break;
        case 5: std::cout << "петстотин "; break;
        case 6: std::cout << "шестстотин "; break;
        case 7: std::cout << "седемстотин "; break;
        case 8: std::cout << "осемстотин "; break;
        case 9: std::cout << "деветстотин "; break;
    }

    if (hundreds != 0 && ones == 0) std::cout << "и ";

    switch (tens) {
        case 1: 
        if (hundreds != 0) std::cout << "и ";

        switch (ones) {
            case 0: std::cout << "десет"; break;
            case 1: std::cout << "единадесет"; break;
            case 2: std::cout << "дванадесет"; break;
            case 3: std::cout << "тринадесет"; break;
            case 4: std::cout << "четиринадесет"; break;
            case 5: std::cout << "петнадесе"; break;
            case 6: std::cout << "шестнадесет"; break;
            case 7: std::cout << "седемнадесет"; break;
            case 8: std::cout << "осемнадесет"; break;
            case 9: std::cout << "деветнадесет"; break;
        } 
        break;     
        case 2: std::cout << "двадесет "; break;
        case 3: std::cout << "тридесет "; break;
        case 4: std::cout << "четиридесет "; break;
        case 5: std::cout << "петдесет "; break;
        case 6: std::cout << "шестдесет "; break;
        case 7: std::cout << "седемдесет "; break;
        case 8: std::cout << "осемдесет "; break;
        case 9: std::cout << "деветдесет "; break;
    }

    if (tens == 1) {
        std::cout << std::endl;

        return 0;
    }

    if ((hundreds != 0 || tens != 0) && ones != 0) std::cout << "и ";

    switch (ones) {
        case 1: std::cout << "едно"; break;
        case 2: std::cout << "две"; break;
        case 3: std::cout << "три"; break;
        case 4: std::cout << "четири"; break;
        case 5: std::cout << "пет"; break;
        case 6: std::cout << "шест"; break;
        case 7: std::cout << "седем"; break;
        case 8: std::cout << "осем"; break;
        case 9: std::cout << "девет"; break;
    }

    std::cout << std::endl;

    return 0;
}
```