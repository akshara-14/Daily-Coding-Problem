/* Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
You can modify the input array in-place. */

// Asked by Stripe

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Utility function that puts all non-positive (0 and negative) numbers on left side of arr[] and return count of such numbers */
int segregate(int arr[], int size)
{
    int j = 0, i;
    for (i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            swap(&arr[i], &arr[j]);
            j++; // increment count of non-positive integers
        }
    }
 
    return j;
}

int findMissingPositive(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)  // abs() returns absolute value of an integer. The absolute value of a number is always positive.
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
 
    // Return the first index value at which is positive
    for (i = 0; i < size; i++)
        if (arr[i] > 0)
            // 1 is added because indexes start from 0
            return i + 1;
 
    return size + 1;
}

int findMissing(int arr[], int size)
{
    // First separate positive and negative numbers
    int shift = segregate(arr, size);
 
    return findMissingPositive(arr + shift, size - shift);
}

int main()
{
    int n, arr[n];
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d of the array: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int missing = findMissing(arr, n);
    printf("The smallest positive missing number is %d ", missing);
    // getchar();
    return 0;
}