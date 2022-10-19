// Q2 : Search for an element in a user input array

#include<stdio.h>
#include<stdlib.h>

int search(int *arr, int n, int x) {
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if(arr[i] == x) {
            ans = i;
            exit;
        }
    }
    return ans;
}

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);
    int ans = search(arr, n, x);
    
    if(ans >= 0) {
        printf("The element was found at index %d", ans);
    } else {
        printf("The element is not in the array.");
    }

    return 0;
}
