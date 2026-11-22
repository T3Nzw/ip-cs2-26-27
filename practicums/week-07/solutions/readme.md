# Седмица 7 - Примерни решения

## Задача 1
```cpp
void printMirrorPairs(const int* arr, size_t size) {
    for (size_t idx = 0; idx < size / 2; ++idx)
        std::cout << '(' << arr[idx] << ", " << arr[size - 1 - idx] << "); ";

    if (size %2 == 1)
        std::cout << '(' << arr[size / 2] << ')' << ';';

    std::cout << std::endl;
}
```

## Задача 2
```cpp
#include <iostream>

const size_t MAX_N = 1024;

size_t getValidSize(const size_t& boundary) {
    size_t n;
    do {
        std::cout << "Input n: ";
        std::cin >> n;
    } while (n > boundary);

    return n;
}

void inputMatrix(int matrix[][MAX_N], size_t n) {
    for (size_t row = 0; row < n; ++row)
        for (size_t col = 0; col < n; ++col)
            std::cin >> matrix[row][col];
}

int getBelowPrimarySum(const int matrix[][MAX_N], size_t n) {
    int sum = 0;
    for (size_t row = 0; row < n; ++row)
        for (size_t col = 0; col < row; ++col)
            sum += matrix[row][col];

    return sum;
}

int getAbovePrimarySum(const int matrix[][MAX_N], size_t n) {
    int sum = 0;
    for (size_t row = 0; row < n; ++row)
        for (size_t col = row + 1; col < n; ++col)
            sum += matrix[row][col];

    return sum;
}

int getBelowSecondarySum(const int matrix[][MAX_N], size_t n) {
    int sum = 0;
    for (size_t row = 0; row < n; ++row)
        for (size_t col = n - row; col < n; ++col)
            sum += matrix[row][col];

    return sum;
}

int getAboveSecondarySum(const int matrix[][MAX_N], size_t n) {
    int sum = 0;
    for (size_t row = 0; row < n; ++row)
        for (size_t col = 0; col < n - 1 - row; ++col)
            sum += matrix[row][col];

    return sum;
}

void printBelowPrimary(const int matrix[][MAX_N], size_t n) {
    for (size_t row = 0; row < n; ++row) {
        for (size_t col = 0; col < row; ++col)
            std::cout << matrix[row][col] << ' ';
        
        std::cout << std::endl;
    }
}

void printAbovePrimary(const int matrix[][MAX_N], size_t n) {
    for (size_t row = 0; row < n; ++row) {
        for (size_t col = 0; col <= row; ++col)
            std::cout << ' ' << ' ';

        for (size_t col = row + 1; col < n; ++col)
            std::cout << matrix[row][col] << ' ';
        
        std::cout << std::endl;
    }
}

void printBelowSecondary(const int matrix[][MAX_N], size_t n) {
    for (size_t row = 0; row < n; ++row){
        for (size_t col = 0; col < n - row; ++col)
            std::cout << ' ' << ' ';

        for (size_t col = n - row; col < n; ++col)
            std::cout << matrix[row][col] << ' ';
        
        std::cout << std::endl;
    }
}

void printAboveSecondary(const int matrix[][MAX_N], size_t n) {
    for (size_t row = 0; row < n; ++row) {
        for (size_t col = 0; col < n - 1 - row; ++col)
            std::cout << matrix[row][col] << ' ';

        std::cout << std::endl;
    }
}

size_t getMaxIdx(int* arr, size_t n) {
    size_t maxIdx = 0;
    for (size_t idx = 1; idx < n; ++idx)
        if (arr[idx] > arr[maxIdx])
            maxIdx = idx;

    return maxIdx;
}

int main() {
    int matrix[MAX_N][MAX_N];
    size_t n = getValidSize(MAX_N);

    inputMatrix(matrix, n);

    int tempArr[] = {
        getAbovePrimarySum(matrix, n),
        getBelowPrimarySum(matrix, n),
        getAboveSecondarySum(matrix, n),
        getBelowSecondarySum(matrix, n)
    };

    switch (getMaxIdx(tempArr, 4)) {
        case 0: printAbovePrimary(matrix, n); break;
        case 1: printBelowPrimary(matrix, n); break;
        case 2: printAboveSecondary(matrix, n); break;
        case 3: printBelowSecondary(matrix, n); break;
    }

    return 0;
}
```

