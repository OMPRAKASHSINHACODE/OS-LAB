//contributed by github@mishalalshahari
#include<stdio.h>

int main(){
    int n,s,bt[100],ct[100],wt[100],tat[100],i,j,awt=0,att=0,max;
    float temp=0;
    printf("Program for Round Robin Algorithm.\n\n");
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the time slice:");
    scanf("%d",&s);
    printf("\nEnter the burst time towards respective process:\n");
    printf("\nProcess\t\tBurst Time\n\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t",i);
        scanf("%d",&bt[i]);
        ct[i]=bt[i];
    }
    max=bt[0];
    for(i=1;i<n;i++){
        if(max<bt[i]) max=bt[i];
    }
    for(j=0;j<(max/s)+1;j++){
        for(i=0;i<n;i++){
            if(bt[i]!=0){
                if(bt[i]<=s){
                    tat[i]=temp+bt[i];
                    temp=temp+bt[i];
                    bt[i]=0;
                }
                else{
                    bt[i]=bt[i]-s;
                    temp=temp+s;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        wt[i]=tat[i]-ct[i];
        att+=tat[i];
        awt+=wt[i];
    }
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("\nP%d\t\t%d\t\t\t%d\t\t\t%d",i+1,ct[i],wt[i],tat[i]);
    }
    printf("\n\nAverage Waiting Time: %.3f",(float)awt/n);
    printf("\nAverage Turnaround Time: %.3f",(float)att/n);
    return 0;
}
