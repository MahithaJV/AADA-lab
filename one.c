
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

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
     printf("enter element:");
     scanf("%d",&a[i]);
    }
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

    return 0;
}
