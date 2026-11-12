# Седмица 6 - Примерни решения

## Задача 1 - Цифрова война
```cpp
#include <iostream>

int main(){
    int num;
    std::cin >> num;
    bool isNegative = num < 0;
    bool player1TurnRev = isNegative;
    unsigned player1Cards = 0, player2Cards = 0;

    unsigned deck = isNegative ? -num : num;

    while (deck) {
        if (player1TurnRev)
            player1Cards = player1Cards * 10 + deck %10;
        else
            player2Cards = player2Cards * 10 + deck %10;

        player1TurnRev = !player1TurnRev;
        deck /= 10;
    }

    unsigned player1Points = 0, player2Points = 0;
    unsigned short player1Card, player2Card;
    unsigned short prevWin = 0; // 0, 1, 2;
    while (player1Cards && player2Cards) {
        player1Card = player1Cards %10;
        player2Card = player2Cards %10;

        if (player1Card > player2Card) {
            ++player1Points;
            prevWin = 1;
        } else if (player1Card < player2Card) {
            ++player2Points;
            prevWin = 2;
        } else if (prevWin == 1) {
            ++player1Points;
        } else if (prevWin == 2) {
            ++player2Points;
        }

        player1Cards /= 10;
        player2Cards /= 10;
    }

    if (player1Points > player2Points)
        std::cout << "Играч 1 печели!" << std::endl;
    else if (player1Points < player2Points)
        std::cout << "Играч 2 печели!" << std::endl;
    else if (isNegative)
        std::cout << "Играч 1 печели!" << std::endl;
    else
        std::cout << "Играч 2 печели!" << std::endl;

    return 0;
}
```

## Задача 2
```cpp
const size_t ROWS = 1024; 
const size_t COLS = 9; // unsigned limit

unsigned charToDigit(char number) {
    return number - '0'; // Assuming it's valid
}

unsigned charRowToNum(char row[], size_t size) {
    unsigned result = 0;
    for (size_t idx = 0; idx < size; ++idx)
        result = result * 10 + charToDigit(row[idx]);

    return result;
}

size_t getBiggestRow(char matrix[ROWS][COLS], size_t rows, size_t cols) {
    size_t maxRow = 0;

    for (size_t row = 1; row < rows; ++row)
        if (charRowToNum(matrix[row], cols) > charRowToNum(matrix[maxRow], cols))
            maxRow = row;

    return maxRow;
}
```

## Задача 3 - Шампионат по шах
```cpp
#include <iostream>

const size_t MAX_COMPETITORS = 1024;

void swap(unsigned& lhs, unsigned& rhs) {
    unsigned temp = lhs;
    lhs = rhs;
    rhs = temp;
}

size_t getValidSize() {
    size_t size;
    do {
        std::cin >> size;
    } while (size > MAX_COMPETITORS);

    return size;
}

unsigned getPlayerResult(unsigned points) {
    unsigned result = 0;

    while (points) {
        result += points %3;
        points /= 3;
    }

    return result;
}

void sortPlayers(unsigned results[], size_t size) {
    for (size_t idx = 0; idx < size; ++idx)
        for (size_t jdx = 0; jdx < size - 1 - idx; ++jdx)
            if (getPlayerResult(results[jdx]) < getPlayerResult(results[jdx + 1]))
                swap(results[jdx], results[jdx + 1]);
}

void inputResults(unsigned results[], size_t size) {
    for (size_t idx = 0; idx < size; ++idx)
        std::cin >> results[idx];
}

void outputResults(unsigned results[], size_t size) {
    for (size_t idx = 0; idx < size; ++idx)
        std::cout << idx + 1 << ". " <<  results[idx] << std::endl;
}

int main(){
    unsigned results[MAX_COMPETITORS];
    size_t size = getValidSize();
    inputResults(results, size);
    sortPlayers(results, size);
    outputResults(results, size);

    return 0;
}
```