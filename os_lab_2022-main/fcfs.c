//contributed by github@mishalalshahari
#include<stdio.h>

int main(){
    int n,arr[100],wt=0,tt,i,awt=0,att=0;
    printf("Program for First Come First Serve(FCFS) Algorithm.\n");
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("\nEnter the burst time towards respective process:\n");
    printf("\nProcess\t\tBurst Time\n\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t",i);
        scanf("%d",&arr[i]);
    }
    tt=arr[0];
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("\nP%d\t\t%d\t\t\t%d\t\t\t%d",i,arr[i],wt,tt);
        awt=wt+awt;
        wt=wt+arr[i];
        att=tt+att;
        tt=wt+arr[i+1];
    }
    printf("\n\nAverage Waiting Time: %.3f",(float)awt/n);
    printf("\nAverage Turnaround Time: %.3f",(float)att/n);
    return 0;
}
