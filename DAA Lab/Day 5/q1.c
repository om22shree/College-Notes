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
    
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main() {
    printf("The complexity table:-\n");
    printf("N value\t Worst time\t Average time\t Best time\n");

    for (int i = 5001; i <= 50001; i+=5000) {
        int n, x, sol;
        double wt, bt, at;
        n = i;
        int arr[n];
        randoms(10000, n, arr);
        sort(arr, n);
        
        // Best case :-
        x = arr[n / 2];
        int start = clock();
        sol = binarySearch(arr, 0, n, x);
        int end = clock();
        double time = (double)(end - start)/CLOCKS_PER_SEC;
        bt = time;

        // Average case :-
        x = arr[n / 2 + n / 4 + n / 8];
        int start = clock();
        sol = binarySearch(arr, 0, n, x);
        int end = clock();
        double time = (double)(end - start)/CLOCKS_PER_SEC;
        at = time;

        // Worst case :-
        x = arr[n - 1] + 1000;
        int start = clock();
        sol = binarySearch(arr, 0, n, x);
        int end = clock();
        double time = (double)(end - start)/CLOCKS_PER_SEC;
        wt = time;

        printf("%d\t %ld/t %ld\t %ld\n", n, bt, at, wt);
    }

    return 0;
}