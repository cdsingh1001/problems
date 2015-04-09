#include "stdio.h"

/* Iterative Binary Search */
int binary_search_i (int arr[], int len, int x)
{
    int lower, upper, middle;
    int index = -1;

    lower = 0;
    upper = len-1;

    while (lower <= upper) {
        middle = (lower+upper)/2;
        if (x < arr[middle]) {
            upper = middle-1;
        } else if (x == arr[middle]) {
            index = middle;
            break;
        } else {
            lower = middle+1;
        }
    }

    return index;
}

/* Recursive Binary Search */
int binary_search_r (int arr[], int lower, int upper, int x)
{
    int middle;
    int index = -1;

    middle = (lower+upper)/2;

    if (upper < lower) {
        return -1;
    }

    if (x == arr[middle]) {
        return middle;
    }

    if (x < arr[middle]) {
        index = binary_search_r (arr, 0, middle-1 , x);
    } else {
        index = binary_search_r (arr, middle+1, upper, x);
    }

    return index;
}

