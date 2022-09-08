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

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j) {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j) {
            // Swap arr[i], arr[j];
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[low], arr[j];
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    int n = 50;
    int *arr = (int*)malloc(sizeof(int) * n);
    randoms(77, n, arr);
    printf("Before Sort:-\n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("After Sort:-\n");
    printArray(arr, n);
    return 0;
}