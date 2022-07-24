#include<stdio.h>

void swap(int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

int main () {
    int a = 10, b = 20;
    printf("Before Swap: %d %d\n", a, b);
    swap(&a, &b);
    printf("After Swap: %d %d\n", a, b);
    return 0;
}