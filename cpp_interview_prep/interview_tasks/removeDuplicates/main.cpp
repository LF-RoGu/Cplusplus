#include <iostream>

int removeDuplicates(int arr_count, int* arr)
{
    if (arr_count == 0)
    {
        return 0;
    }

    int writeIndex = 1;

    for (int i = 1; i < arr_count; i++)
    {
        if (arr[i] != arr[writeIndex - 1])
        {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    return writeIndex;
}

bool arraysEqualPrefix(
    const int* arr,
    const int* expected,
    int validCount)
{
    for (int i = 0; i < validCount; i++)
    {
        if (arr[i] != expected[i])
        {
            return false;
        }
    }

    return true;
}

void runTest(
    const char* testName,
    int* arr,
    int size,
    const int* expected,
    int expectedCount)
{
    std::cout << "\n-------------------------\n";
    std::cout << testName << '\n';

    std::cout << "Before: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';

    int resultCount = removeDuplicates(size, arr);

    std::cout << "After:  ";

    for (int i = 0; i < resultCount; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';

    std::cout << "Expected count: "
              << expectedCount
              << '\n';

    std::cout << "Result count:   "
              << resultCount
              << '\n';

    bool valuesCorrect =
        arraysEqualPrefix(
            arr,
            expected,
            expectedCount);

    if (resultCount == expectedCount &&
        valuesCorrect)
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
    int test1[] = {1, 1, 2, 2, 3, 4, 4};
    int expected1[] = {1, 2, 3, 4};

    int test2[] = {5, 5, 5, 5};
    int expected2[] = {5};

    int test3[] = {1, 2, 3, 4};
    int expected3[] = {1, 2, 3, 4};

    int test4[] = {-3, -3, -1, -1, 0, 2, 2};
    int expected4[] = {-3, -1, 0, 2};

    int test5[] = {10};
    int expected5[] = {10};

    runTest(
        "Test 1",
        test1,
        7,
        expected1,
        4);

    runTest(
        "Test 2",
        test2,
        4,
        expected2,
        1);

    runTest(
        "Test 3",
        test3,
        4,
        expected3,
        4);

    runTest(
        "Test 4",
        test4,
        7,
        expected4,
        4);

    runTest(
        "Test 5",
        test5,
        1,
        expected5,
        1);

    return 0;
}