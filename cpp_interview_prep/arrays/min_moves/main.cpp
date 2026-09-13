#include <iostream>

int minMoves(int arr_count, const int* arr);

struct TestCase
{
    const int* arr;
    int size;
    const char* name;
};

int main()
{
    // Different-sized test arrays
    int arr1[] = {1, 1, 1, 1, 0, 1, 0, 1};             // size 8
    int arr2[] = {1, 1, 0, 0};                         // size 4
    int arr3[] = {1, 0, 1, 0, 0, 0};                   // size 6
    int arr4[] = {0, 0, 0, 1, 1};                      // size 5
    int arr5[] = {1, 0, 1};                            // size 3
    int arr6[] = {0};                                  // size 1
    int arr7[] = {1, 0};                               // size 2
    int arr8[] = {1, 1, 0, 1, 0, 0, 1, 0, 1, 0};     // size 10

    TestCase tests[] =
    {
        {arr1, sizeof(arr1) / sizeof(arr1[0]), "Test 1"},
        {arr2, sizeof(arr2) / sizeof(arr2[0]), "Test 2"},
        {arr3, sizeof(arr3) / sizeof(arr3[0]), "Test 3"},
        {arr4, sizeof(arr4) / sizeof(arr4[0]), "Test 4"},
        {arr5, sizeof(arr5) / sizeof(arr5[0]), "Test 5"},
        {arr6, sizeof(arr6) / sizeof(arr6[0]), "Test 6"},
        {arr7, sizeof(arr7) / sizeof(arr7[0]), "Test 7"},
        {arr8, sizeof(arr8) / sizeof(arr8[0]), "Test 8"}
    };

    int testCount = sizeof(tests) / sizeof(tests[0]);

    for (int test = 0; test < testCount; test++)
    {
        std::cout << "\n------------------------\n";
        std::cout << tests[test].name << '\n';
        std::cout << "Size: " << tests[test].size << '\n';

        std::cout << "Input: ";

        for (int i = 0; i < tests[test].size; i++)
        {
            std::cout << tests[test].arr[i] << ' ';
        }

        std::cout << '\n';

        int result = minMoves(
            tests[test].size,
            tests[test].arr
        );

        std::cout << "Minimum moves: "
                  << result
                  << '\n';
    }

    return 0;
}