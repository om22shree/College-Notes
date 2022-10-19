#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
	*a = *b;
    *b = temp;
}
  
void randoms(int upper, int count, int *arr){
    int lower = 1;
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
    }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      	swap(&arr[i], &arr[largest]);
    	heapify(arr, n, largest);
    }
}
  
void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
    	heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
      	swap(&arr[0], &arr[i]);
      	heapify(arr, i, 0);
    }
}
  
void printArray(int *arr, int n) {
    for (int i = 0; i < n; ++i)
    	printf("%d ", arr[i]);
    printf("\n");
}
  
int main() {
	for (int n = 50; n <= 500; n+=50) {
		int arr[n];
		printf("For n = %d:-\nBefore sorting:-\n", n);
		randoms(50, n, arr);
		printArray(arr, n);
		heapSort(arr, n);
    	printf("After sorting:-\n");
    	printArray(arr, n);
		printf("\n\n");
	}
	return 0;
}