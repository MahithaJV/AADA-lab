
#include <stdio.h>
#include<time.h>
# include<stdlib.h>
void mergeArrays(int a[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    int b[1000];  

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= end) {
        b[k] = a[j];
        j++;
        k++;
    }

    
    for (i = start; i <= end; i++) {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        mergeArrays(a, start, mid, end);
    }
}

int partition(int b[], int start, int end) {
    int pivot = b[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (b[j] <= pivot) {
            i++;
            int temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
    // we cant swap the pivot 
    int temp = b[i + 1];
    b[i + 1] = b[end];
    b[end] = temp;

    return i + 1;
}

// QuickSort function
void quicksort(int b[], int start, int end) {
    if (start < end) {
        int p = partition(b, start, end);
        quicksort(b, start, p - 1);
        quicksort(b, p + 1, end);
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
     printf("enter element:");
     scanf("%d",&a[i]);
    }

    printf("merge sort:");
    clock_t start,end;
    double time_taken;
    start=clock();
    mergeSort(a, 0, n - 1);
    end=clock();
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d   ", a[i]);
    }
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    printf("\n");

int m;
    printf("Enter number of elements: ");
    scanf("%d", &m);

    int b[n];
    for (int i = 0; i < m; i++) {
     printf("enter element:");
     scanf("%d",&b[i]);
    }

    printf("quicksort:");
    
    clock_t start1,end1;
    double time_taken1;
    start1=clock();
    quicksort(b, 0, n - 1);
    end1=clock();
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d   ", b[i]);
    }
    time_taken1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken1);

    printf("\n");

    return 0;
}
