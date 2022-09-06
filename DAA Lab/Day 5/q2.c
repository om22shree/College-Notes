#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void randoms(int upper, int count, int *arr){
    int lower = 1;
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
    }
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int n;
    int *arr;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    randoms(100, n, arr);
    printf("Printing the array:-\n");
    printArray(arr, n);
    

    return 0;
}