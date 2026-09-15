#include <iostream>

int firstUnique(int arr_count, const int* arr)
{
    const int* p = arr;
    int firstUnique = 0;

    int monitor = 0;

    for (int i = 0; i < arr_count; i++) {
        firstUnique = 0;
        for (int j = 0; j < arr_count; j++) {
            if (i == j) {
                continue;
            }
            monitor = p[j];
            if (p[i] == p[j]) {
                firstUnique++;
            }
        }
        if (firstUnique == 0) {
            return p[i];
        }
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

    int result = firstUnique(size, arr);

    std::cout << "Result: " << result << '\n';
    std::cout << "Expected: " << expected << '\n';

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
        4, 5, 1, 2, 0, 4, 1, 2
    };

    int test2[] =
    {
        1, 1, 2, 2, 3, 3
    };

    int test3[] =
    {
        7, 3, 7, 4, 3, 5, 4
    };

    int test4[] =
    {
        10
    };

    int test5[] =
    {
        8, 8, 9, 10, 10
    };

    int test6[] =
    {
        1, 2, 3, 1, 2, 3, 4
    };

    runTest(
    "Test 1",
    test1,
    sizeof(test1) / sizeof(test1[0]),
    5
);

    runTest(
        "Test 2",
        test2,
        sizeof(test2) / sizeof(test2[0]),
        -1
    );

    runTest(
        "Test 3",
        test3,
        sizeof(test3) / sizeof(test3[0]),
        5
    );

    runTest(
        "Test 4",
        test4,
        sizeof(test4) / sizeof(test4[0]),
        10
    );

    runTest(
        "Test 5",
        test5,
        sizeof(test5) / sizeof(test5[0]),
        9
    );

    runTest(
        "Test 6",
        test6,
        sizeof(test6) / sizeof(test6[0]),
        4
    );

    return 0;
}