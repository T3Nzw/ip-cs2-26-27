# Седмица 3 - Примерни решения

## Задача 1
```cpp
#include <iostream>

int main(){
    unsigned a, b;
    std::cin >> a >> b;

    unsigned * ptrA = &a;
    unsigned * ptrB = &b;

    unsigned temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    std::cout << a << ' ' << b << std::endl;

    return 0;
}
```

## Задача 2
```cpp
#include <iostream>

int main() {
    unsigned num;
    std::cin >> num;

    bool isSquare = false;
    for (unsigned i = 1; i * i <= num; ++i) {
        if (i * i == num) {
            isSquare = true;
            break;
        }
    }
    
    std::cout << (isSquare ? "Да" : "Не") << std::endl;

    return 0;
}
```

## Задача 3
```cpp
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int sum = 0;
    for (int num = a; num <= b; ++num)
        sum += num;
    
    std::cout << sum << std::endl;

    return 0;
}
```

## Задача 4
```cpp
#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int min = num, max = num;
    while (num) {
        if (num < min)
            min = num;

        if (num > max)
            max = num;

        std::cin >> num;
    }

    std::cout << "min = " << min << "; ";
    std::cout << "max = " << max << std::endl;

    return 0;
}
```

## Задача 5
```cpp
#include <iostream>

int main() {
    unsigned num;
    std::cin >> num;

    unsigned evenCount = 0, evenSum = 0;
    unsigned oddCount = 0, oddSum = 0;

    unsigned revNum = 0;
    while (num) {
        revNum *= 10;
        revNum += num %10;
        num /= 10;
    }

    bool isEven = false;
    unsigned currDigit;
    while (revNum) {
        currDigit = revNum %10;

        if (isEven) {
            evenSum += currDigit;
            evenCount ++;
        } else {
            oddSum += currDigit;
            oddCount++;
        }

        revNum /= 10;
        isEven = !isEven;
    }

    float evenAvg = (float) evenSum / evenCount;
    float oddAvg = (float) oddSum / oddCount;

    if (evenAvg > oddAvg)
        std::cout << "evenAvg = " << evenAvg << std::endl;
    else 
        std::cout << "oddAvg = " << oddAvg << std::endl;

    return 0;
}
```

## Задача 6
```cpp
#include <iostream>

int main() {
    unsigned num;
    std::cin >> num;

    unsigned long long revBinNum = 1; // За водещи нули
    while (num) {
        revBinNum = revBinNum * 10 + num %2;

        num /= 2;
    }

    unsigned long long binNum = 0;
    while (revBinNum) {
        binNum *= 10;
        binNum += revBinNum %10;
        revBinNum /= 10;
    }

    binNum /= 10; // Премахване на единицата за водещи нули

    std::cout << binNum << std::endl;

    return 0;
}
```

## Задача 7
```cpp
#include <iostream>

int main() {
    unsigned num;
    std::cin >> num;

    for (unsigned i = 1; i <= num; ++i)
        if (num %i == 0)
            std::cout << i << " ";

    std::cout << std::endl;
    
    return 0;
}
```

## Задача 8
```cpp
#include <iostream>

int main() {
    unsigned a, b;
    std::cin >> a >> b;

    unsigned tempNum, revNum;
    for (unsigned num = a; num <= b; ++num) {
        tempNum = num;
        unsigned revNum = 0;

        while (tempNum) {
            revNum *= 10;
            revNum += tempNum %10;
            tempNum /= 10;
        }

        if (num == revNum)
            std::cout << num << " ";

    }
    
    std::cout << std::endl;

    return 0;
}
```

## Задача 9
```cpp
#include <iostream>

int main() {
    unsigned num;
    std::cin >> num;

    unsigned currSum = 0;
    do {
        std::cout << num << " -> ";
        while (num) {
            currSum += num %10;
            num /= 10;
        }
        num = currSum;
        currSum = 0;
    } while (num > 9);

    std::cout << num << std::endl;

    return 0;
}
```

## Задача 10
```cpp
#include <iostream>

int main() {
    int operand;
    char operation;
    std::cin >> operand;
    double result = operand;

    do {
        std::cin >> operation;

        switch (operation){
            case '+': 
                std::cin >> operand;
                result += operand; 
                break;
            case '-': 
                std::cin >> operand;
                result -= operand;
                break;
            case '*': 
                std::cin >> operand;
                result *= operand; 
                break;
            case '/':
                std::cin >> operand; 
                if (operand == 0) {
                    std::cout << "Невалидна операция!" << std::endl;
                    return 0;
                }
                result /= operand;
                break;
            case '=': break;
            default:
                std::cout << "Невалидна операция!" << std::endl;
                return 0;
        }
    } while (operation != '=');

    std::cout << result << std::endl;

    return 0;
}
```

## Задача 11
```cpp
#include <iostream>

int main() {
    unsigned n;
    char direction;
    std::cin >> n >> direction;
    if (direction != '>' && direction != '<') {
        std::cout << "Невалидна посока!" << std::endl;

        return 0;
    }
    
    unsigned num = 1;
    for (unsigned i = 0; i < n; ++i) {
        if (direction == '>')
            for (unsigned j = 0; j < n; ++j)
                std::cout << num + j << " ";
        else
            for (int j = n - 1; j >= 0; --j)
                std::cout << num + j << " ";
        
        num += n;
        direction = direction == '>' ? '<' : '>';     
        
        std::cout << std::endl;
    }

    
    return 0;
}
```

## Задача 12 - Триъгълничета
```cpp
#include <iostream>

int main() {
    unsigned rows;
    char alignment, symbol;

    std::cin >> rows >> alignment >> symbol;
    if (alignment != 'l' && alignment != 'c' && alignment != 'r') {
        std::cout << "Невалиден формат!" << std::endl;

        return 0;
    }

    for (unsigned i = 1; i <= rows; ++i) {
        if (alignment != 'l')
            for (unsigned j = i; j < rows; ++j) {
                std::cout << ' ';
                std::cout << (alignment == 'r' ? ' ' : '\0');
            }
        
        for (unsigned j = 1; j <= i; ++j)
            std::cout << symbol << ' ';

        std::cout << std::endl;
    }

    return 0;
}
```

## Задача 13 - Бикове и крави Част 2
```cpp
#include <iostream>

int main() {
    unsigned playerOneNumber, playerTwoNumber;
    std::cout << "Играч 1 си намисля числото: ";
    std::cin >> playerOneNumber;
    std::cout << "Играч 2 си намисля числото: ";
    std::cin >> playerTwoNumber;

    bool guessing = true;
    bool playerOneTurn = true;

    while (guessing) {
        std::cout << "Играч " << (playerOneTurn ? 1 : 2) << " казва: ";
        unsigned short number = playerOneTurn ? playerOneNumber : playerTwoNumber;
        unsigned short guess;
        std::cin >> guess;

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

        std::cout << '!' << std::endl;

        if (bullsAmount == 4) {
            guessing = false;
            continue;
        }

        playerOneTurn = !playerOneTurn;
    }

    std::cout << "Играч " << (playerOneTurn? 1 : 2) << " е победител!!!" << std::endl;

    return 0;
}
```