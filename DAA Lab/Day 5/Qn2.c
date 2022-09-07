#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define upper 999
#define lower 60

void mergeAscending(int *arr, int startIndex, int endIndex) {
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

void merSortAscending(int *arr, int startIndex, int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int midIndex = (startIndex+endIndex)/2;
    merSortAscending(arr, startIndex, midIndex);
    merSortAscending(arr, midIndex+1, endIndex);
    mergeAscending(arr, startIndex, endIndex);
}

void mergeDescending(int *arr, int startIndex, int endIndex) {
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

void mergeSortDescending(int *arr, int startIndex, int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int midIndex = (startIndex+endIndex)/2;
    mergeSortDescending(arr, startIndex, midIndex);
    mergeSortDescending(arr, midIndex+1, endIndex);
    mergeDescending(arr, startIndex, endIndex);
}

int main() {
    printf("Sl.No.\tn\tRandom Data\tData in Ascending\tData in Descending\n");
    int slno = 1;
    for(int n = 50000; n <= 500000; n += 50000) {
        int *arr = (int*)(malloc)(sizeof(int) * n);
        int *arrAscending = (int*)(malloc)(sizeof(int) * n);
        int *arrDescending = (int*)(malloc)(sizeof(int) * n);

        for(int i = 0; i < n; i++) {
            arr[i] = (rand()%(upper-lower+1))+lower;
            arrAscending[i] = arr[i];
            arrDescending[i] = arr[i];
        }
        
        merSortAscending(arrAscending, 0, n-1);
        mergeSortDescending(arrDescending, 0, n-1);

        clock_t t = clock();
        merSortAscending(arr, 0, n-1);
        t = clock()-t;
        double randomTime = ((double)t/CLOCKS_PER_SEC);

        t = clock();
        merSortAscending(arrAscending, 0, n-1);
        t = clock()-t;
        double ascendingTime = ((double)t/CLOCKS_PER_SEC);

        t = clock();
        merSortAscending(arrDescending, 0, n-1);
        t = clock()-t;
        double descendingTime = ((double)t/CLOCKS_PER_SEC);
        printf("%d\t%d\t%lf\t%lf\t\t%lf\n", slno++, n, randomTime, ascendingTime, descendingTime);
    }
    
    return 0;
}