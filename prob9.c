// Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
// For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
// Follow-up: Can you do this in O(N) time and constant space?

// Asked by Airbnb

#include <stdio.h>

int FindMaxSum(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
        /* current max excluding i */
        excl_new = (incl > excl) ? incl : excl;

        /* current max including i */
        incl = excl + arr[i];
        excl = excl_new;
    }

    /* return max of incl and excl */
    return ((incl > excl) ? incl : excl);
}

int main()
{
    int x;
    printf("Enter size of array: ");
    scanf("%d", &x);
    int arr[x];
    printf("Enter elements of array:\n");

    for (int i = 0; i < x; i++)
    {
        scanf("%d", &arr[i]);
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", FindMaxSum(arr, n));
    return 0;
}