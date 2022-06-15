#include <stdio.h>

void swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

void bubbleSort(int arr[],int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
    }
}

int main()
{
    int arr[100],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the %d elements of array: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    printf("\nSorted array:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
