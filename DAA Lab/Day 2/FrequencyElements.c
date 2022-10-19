/* Q1 : Find the frequency of elements in a randomly generated array which contains
 some duplicate elements. */ 

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

int MaxFrequency(int *array, int n)  {
    int i, j, maxElement, count;
    int maxCount = 0;
    for (i = 0; i < n; i++){
        count = 1;
        for(j = i+1; j < n; j++) {
            if(array[j] == array[i]) {
                count++;
                if(count > maxCount) {
                    maxElement = array[j];
                    maxCount = count;
                }
            }
        }
    }
    return maxElement;
}

int duplicates(int *arr, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n = 10;
    int arr[n];
    randoms(8, n, arr);
    printf("The array is:-\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Number of duplications are:-\n%d \n", duplicates(arr, n));
    printf("Maximum repeating element is %d\n", MaxFrequency(arr, n));
    return 0;
}