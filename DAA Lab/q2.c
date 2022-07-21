/* Rearrang even odd format:- */

#include<stdio.h>
#include<stdlib.h>

void randoms(int upper, int count, int *arr){
    int lower = 1;
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
    }
}

void evenOdd(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if(arr[i]%2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if(arr[i]%2 == 1) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int n = 10;
    int arr[n];
    randoms(7, 10, arr);
    printf("The array is:-\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nRearranged order is:-\n");
    evenOdd(arr, n);
    printf("\n");
    return 0;
}
