#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int b[100000]; 

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= high) {
        b[k++] = a[j++];
    }

 
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}


void merge(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge(a, low, mid);
        merge(a, mid + 1, high);
        mergesort(a, low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    srand(time(0));

    printf("Random elements: ");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000000; 
        printf("%d ", a[i]);
    }
    printf("\n");

    clock_t start, end;
    double time_taken;

    start = clock();
    merge(a, 0, n - 1);
    end = clock();

    
    printf("\n");

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}

