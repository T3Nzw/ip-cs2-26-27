# Седмица 5 - Примерни решения

## Помощни функции
```cpp
void swap(int& lhsElement, int& rhsElement) {
    int temp = lhsElement;
    lhsElement = rhsElement;
    rhsElement = temp;
}

void printArray(int arr[], size_t size) {
    for (size_t idx = 0; idx < size; ++idx)
        std::cout << arr[idx] << ' ';
    
    std::cout << std::endl;
}

const size_t N = 5; // За матрица ни трябва да знаем размера на колоните
void printMatrix(int matrix[][N]) {
    for (size_t idx = 0; idx < N; ++idx)
        printArray(matrix[idx], N);
}
```

## Задача 1
```cpp
#include <iostream>

const size_t LIST_MAX_SIZE = 1024;

int main(){
    int nums[LIST_MAX_SIZE];
    size_t size;
    std::cin >> size;

    if (size > LIST_MAX_SIZE) {
        std::cout << "Невалиден размер!" << std::endl;

        return 0;
    }

    for (size_t idx = 0; idx < size; ++idx)
        std::cin >> nums[idx];

    for (size_t idx = 0; idx < size; idx += 2)
        std::cout << nums[idx] << ' ';

    std::cout << std::endl;

    return 0;
}
```

## Задача 2
```cpp
int max(int arr[], size_t size) {
    int maxElement = arr[0];

    for (size_t idx = 1; idx < size; ++idx)
        if (arr[idx] > maxElement)
            maxElement = arr[idx];

    return maxElement;
}

size_t min(int arr[], size_t size) {
    size_t minIdx = 0;

    for (size_t idx = 1; idx < size; ++idx)
        if (arr[idx] < arr[minIdx])
            minIdx = idx;

    return minIdx;
}
```

## Задача 3
```cpp
void reverse(int arr[], size_t size) {
    for (size_t idx = 0; idx < size / 2; ++idx)
        swap(arr[idx], arr[size - 1 - idx]);
}
```

## Задача 4
```cpp
int sumPrimary = 0;
for (size_t idx = 0; idx < N; ++idx)
    sumPrimary += nums[idx][idx];

int sumSecondary = 0;
for (size_t idx = 0; idx < N; ++idx)
    sumSecondary += nums[idx][N - 1 - idx];

std::cout << sumPrimary << ' ' << sumSecondary << std::endl;
```

## Задача 5
```cpp
const size_t N = 5;

void swapRows(int matrix[][N], size_t fRow, size_t sRow) {
    for (size_t idx = 0; idx < N; ++idx)
        swap(matrix[fRow][idx], matrix[sRow][idx]);
}

void swapCols(int matrix[][N], size_t fCol, size_t sCol) {
    for (size_t idx = 0; idx < N; ++idx)
        swap(matrix[idx][fCol], matrix[idx][sCol]);
}
```

## Задача 6
```cpp
void revSort(int* arr, size_t size) {
    //Използваме алгоритъмa Insertion sort
    /* 
    Знака на value > arr [jdx - 1] определя реда:
        value > arr [jdx - 1] - низходящ ред
        value < arr [jdx - 1] - възходящ ред 
    */
    int value, jdx;
    for (size_t idx = 1; idx < size; ++idx) {
        value = arr[idx];
        jdx = idx;

        while(jdx > 0 && value > arr [jdx - 1]) {
            arr[jdx] = arr[jdx - 1];
            --jdx;
        }

        arr[jdx] = value;
    }
}

void printThreeLargest(int arr[], size_t size) {
    revSort(arr, size);
    for (unsigned short idx = 3; idx > 0; --idx)
        std::cout << arr[idx - 1] << ' ';

    std::cout << std::endl;
}
```

## Задача 7
```cpp
const size_t N = 5;
void transpose(int matrix[][N]) {
    for (size_t idx = 0; idx < N; ++idx)
        for (size_t jdx = idx; jdx < N; ++jdx)
            swap(matrix[idx][jdx], matrix[jdx][idx]);
}
```

## Задача 8
```cpp
const size_t N = 5;
const size_t M = 6;
void printColsReverse(int matrix[N][M]) {
    for (size_t idx = N; idx > 0; --idx) {
        for (size_t jdx = 0; jdx < M; ++jdx)
            std::cout << matrix[idx - 1][jdx] << ' ';

        std::cout << std::endl;
    }
}
```

## Задача 9
```cpp
const size_t N = 5;
const size_t M = 6;
void printSnake(int matrix[N][M], char symbol) {
    if (symbol == 'l' || symbol == 'r') {
        for (size_t row = 0; row < N; ++row) {
            if (symbol == 'l')
                for (size_t col = 0; col < M; ++col)
                    std::cout << matrix[row][col] << ' ';
            if (symbol == 'r')
                for (size_t col = M; col > 0; --col)
                        std::cout << matrix[row][col - 1] << ' ';

            symbol = symbol == 'r' ? 'l' : 'r';
            std::cout << std::endl;
        }
    }

    if (symbol == 'd' || symbol == 'u') {
        for (size_t col = 0; col < M; ++col) {
            if (symbol == 'd')
                for (size_t row = 0; row < N; ++row)
                    std::cout << matrix[row][col] << ' ';
            if (symbol == 'u')
                for (size_t row = N; row > 0; --row)
                        std::cout << matrix[row - 1][col] << ' ';

            symbol = symbol == 'u' ? 'd' : 'u';
            std::cout << std::endl;
        }
    }
}
```

