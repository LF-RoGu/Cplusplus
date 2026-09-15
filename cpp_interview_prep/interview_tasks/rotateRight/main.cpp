#include <iostream>

void rotateRight(int arr_count, int* arr, int k)
{
    int rotation = k%arr_count;
    int* tempArr = new int[arr_count];
    int tempVal = 0;

    for (int i = 0; i < arr_count; i++)
    {
        tempArr[i] = arr[i];
    }

    for (int i = 0; i < rotation; i++)
    {
        // Save last element
        int tempVal = tempArr[arr_count - 1];

        // Shift everything one position to the right
        for (int j = arr_count - 1; j > 0; j--)
        {
            tempArr[j] = tempArr[j - 1];
        }

        // Last value becomes first
        tempArr[0] = tempVal;
    }

    for (int i = 0; i < arr_count; i++)
    {
        arr[i] = tempArr[i];
    }
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
    int k,
    const int* expected)
{
    std::cout << "\n-------------------------\n";
    std::cout << testName << '\n';

    std::cout << "Before: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nRotate by: "
              << k
              << '\n';

    rotateRight(size, arr, k);

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
    int test1[] = {1, 2, 3, 4, 5};
    int expected1[] = {4, 5, 1, 2, 3};

    int test2[] = {10, 20, 30, 40};
    int expected2[] = {40, 10, 20, 30};

    int test3[] = {1, 2, 3};
    int expected3[] = {1, 2, 3};

    int test4[] = {7, 8, 9, 10, 11};
    int expected4[] = {9, 10, 11, 7, 8};

    int test5[] = {5};
    int expected5[] = {5};

    runTest(
        "Test 1",
        test1,
        5,
        2,
        expected1);

    runTest(
        "Test 2",
        test2,
        4,
        1,
        expected2);

    runTest(
        "Test 3",
        test3,
        3,
        3,
        expected3);

    runTest(
        "Test 4",
        test4,
        5,
        8,
        expected4);

    runTest(
        "Test 5",
        test5,
        1,
        100,
        expected5);

    return 0;
}