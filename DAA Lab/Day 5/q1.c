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

void sort(int* arr, int n) {
    // reusing lab 4's insertion sort.
    int i, j, key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int *arr, int l, int r, int x) {
    int start, end;
    start = clock();
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    end = clock();
    double time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken: %f", time);
    return -1;
}

int main() {
    int n, x, sol;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nArray:-\n");
    randoms(100, n, arr);
    printArray(arr, n);
    printf("Enter the element to be found: ");
    scanf("%d", &x);
    sort(arr, n);
    printf("Sorted array:-\n");
    printArray(arr, n);
    sol = binarySearch(arr, 0, n, x);
    if (sol != -1) {
        printf("\nElement was first found at index: %d\n", sol);
    }
    else {
        printf("\nElement was not found\n");
    }

    return 0;
}