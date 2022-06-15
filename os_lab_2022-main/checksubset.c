#include <stdio.h>

int subSet(int A[],int B[],int a,int b){
    int i,j;
    for(i=0;i<b;i++){
        for(j=0;j<a;j++){
            if(B[i]==A[j]) break; 
        }
        if(j==a) return 0;
    }
    return 1;
}

int main(){
    int A[100],B[100],a,b,flag,i;
    printf("Enter the number of elements of Set A:");
    scanf("%d",&a);
    printf("Enter the %d elements of Set A:",a);
    for(i=0;i<a;i++) scanf("%d",&A[i]);
    printf("Enter the number of elements of Set B:");
    scanf("%d",&b);
    printf("Enter the %d elements of Set B:",b);
    for(i=0;i<b;i++) scanf("%d",&B[i]);
    flag=subSet(A,B,a,b);
    if(flag==1) printf("B is subset of A.");
    else printf("B is not a subset of A.");
}
