#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randoms(int upper, int count, int *arr){
    int lower = 1;
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
    }
}


int partition(int arr[], int low, int high) {
	int pivot = arr[low];
	int i = low - 1, j = high + 1;
	while (1) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

int partition_r(int arr[], int low, int high) {
	int random = low + rand() % (high - low);
	int temp = arr[random];
	arr[random] = arr[low];
	arr[low] = temp;
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition_r(arr, low, high);
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
    int n = 50;
    int *arr = (int *)malloc(sizeof(int) * n);
    randoms(77, n, arr);
    printf("Before sorting:-\n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array:-\n");
	printArray(arr, n);
	return 0;
}