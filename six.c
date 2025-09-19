
#include <stdio.h>
#include <time.h>
# include<stdlib.h>

int partition(int a[], int start, int end) {
    int pivot = a[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // we cant swap the pivot 
    int temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;

    return i + 1;
}

// QuickSort function
void quicksort(int a[], int start, int end) {
    if (start < end) {
        int p = partition(a, start, end);
        quicksort(a, start, p - 1);
        quicksort(a, p + 1, end);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        a[i]=rand()/10000;
    }

    clock_t t_start, t_end;
    double time_taken;

    t_start = clock();
    quicksort(a, 0, n - 1);
    t_end = clock();

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", a[i]);
    }

    time_taken = (double)(t_end - t_start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}