## Задача 3
```cpp
const size_t N = 10;
void swap(int& lhs, int& rhs) {
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void transpose(int matrix[N][N]) {
    for (size_t idx = 0; idx < N; ++idx)
        for (size_t jdx = idx + 1; jdx < N; ++jdx)
            swap(matrix[idx][jdx], matrix[jdx][idx]);
}

void reverse(int* arr, size_t size) {
    for (size_t idx = 0; idx < size / 2; ++idx)
        swap(arr[idx], arr[size - 1 - idx]);
}

void rotate90(int matrix[N][N]) {
    transpose(matrix);
    for (size_t row = 0; row < N; ++row)
        reverse(matrix[row], N);
}

void rotate180(int matrix[N][N]) {
    reverse(&matrix[0][0], N * N);
}

void rotate(int matrix[N][N], unsigned angle) {
    switch (angle) {
        case 90: rotate90(matrix); break;
        case 180: rotate180(matrix); break;
        case 270: rotate90(matrix); rotate180(matrix); break;
    }
}
```

## Задача 4
```cpp
#include <iostream>

const size_t MAX_N = 1024;

size_t getValidSize(const size_t& boundary) {
    size_t n;
    do {
        std::cout << "Input n: ";
        std::cin >> n;
    } while (n > boundary);

    return n;
}

void inputArray(int* array, size_t n) {
    for (size_t idx = 0; idx < n; ++idx)
            std::cin >> array[idx];
}

void printSubarray(const int* array, size_t arrSize, size_t startIdx, size_t subSize) { /* Bonus */
    if (startIdx + subSize > arrSize) return;

    std::cout << "[ ";

    for (size_t idx = startIdx; idx < startIdx + subSize; ++idx)
        std::cout << array[idx] << ' ';

    std::cout << ']' << std::endl;
}

void findLongestAscending(const int* array, size_t arrSize, size_t& startIdx, size_t& subSize) {
    if (arrSize == 0) {
        startIdx = 0;
        subSize = 0;
        return;
    }

    size_t currStart = 0;
    size_t currSize = 1;

    startIdx = 0;
    subSize = 1;

    for (size_t idx = 1; idx < arrSize; ++idx) {
        if (array[idx - 1] < array[idx]) {
            ++currSize;
        }
        else {
            if (currSize > subSize) {
                subSize = currSize;
                startIdx = currStart;
            }

            currStart = idx;
            currSize = 1;
        }
    }

    if (currSize > subSize) {
        subSize = currSize;
        startIdx = currStart;
    }
}

int main() {
    size_t size = getValidSize(MAX_N);
    int array[MAX_N];
    inputArray(array, size);
    
    size_t startIdx = 0, subSize = 0;
    findLongestAscending(array, size, startIdx, subSize);
    std::cout << startIdx << ' ' << subSize;

    /* Bonus */
    printSubarray(array, size, startIdx, subSize);
    
    return 0;
}
```

