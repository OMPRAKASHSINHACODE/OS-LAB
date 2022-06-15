#include <stdio.h>

void swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

void selection(int arr[],int size){
    int i,j,min;
    for(i=0;i<size-1;i++){
        min=i;
        for(j=i;j<size;j++){
            if(arr[min]>arr[j]) min=j;
        }
        swap(&arr[min],&arr[i]);
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
    selection(arr,n);
    printf("\nSorted array:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
