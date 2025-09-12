# include<stdio.h>
void maxheapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n &&a[l]>a[largest])
    largest=l;
    if(r<n && a[r]>a[largest])
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
void insertelement(int a[],int n,int value){
    a[n]=value;
   int i=n;
   n=n+1;

   int parent=i/2-1;
   if(a[parent]<a[i]){
    int tem=a[parent];
    a[parent]=a[i];
    a[i]=tem;
    i=parent;
   }
   else
   return;

}
int main(){
    int n;
    printf("enter no of ele");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("enter elelment");
        scanf("%d",&a[i]);
    }
    bulidmaxheap(a,n-1);
    printf("before insertion\n");
    for(int i=0;i<n;i++){
        printf("%d   ",a[i]);
    }
    insertelement(a,n-1,100000);
    bulidmaxheap(a,n-1);
    printf("after insertion\n");
    for(int i=0;i<n;i++){
        printf("%d   ",a[i]);
    }

}
