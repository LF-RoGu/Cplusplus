#include <cstdio>
//
// Created by Luis on 13/09/2026.
//

#define DEBUG 0

void printArray(const int* arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int minMoves(int arr_count, const int* arr)
{
    // Your implementation here
    int* tempArr = new int[arr_count];
    for (int i = 0; i < arr_count; i++)
    {
        tempArr[i] = arr[i];
    }

    int balance = 0;
    int moves = 0;

    bool change = false;

    int temp = 0;

    // Here by only checking half of the array we know if we put 1 or 0 first on the checking list
    for (int i = 0; i < arr_count/2; i++) {
        if (arr[i] == 1) {
            balance++;
        }
        else {
            balance--;
        }
    }

    // Possitive result (More 1's)
    if (balance > 0) {
        change = true;
        while (change == true) {
            change = false;
            for (int i = 0; i < arr_count - 1; i++) {
                if ((tempArr[i] == 0) && (tempArr[i+1] == 1)) {

#if DEBUG
                    printf("Before %d:\n", moves + 1);
                    printArray(tempArr, arr_count);
#endif
                    temp = tempArr[i];
                    tempArr[i] = tempArr[i+1];
                    tempArr[i+1] = temp;

                    moves++;
#if DEBUG
                    printf("After %d:\n", moves + 1);
                    printArray(tempArr, arr_count);
#endif
                    change = true;
                    break;
                }
            }
        }
    }
    // Negative result (More 0's)
    else if (balance < 0) {
        change = true;
        while (change == true) {
            change = false;

            for (int i = 0; i < arr_count - 1; i++) {
                if ((tempArr[i] == 1) && (tempArr[i+1] == 0)) {
#if DEBUG
                    printf("Before %d:\n", moves + 1);
                    printArray(tempArr, arr_count);
#endif
                    temp = tempArr[i];
                    tempArr[i] = tempArr[i+1];
                    tempArr[i+1] = temp;

                    moves++;
#if DEBUG
                    printf("After %d:\n", moves + 1);
                    printArray(tempArr, arr_count);
#endif
                    change = true;
                    break;
                }
            }
        }
    }
    else {
        moves = 0;
    }
    delete[] tempArr;
    return moves;
}