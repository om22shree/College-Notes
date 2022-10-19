/* Q2 : Rearrange a randomly generated array such that the even elements are
followed by the odd elements. */

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

void EvenOdd(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(arr[i]%2 == 1 && arr[j]%2==0) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
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
    EvenOdd(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