## Задача 5
```cpp
#include <iostream>

const size_t MAX_SYMMOLS = 127;

void histogram(const char* data, size_t size, unsigned values[MAX_SYMMOLS]) {
    for (size_t idx = 0; idx < size; ++idx)
        values[data[idx]] += 1;
}

void printHistogram(const unsigned values[MAX_SYMMOLS]) {
    for (size_t idx = 0; idx < MAX_SYMMOLS; ++idx)
        if (values[idx])
            std::cout << "(\'" << (char) idx << "\', " << values[idx] << ") ";

    std::cout << std::endl;
}

int main() {
    char symbols[] = {
        '?', '?', '=', '#', '!', '&', '#', '@', '#', '^',
        '@', '#', '&', '&', '@', '?', '?', '+', '@', '?',
        '*', '*', '*', '$', '^', '&', '%', '*', '%', '*',
        '#', '?', '&', '!', '@', '?', '$', '&', '%', '#',
        '?', '*', '?', '?', '#', '!', '!', '!', '#', '*',
        '!', '?', '#', '&', '#', '?', '&', '!', '*', '!',
        '*', '#', '#', '!', '^', '#', '^', '?', '=', '*',
        '#', '+', '&', '+', '&', '=', '*', '@', '%', '^',
        '!', '*', '*', '=', '$', '#', '&', '@', '#', '@',
        '%', '#', '#', '*', '*', '*', '+', '#', '#', '^'
    };

    unsigned values[MAX_SYMMOLS] = {};

    histogram(symbols, sizeof(symbols) / sizeof(char), values);

    printHistogram(values);

    return 0;
}
```

## Задача 6
```cpp
#include <iostream>

const size_t MAX_N = 1024;

bool isValidSubmatrix(
    size_t matrixSize, 
    size_t startRow, size_t startCol, size_t subSize
) {
    return startRow + subSize <= matrixSize && startCol + subSize <= matrixSize;
}

int sumFromSubmatrix(
    const int matrix[MAX_N][MAX_N], 
    size_t startRow, size_t startCol, size_t subSize
) {
    // Данните вече са валидирани
    int sum = 0;
    for (size_t row = startRow; row < startRow + subSize; ++row)
        for (size_t col = startCol; col < startCol + subSize; ++col)
            sum += matrix[row][col];

    return sum;
}

int maxSumFromSubmatrix(const int matrix[MAX_N][MAX_N], size_t size) {
    int maxSum = sumFromSubmatrix(matrix, 0, 0, size);
    int currSum;
    for (size_t currSize = 1; currSize < size; ++currSize) {
        for (size_t row = 0; row < size; ++row) {
            for (size_t col = 0; col < size; ++col) {
                if (!isValidSubmatrix(size, row, col, currSize)) 
                    continue;
                
                currSum = sumFromSubmatrix(matrix, row, col, currSize);
                if (currSum > maxSum)
                    maxSum = currSum;
            }
        }
    }

    return maxSum;
}

size_t getValidSize(const size_t& boundary) {
    size_t n;
    do {
        std::cout << "Input n: ";
        std::cin >> n;
    } while (n > boundary);

    return n;
}

void inputMatrix(int matrix[MAX_N][MAX_N], size_t n) {
    for (size_t row = 0; row < n; ++row)
        for (size_t col = 0; col < n; ++col)
            std::cin >> matrix[row][col];
}

int main() {
    size_t size = getValidSize(MAX_N);
    int matrix[MAX_N][MAX_N];
    inputMatrix(matrix, size);

    std::cout << maxSumFromSubmatrix(matrix, size) << std::endl;

    return 0;
}
```

## Задача 7
```cpp
double sum(const double* arr, size_t size) {
    double result = 0;
    for (size_t idx = 0; idx < size; ++idx)
        result += arr[idx];

    return result;
}

double subtract(const double* arr, size_t size) {
    double result = 0;
    for (size_t idx = 0; idx < size; ++idx)
        result -= arr[idx];

    return result;
}

double mul(const double* arr, size_t size) {
    double result = 1;
    for (size_t idx = 0; idx < size; ++idx)
        result *= arr[idx];

    return result;
}

double divide(const double* arr, size_t size) {
    double result = 1;
    for (size_t idx = 0; idx < size; ++idx) {
        if (arr[idx] == 0) {
            std::cout << "Намерена нула на индекс: " << idx << "!" << std::endl;
            std::cout << "Игнориранe!" << std::endl;
            continue;
        }

        result /= arr[idx];
    }

    return result;
}

double calc(const double* arr, size_t size, char operation) {
    switch (operation) {
        case '+': return sum(arr, size);
        case '-': return subtract(arr, size);
        case '*': return mul(arr, size);
        case '/': return divide(arr, size);
        default: 
            std::cout << "Невалидна операция!" << std::endl;
            return 0;
    }
}
```

