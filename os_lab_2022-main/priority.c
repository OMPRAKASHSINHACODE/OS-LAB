//contributed by github@mishalalshahari
#include<stdio.h>

void swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

void sort(int bt[],int pr[],int p[],int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(pr[i]>pr[j]){
                swap(&bt[i],&bt[j]);
                swap(&pr[i],&pr[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
    
}

int main(){
    int n,bt[100],pr[100],p[100],wt=0,tt,i,awt=0,att=0;
    printf("Program for Priority Algorithm.\n\n");
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("\nEnter the burst time and priority towards respective process:\n");
    printf("\nProcess\t\tBurst Time\tPriority\n\n");
    for(i=0;i<n;i++){
        p[i]=i;
        printf("P%d\t\t",i);
        scanf("%d",&bt[i]);
        scanf("%d",&pr[i]);
        
    }
    sort(bt,pr,p,n);
    tt=bt[0];
    printf("\nProcess\t\tBurst Time\tPriority\t\tWaiting Time\t\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("\nP%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],pr[i],wt,tt);
        awt=wt+awt;
        wt=wt+bt[i];
        att=tt+att;
        tt=wt+bt[i+1];
    }
    printf("\n\nAverage Waiting Time: %.3f",(float)awt/n);
    printf("\nAverage Turnaround Time: %.3f",(float)att/n);
    return 0;
}
