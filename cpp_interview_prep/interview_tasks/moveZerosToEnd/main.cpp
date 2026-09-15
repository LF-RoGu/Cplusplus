#include <iostream>

void moveZerosToEnd(int arr_count, int* arr)
{
    int* arrTemp = new int[arr_count]();
    int zerosCounter = 0;
    int temp;

    // copy arr into temp Arr
    for (int i = 0; i < arr_count; i++) {
        if (arr[i] == 0) {
            continue;
        }
        else {
            temp = arr[i];
            arrTemp[zerosCounter] = temp;
            zerosCounter++;
        }
    }

    for (int i = 0; i < arr_count; i++) {
        if (arrTemp[i] != 0) {
            arr[i] = arrTemp[i];
        } else {
            arr[i] = 0;
        }
    }

    delete[] arrTemp;

}

bool arraysEqual(const int* a, const int* b, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
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
    const int* expected)
{
    std::cout << "\n-------------------------\n";
    std::cout << testName << '\n';

    std::cout << "Before: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';

    moveZerosToEnd(size, arr);

    std::cout << "After:  ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';

    std::cout << "Expected: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << expected[i] << " ";
    }

    std::cout << '\n';

    if (arraysEqual(arr, expected, size))
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
    int test1[] = {0, 1, 0, 3, 12};
    int expected1[] = {1, 3, 12, 0, 0};

    int test2[] = {1, 2, 3, 4};
    int expected2[] = {1, 2, 3, 4};

    int test3[] = {0, 0, 0, 1};
    int expected3[] = {1, 0, 0, 0};

    int test4[] = {1, 0, 2, 0, 3, 0};
    int expected4[] = {1, 2, 3, 0, 0, 0};

    int test5[] = {0, 0, 0};
    int expected5[] = {0, 0, 0};

    int test6[] = {-1, 0, -2, 5, 0};
    int expected6[] = {-1, -2, 5, 0, 0};

    runTest(
        "Test 1",
        test1,
        5,
        expected1);

    runTest(
        "Test 2",
        test2,
        4,
        expected2);

    runTest(
        "Test 3",
        test3,
        4,
        expected3);

    runTest(
        "Test 4",
        test4,
        6,
        expected4);

    runTest(
        "Test 5",
        test5,
        3,
        expected5);

    runTest(
        "Test 6",
        test6,
        5,
        expected6);

    return 0;
}