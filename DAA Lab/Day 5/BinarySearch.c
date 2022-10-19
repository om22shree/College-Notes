#include <stdio.h>
#include <stdlib.h>
#define upper 999
#define lower 60

void merge(int *arr, int startIndex, int endIndex) {
    int midIndex = (startIndex+endIndex)/2;
    int *temp = (int*)(malloc(sizeof(int) * (endIndex-startIndex+1)));
    int i = startIndex, j = midIndex+1, k = 0;
    
    while(i <= midIndex && j <= endIndex) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= midIndex) {
        temp[k++] = arr[i++];
    }

    while(j <= endIndex) {
        temp[k++] = arr[j++];
    }
    
    k = 0;
    while(startIndex <= endIndex) {
        arr[startIndex++] = temp[k++];
    }

    free(temp);
}

void sort(int *arr, int startIndex, int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int midIndex = (startIndex+endIndex)/2;
    sort(arr, startIndex, midIndex);
    sort(arr, midIndex+1, endIndex);
    merge(arr, startIndex, endIndex);
}

int binarySearch(int *arr, int startIndex, int endIndex, int target, int *stepCounter) {
    if(endIndex < startIndex) {
        return 0;
    }
    int mid = (startIndex+endIndex)/2;
    (*stepCounter)++;
    if(target == arr[mid]) {
        return 1;
    } else if(target < arr[mid]) {
        return binarySearch(arr, startIndex, mid-1, target, stepCounter);
    } else {
        return binarySearch(arr, mid+1, endIndex, target, stepCounter);
    }
}

int main() {
    printf("Sl.No.\tn\tSteps\n");
    int slno = 1;
    for(int n = 5000; n <= 50000; n += 5000) {
        int *arr = (int*)(malloc)(sizeof(int) * n);
        for(int i = 0; i < n; i++) {
            arr[i] = (rand()%(upper-lower+1))+lower;
        }
        sort(arr, 0, n);
        int x = (rand()%(upper-lower+1))+lower;
        int stepCounter = 0;
        int found = binarySearch(arr, 0, n-1, x, &stepCounter);
        int best, worst, average;
        average = stepCounter;
        stepCounter = 0;
        x = arr[n / 2];
        found = binarySearch(arr, 0, n - 1, x, &stepCounter);
        best = stepCounter;
        x = arr[n-1];
        found = binarySearch(arr, 0, n - 1, x, &stepCounter);
        worst = stepCounter;
        printf("%d\t%d\t%d\t%d\t%d\t\n", slno++, n, best, average, worst);
    }
    return 0;
}