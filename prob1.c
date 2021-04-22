/* Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass? */

// Asked by Google

#include <stdio.h>
int main()
{
    int k, n, arr[n], x = 0;

    printf("Enter the number k: ");
    scanf("%d", &k);

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d of the list of numbers: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int j = k - arr[i];
        for (int m = i + 1; m < n; m++)
        {
            if (j == arr[m])
            {
                printf("Yes");
                x = 1;
            }
        }
    }

    if (x == 0)
    {
        printf("No");
    }

    return 0;
}