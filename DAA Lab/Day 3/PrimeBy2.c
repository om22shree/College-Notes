#include<stdio.h>
#include<stdlib.h>

int prime(int n) {
    int check;
    int steps = 0;
    for (int i = 2; i <= n/2; ++i) {
        steps++;
        if(n%i == 0) {
            check = 0;
            break;
        }
    }
    if(check) {
        printf("The number is prime\n");
    } else {
        printf("The number is not prime\n");
    }
    return steps;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The number of steps for %d input: %d\n", n, prime(n));
    return 0;
}