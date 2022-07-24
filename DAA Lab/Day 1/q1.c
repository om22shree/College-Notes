// Q1 : Find the largest element in a user input array.

#include<stdio.h>
#include<stdlib.h>

int largest(int *arr, int n) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if(arr[i] > ans) {
            ans = arr[i];
        }
    }
    return ans;
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The largest element is: %d", largest(arr, n));
    return 0;
}