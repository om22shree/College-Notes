#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prime(int n) {
    int steps = 0;
    int check = 1;
    for (int i = 2; i < n; i++) {
        steps++;
        if(n%i == 0) {
            check = 0;
        }
    }
    if(check) {
        printf("The nnumber is prime\n");
    } else {
        printf("The number is not prime\n");
    }
    return steps;
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("The number of steps required for %d input: %d", n, prime(n));
    return 0;
}