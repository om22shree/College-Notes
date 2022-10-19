#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prime(int n) {
    int check = 1;
    int steps = 0;
    for (int i = 2; i < sqrt(n); i++) {
        steps++;
        if(n%i == 0) {
            check = 0;
            break;
        }
    }
    if(check) {
        printf("The number is prime");
    } else {
        printf("The number is not prime");
    }
    return steps;
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("\nThe number of steps for %d input: %d", n, prime(n));
    return 0;
}