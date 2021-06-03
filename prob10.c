// Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.

// Asked by Apple

#include<stdio.h>
#include<Windows.h>
int main(){
    int n;
    printf("Enter sleep time in ms:\n");
    scanf("%d",&n);
    Sleep(n);
    printf("Function is called after %d millisec",n);  // 1 sec = 1000 ms
    return 0;
}