## Задача 8
```cpp
const size_t N = 10;
const size_t MAX_NEIGHBOURS = 8; // Знаем, че са най-много 8

bool isAliveNow(char cell) {
    /*
    Кодировка:
        'd' -> dead
        'l' -> living
        's' -> soon to die
        'n' -> next to be born
    */

    return cell == 'l' || cell == 's';
}

bool validPosition(int row, int col, size_t matrixSize) {
    return (row >= 0 && row < matrixSize) && (col >= 0 && col < matrixSize);
}

void fillNeighbour(
    char board[N][N],
    size_t boardSize,
    int row, int col, 
    char& neighbour,
    size_t& neighbourIdx
){
    if (!validPosition(row, col, boardSize)) return;

    neighbour = board[row][col];
    ++neighbourIdx;
}

void fillNeighbours(
    char board[N][N],
    size_t boardSize,
    int row, int col, 
    char neighbours[MAX_NEIGHBOURS],
    size_t& neighbourAmount
) {
    size_t idx = 0;
    for (int rowOffset = -1; rowOffset <= 1; ++rowOffset)
        for (int colOffset = -1; colOffset <= 1; ++colOffset)
            if (rowOffset != 0 || colOffset != 0)
                fillNeighbour(
                    board, boardSize, 
                    row + rowOffset, col + colOffset, 
                    neighbours[idx], idx
                );

    neighbourAmount = idx;
}

size_t getLivingNeighboursAmount(char* neighbours, size_t neighbourAmount) {
    size_t aliveAmount = 0;
    for (size_t idx = 0; idx < neighbourAmount; ++idx)
        if (isAliveNow(neighbours[idx]))
            ++aliveAmount;

    return aliveAmount;
}

char getSituations(char currCell, char* neighbours, size_t neighbourAmount) {
    /*
    Кодировка:
        'l' -> lonely
        's' -> surviving
        'c' -> crowdy
        't' -> triving
    */
    
    size_t livingNeighbours = getLivingNeighboursAmount(neighbours, neighbourAmount);

    if (livingNeighbours < 2 && isAliveNow(currCell)) return 'l';
    if (livingNeighbours == 2 && isAliveNow(currCell)) return 's';
    if (livingNeighbours == 3 && isAliveNow(currCell)) return 's';
    if (livingNeighbours > 3 && isAliveNow(currCell)) return 'c';
    if (livingNeighbours == 3 && !isAliveNow(currCell)) return 't';

    return '\0';
}

void markCell(char& cell, char situation) {
    switch (situation) {
        case 'l': cell = 's'; break;
        case 's': cell = 'l'; break;
        case 'c': cell = 's'; break;
        case 't': cell = 'n'; break;
    }
}

void finalizeGeneration(char board[N][N]) {
    for (size_t row = 0; row < N; ++row) {
        for (size_t col = 0; col < N; ++col) {
            if (board[row][col] == 's')
                board[row][col] = 'd';

            else if (board[row][col] == 'n')
                board[row][col] = 'l';
        }
    }
}

void doGenerations(char board[N][N], size_t generations){
    if (generations == 0) return;

    char neighbours[MAX_NEIGHBOURS] = {};
    size_t neighbourAmount = 0;

    for (size_t idx = 0; idx < generations; ++idx) {
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < N; ++col) {
                fillNeighbours(board, N, row, col, neighbours, neighbourAmount);
                markCell(
                    board[row][col],
                    getSituations(
                        board[row][col], 
                        neighbours, neighbourAmount
                    )
                );
            }
        }
        finalizeGeneration(board);
    }
}
```