## Задача 10
```cpp
void sort(int arr[], size_t size) {
    // Използваме алгоритъм Bubble Sort
    for (size_t idx = 0; idx < size; ++idx)
        for (size_t jdx = 0; jdx < size - 1; ++jdx)
            if (arr[jdx] > arr[jdx + 1])
                swap(arr[jdx], arr[jdx + 1]);
}

int mode(int arr[], size_t size) {
    if (size == 0 || arr == nullptr) {
        std::cout << "Празен масив!";

        return 0;
    }

    sort(arr, size);
    size_t modeIdx = 0, currIdx = 0;
    unsigned modeCount = 0, currCount = 0;

    for (size_t idx = 0; idx < size; ++idx) {
        if (arr[idx] == arr[currIdx]) {
            ++currCount;
        } else {
            currIdx = idx;
            currCount = 1;
        }

        if (modeCount < currCount) {
            modeCount = currCount;
            modeIdx = currIdx;
        }
    }

    return arr[modeIdx];
}
```

## Задача 11
```cpp
const size_t N = 5;
void sumMatrix(int lhs[][N], int rhs[][N], int result[][N]) {
    for (size_t idx = 0; idx < N; ++idx)
        for (size_t jdx = 0; jdx < N; ++jdx)
            result[idx][jdx] = lhs[idx][jdx] + rhs[idx][jdx];
}
```

## Задача 12
```cpp
const size_t N = 5;
void mulMatrix(int lhs[][N], int rhs[][N], int result[][N]) {
    int currSum = 0;
    for (size_t idx = 0; idx < N; ++idx)
        for (size_t jdx = 0; jdx < N; ++jdx) {
            currSum = 0;
            for (size_t kdx = 0; kdx < N; ++kdx)
                currSum += lhs[idx][kdx] * rhs[kdx][jdx];

            result[idx][jdx] = currSum;
        }     
}
```

## Задача 13
```cpp
void rotate(int arr[], size_t size, int rotations) {
    if (size == 0) return;

    bool backwards = rotations < 0;
    unsigned absRotations = backwards ? -rotations : rotations;
    unsigned meaningfullRoations = absRotations % size;
    
    for (unsigned rotation = 0; rotation < meaningfullRoations; ++rotation) {
        for (size_t idx = 1; idx < size; ++idx) {
            if (backwards)
                swap(arr[idx - 1], arr[idx]);
            else
                swap(arr[size - idx], arr[size - idx - 1]);
        }
    }
}
```

## Задача 14
```cpp
const size_t N = 5;
int sumCol(int matrix[][N], size_t col) {
    int sum = 0;
    for (size_t idx = 0; idx < N; ++idx)
        sum += matrix[idx][col];

    return sum;
}

void sortColsBySum(int matrix[][N]) {
    int sumArray[N] = {};
    
    for (size_t idx = 0; idx < N; ++idx)
        sumArray[idx] = sumCol(matrix, idx);

    for (size_t idx = 0; idx < N; ++idx)
        for (size_t jdx = 0; jdx < N - 1 - idx; ++jdx)
            if (sumArray[jdx] > sumArray[jdx + 1]) {
                swap(sumArray[jdx], sumArray[jdx + 1]);
                swapCols(matrix, jdx, jdx + 1);
            }
}
```

## Задача 15
```cpp
#include <iostream>

const size_t LIST_MAX_SIZE = 1024;
const size_t RESULT_LIST_MAX_SIZE = LIST_MAX_SIZE * 2;

void swap(int& lhsElement, int& rhsElement) {
    int temp = lhsElement;
    lhsElement = rhsElement;
    rhsElement = temp;
}

void mergeSortedArrays(int lhsArr[], int rhsArr[], int resultArr[], size_t lhsSize, size_t rhsSize) {
    size_t lhsIdx = 0, rhsIdx = 0, resultIdx = 0;

    while (lhsIdx < lhsSize && rhsIdx < rhsSize ) {
        if (lhsArr[lhsIdx] < rhsArr[rhsIdx]) {
            resultArr[resultIdx] = lhsArr[lhsIdx];
            ++lhsIdx;
        } else {
            resultArr[resultIdx] = rhsArr[rhsIdx];
            ++rhsIdx;
        }
        
        ++resultIdx;
    }

    while (lhsIdx < lhsSize) {
        resultArr[resultIdx] = lhsArr[lhsIdx];
        ++lhsIdx;
        ++resultIdx;
    }

    while (rhsIdx < rhsSize) {
        resultArr[resultIdx] = rhsArr[rhsIdx];
        ++rhsIdx;
        ++resultIdx;
    }
}

size_t input(int arr[]) {
    size_t size;
    do {
        std::cout << "Въведете дължината на масива: ";
        std::cin >> size;
    } while (size > LIST_MAX_SIZE);

    for (size_t idx = 0; idx < size; ++idx)
        std::cin >> arr[idx];

    return size;
}

int main(){
    int lhs[LIST_MAX_SIZE], rhs[LIST_MAX_SIZE];
    size_t lhsSize = input(lhs);
    size_t rhsSize = input(rhs);
    size_t resultsSize = lhsSize + rhsSize;
    int result[RESULT_LIST_MAX_SIZE];
    mergeSortedArrays(lhs, rhs, result, lhsSize, rhsSize);

    printArray(result, resultsSize);

    return 0;
}
```