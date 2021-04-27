/* cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
Given this implementation of cons:
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr. */

// Asked by Jane Street

#include <stdio.h>
#include <stdlib.h>

void cons(int a, int b)
{
    int car = a;
    printf("%d\n",car);
    int cdr = b;
    printf("%d",cdr);
}

int main()
{
    cons(3,4);
    return 0;
}