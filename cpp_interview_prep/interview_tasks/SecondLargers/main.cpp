#include <iostream>

int secondLargest(int arr_count, const int* arr)
{
    int currentLargest = 0;
    int previousLargest = 0;

    int target = 0;

    if (arr_count > 2) {
        for (int i = 0; i < arr_count - 1; i++) {
            currentLargest = arr[i+1];
            previousLargest = arr[i];

            if (currentLargest > previousLargest) {
                target = currentLargest;
            }
        }

        if (target > currentLargest) {
            return target;
        }
    }
    else {
        return -1;
    }
    return -1;
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

    int result = secondLargest(size, arr);

    std::cout << "Expected: "
              << expected
              << '\n';

    std::cout << "Result:   "
              << result
              << '\n';

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
    int test1[] =
    {
        4, 1, 9, 7, 9, 3
    };

    int test2[] =
    {
        5, 5, 5
    };

    int test3[] =
    {
        10, 8
    };

    int test4[] =
    {
        3, 2, 3, 1, 2
    };

    int test5[] =
    {
        -5, -1, -3, -1
    };

    int test6[] =
    {
        100
    };

    runTest(
        "Test 1",
        test1,
        sizeof(test1) / sizeof(test1[0]),
        7);

    runTest(
        "Test 2",
        test2,
        sizeof(test2) / sizeof(test2[0]),
        -1);

    runTest(
        "Test 3",
        test3,
        sizeof(test3) / sizeof(test3[0]),
        8);

    runTest(
        "Test 4",
        test4,
        sizeof(test4) / sizeof(test4[0]),
        2);

    runTest(
        "Test 5",
        test5,
        sizeof(test5) / sizeof(test5[0]),
        -3);

    runTest(
        "Test 6",
        test6,
        sizeof(test6) / sizeof(test6[0]),
        -1);

    return 0;
}