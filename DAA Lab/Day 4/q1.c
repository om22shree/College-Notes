#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

clock_t start, end;
double t_time;

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randoms(int upper, int count, int *arr){
    int lower = 1;
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
    }
}

double sort(int *arr, int n) {
    start = clock();
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
    end = clock();
    t_time = (double)(end - start) / CLOCKS_PER_SEC;
    return t_time;
}

double descSort(int *arr, int n) {
    start = clock();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    end = clock();
    t_time = (double)(end - start) / CLOCKS_PER_SEC;
    return t_time;
}

int main() {
    int choice, n;
    double asct, desct;
    int *arr = malloc(sizeof(int) * 10);

    printf("The menu has been shown below:-\n");
    printf("0: Quit\n");
    printf("1: n random numbers => array\n");
    printf("2: Display the array\n");
    printf("3: Sort in ascending order\n");
    printf("4: Sort in descending order\n");
    printf("5: Complexity to sort random data\n");
    printf("6: Complexity to sort ascending order data\n");
    printf("7: Complexity to sort descending order data\n");
    printf("8: Show the tabulation of time complexities\n");
    
    printf("Enter the choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 0: {
            exit;
        }

        case 1: {
            printf("Enter the value of n: ");
            scanf("%d", &n);
            arr = realloc(arr, sizeof(int)*n);
            randoms(200, n, arr);
            printf("\nEnter the next choice: ");
            scanf("%d", &choice);
        }

        case 2: {
            printf("\nDisplaying the array:-\n");
            display(arr, n);
            printf("\nEnter the next choice: ");
            scanf("%d", &choice);
        }

        case 3: {
            printf("Sorting in ascending order:-\n");
            asct = sort(arr, n);
            display(arr, n);
            printf("\nEnter the next choice: ");
            scanf("%d", &choice);
        }

        case 4: {
            printf("Sort in descending order:-\n");
            desct = descSort(arr, n);
            display(arr, n);
            printf("\nEnter the next choice: ");
            scanf("%d", &choice);
        }

        case 5: {
            printf("Time coplexity to sort ascending of random data:-\n");
            printf("%lf", asct);
            printf("\nEnter the next choice: ");
            scanf("%d", &choice);
        }

        case 6: {
            asct = sort(arr, n);
            asct = sort(arr, n);
            printf("Time complexity to sort ascending of pre arrranged ascending data:-\n");
            printf("%lf", asct);
            printf("\nEnter the next choice: ");
            scanf("%d", &choice);
        }

        case 7: {
            desct = descSort(arr, n);
            asct = sort(arr, n);
            printf("Complexity to sort ascending of data pre arranged in descending order:-\n");
            printf("%lf", asct);
            printf("\nEnter the next choice: ");
            scanf("%d", &choice);
        }

        case 8: {
            printf("\nN value\t  Random complexity\t  Ascend complexity\t  Descend complexity\n");
            for (int step = 5000; step <= 50000; step = step + 5000) {
                arr = realloc(arr, sizeof(int)*step);
                randoms(100000, step, arr);
                asct = sort(arr, n);
                printf("%d\t  ", step);
                printf("%lf\t\t  ", asct);
                asct = sort(arr, n);
                printf("%lf\t\t  ", asct);
                desct = descSort(arr, n);
                asct = sort(arr, n);
                printf("%lf\n", asct);
            }

            printf("Enter the next choice: ");
            scanf("%d", &choice);
        }
    }

    return 0;
}
