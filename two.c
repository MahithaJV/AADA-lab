# include<stdio.h>
# include<stdlib.h>
# include<time.h>
//merging two array with help of duplicate array
void merge(char a[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    char b[1000];  

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

//mergesorting
void mergesort(char a[],int start,int end){
    if(start<end){
        int mid=start+(end-start)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}
int main(){
    int n;
    printf("enter no of characters :");
    scanf("%d",&n);
    char a[n];
    for(int i=0;i<n;i++){
        printf("enter the character element: ");
        scanf(" %c",&a[i]);
    }

    printf("before sorting:");
    for(int i=0;i<n;i++){
       printf(" %c    ",a[i]);
    }
    clock_t start,end;
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    double time_taken=(double)end-start/CLOCKS_PER_SEC;
    printf("time taken for the mergesorting is:  %d",time_taken);

    printf("after sorting:");
    for(int i=0;i<n;i++){
       printf(" %c    ",a[i]);
    }
    return 0;
}