/* Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
Follow-up: what if you can't use division? */

// Asked by Uber

#include<stdio.h>
#include<stdlib.h>
void productArray(int arr[], int n)
{
 
    if (n == 1) {
        printf("0");
        return;
    }
 
    int* left = (int*)malloc(sizeof(int) * n);
    int* right = (int*)malloc(sizeof(int) * n);
 
    int* prod = (int*)malloc(sizeof(int) * n);
 
    int i, j;

    left[0] = 1;
    right[n - 1] = 1;
 
    for (i = 1; i < n; i++)
        left[i] = arr[i - 1] * left[i - 1];
 
    for (j = n - 2; j >= 0; j--)
        right[j] = arr[j + 1] * right[j + 1];
 
    for (i = 0; i < n; i++)
        prod[i] = left[i] * right[i];
 
    for (i = 0; i < n; i++)
        printf("%d ", prod[i]);
 
    return;
}
 
int main()
{
    int m, arr[m];
    printf("Enter size of array: ");
    scanf("%d",&m);

    for (int i = 0; i < m; i++)
    {
        printf("Enter element %d of the array: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The product array is: \n");
    productArray(arr, m);
    getchar();
}