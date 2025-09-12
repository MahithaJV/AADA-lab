# include<stdio.h>
# include<stdlib.h>
int partition(int a[],int low,int high){
    int random=low+rand()%(high-low+1);
    int tem=a[random];
    a[random]=a[high];
    a[high]=tem;
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high;j++){
        if(a[j]<pivot){
            i++;
            int tem=a[i];
            a[i]=a[j];
            a[j]=tem;
        }
    }
    int tem1=a[high];
    a[high]=a[i+1];
    a[i+1]=tem1;
    return i+1;

}

void quicksort(int a[],int low,int high){
    int p;
    if(low<high){
        p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}
int main(){
    int i,n;
    printf("enter no of elements");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("enter element");
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d   ",a[i]);
    }
    return 0;
    }
