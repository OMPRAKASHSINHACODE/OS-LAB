#include<stdio.h>

int main(){
    int n,allo[100][3],max[100][3],avail[3],need[100][3],i,j,flag=1,index=0,k;
    printf("Program for Banker's Algorithm.\n");
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\nProcess\t\t\tAllocation\t\tMax");
    printf("\n\t\t\tR1  R2  R3\t\tR1  R2  R3\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t\t",i);
        for(j=0;j<3;j++){
            scanf("%d",&allo[i][j]);
        }
        for(j=0;j<3;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nAvailable:\nR1  R2  R3\n");
    for(i=0;i<n;i++) scanf("%d",&avail[i]);
    int f[n],ans[n];
    for(i=0;i<n;i++){
        f[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    int y=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(f[j]==0){
                flag=0;
                for(k=0;k<3;k++){
                    if(need[j][k]>avail[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[index++]=j;
                    for(y=0;y<3;y++){
                        avail[y]+=allo[j][y];
                    }
                    f[j]=1;
                }
            }
        }
    }
    flag=1;
    for(i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            printf("\nDeadlock Condition i.e. not safe!");
            break;
        }
    }
    if(flag==1){
        printf("\nThe safe sequence is:\n");
        for(i=0;i<n-1;i++){
            printf("P%d->",ans[i]);
        }
        printf("P%d",ans[n-1]);
    }
    return 0;
}
