#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int flag=0, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
        for (int i = 0; i < n-1; i++)
        {
            if ((arr[i + 1] > arr[i]) && flag == 0) {
                ans = arr[i + 1];
                flag++;
            }
        }

        for (int i = 0; i < n; i)
            printf("%d ", ans);
        return 0;
}

/*
10 20 30 40 50 
20 30 66 40 60
*/