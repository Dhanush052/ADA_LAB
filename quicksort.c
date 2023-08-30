#include<stdio.h>
void main(){
    int arr[20],low,high,n,i;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    low=0;high=n-1;
    quickSort(low, high, arr);

    printf("Sorted array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}

void quickSort(int low,int high,int a[]){
    int j;
    if(low<high){
        j=partition(low,high,a);
        quickSort(low,j-1,a);
        quickSort(j+1,high,a);
    }
}

int partition(int low, int high, int a[]){
    int i,j,pivot,temp;
    i=low;
    j=high+1;
    pivot=a[low];
    while(i<j){
        do{
            i=i+1;
        }while(pivot>=a[i]);
        do{
            j=j-1;
        }while(pivot<a[j]);
        if(i<j){
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        if(i>j)
    {
        temp = a[low];
        a[low]=a[j];
        a[j]=temp;
    }
    }
    return j;
}
