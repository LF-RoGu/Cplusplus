#include <iostream>

void moveNegativesToFront(int arr_count, int* arr)
{
    int* positiveArr = new int[arr_count]();
    int* negativeArr = new int[arr_count]();

    int possitiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < arr_count; i++) {
        if (arr[i] < 0) {
            negativeArr[negativeCount] = arr[i];
            negativeCount++;
        }
        else {
            positiveArr[possitiveCount] = arr[i];
            possitiveCount++;
        }
    }

    for (int i = 0; i < negativeCount; i++) {
        arr[i] = negativeArr[i];
    }
    for (int i = negativeCount; i < arr_count; i++) {
        arr[i] = positiveArr[i];
    }
    // YOUR IMPLEMENTATION HERE
}

bool isValidPartition(const int* arr, int size)
{
    bool seenNonNegative = false;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            seenNonNegative = true;
        }
        else if (seenNonNegative)
        {
            return false;
        }
    }

    return true;
}

void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
}

void runTest(
    const char* testName,
    int* arr,
    int size)
{
    std::cout << "\n-------------------------\n";
    std::cout << testName << '\n';

    std::cout << "Before: ";
    printArray(arr, size);

    moveNegativesToFront(size, arr);

    std::cout << "After:  ";
    printArray(arr, size);

    if (isValidPartition(arr, size))
    {
        std::cout << "[PASS]\n";
    }
    else
    {
        std::cout << "[FAIL]\n";
    }
}

int main()
{
    int test1[] = {3, -1, 4, -5, 0, 2, -2};

    int test2[] = {-1, -2, -3};

    int test3[] = {1, 2, 3};

    int test4[] = {0, -1, 0, -2, 5};

    int test5[] = {-5, 10, -3, 8, -1, 2};

    runTest(
        "Test 1",
        test1,
        7);

    runTest(
        "Test 2",
        test2,
        3);

    runTest(
        "Test 3",
        test3,
        3);

    runTest(
        "Test 4",
        test4,
        5);

    runTest(
        "Test 5",
        test5,
        6);

    return 0;
}