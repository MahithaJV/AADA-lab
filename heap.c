# include<stdio.h>
#include<stdlib.h>
# include<time.h>

void maxheapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    while(l<n &&a[l]>a[largest])
    largest=l;
    while(r<n && a[r]>a[largest])
    largest=r;
if(i!=largest){
    int tem=a[i];
    a[i]=a[largest];
    a[largest]=tem;
    maxheapify(a,n,largest);
}
}
void bulidmaxheap(int a[],int n){
    for(int i=n/2-1;i>=0;i--)
    maxheapify(a,n,i);
}
int main(){
    int n;
    printf("enter no of ele");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("enter no of element :");
        scanf("%d",&a[i]);
    }
    double timetaken;
    clock_t start=clock();
    bulidmaxheap(a,n-1);
    clock_t end=clock();


    for(int i=0;i<n;i++){
    
        printf("%2d   ",a[i]);
    }
    printf("\n");
    timetaken= (double) (end-start)/CLOCKS_PER_SEC;
    printf("time taken is %f\n",timetaken);

}

