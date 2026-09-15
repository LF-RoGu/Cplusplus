#include <iostream>

int longestRun(int arr_count, const int* arr)
{
    if (arr_count == 0)
    {
        return 0;
    }

    int currentRun = 1;
    int longestRun = 1;

    for (int i = 1; i < arr_count; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            currentRun++;
        }
        else
        {
            currentRun = 1;
        }

        if (currentRun > longestRun)
        {
            longestRun = currentRun;
        }
    }

    return longestRun;
}

void runTest(
    const char* testName,
    const int* arr,
    int size,
    int expected)
{
    std::cout << "\n-------------------------\n";
    std::cout << testName << '\n';

    std::cout << "Input: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';

    int result = longestRun(size, arr);

    std::cout << "Expected: " << expected << '\n';
    std::cout << "Result:   " << result << '\n';

    if (result == expected)
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
    int test1[] = {1, 1, 2, 2, 2, 3, 3};

    int test2[] = {5, 5, 5, 5};

    int test3[] = {1, 2, 3, 4};

    int test4[] = {7, 7, 2, 2, 2, 2, 9};

    int test5[] = {-1, -1, -1, 2, 2, -3};

    int test6[] = {10};

    runTest(
        "Test 1",
        test1,
        7,
        3);

    runTest(
        "Test 2",
        test2,
        4,
        4);

    runTest(
        "Test 3",
        test3,
        4,
        1);

    runTest(
        "Test 4",
        test4,
        7,
        4);

    runTest(
        "Test 5",
        test5,
        6,
        3);

    runTest(
        "Test 6",
        test6,
        1,
        1);

    return 0;
}