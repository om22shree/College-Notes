#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    swap(&c, &a);
    swap(&a, &b);
    printf("\n%d %d %d\n", a, b, c);
    return 0;
}