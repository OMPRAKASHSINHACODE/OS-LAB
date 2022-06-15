#include<stdio.h>
#include<stdlib.h>

int N,P_name[20],H,HH[20],C; 

void one(){
    int pos = 0, x, i;
    printf("\nAllow one philosopher to eat at any time\n"); 
    for(i=0;i<H; i++, pos++) {
        printf("\nP%d have permisson to eat", P_name[HH[pos]]); 
        for(x=pos;x<H;x++)
            printf("\nP%d is waiting", P_name[HH[x]]);
    }
}

void two(){
    int i, j, s=0, t, r, x;
    printf("\nAllow two philosophers to eat at same time."); 
    for(i=0;i<H;i++) {
        for(j=i+1;j<H;j++) {
            if(abs(HH[i]-HH[j])>=1 && abs(HH[i]-HH[j])!=4) {
                printf("\nCombination %d :\n", (s+1)); 
                t=HH[i]; r=HH[j]; s++;
                printf("\nP%d and P%d have permisson to eat", P_name[HH[i]],
                P_name[HH[j]]);
                for(x=0;x<H;x++) if((HH[x]!=t)&&(HH[x]!=r)) printf("\nP%d is waiting", P_name[HH[x]]);
            }
        }
    }
}

int main(){
    printf("\nDining Philospher Problem\n");
    printf("\nEnter the Total No. of philosophers: "); 
    scanf("%d",&N);
    for(int i=0;i<N;i++) P_name[i]=(i+1);
    printf("How many are Hungry : ");
    scanf("%d", &H);
    if(H==N){
        printf("\nAll are Hungry..\nDead lock stage will occur");
        printf("\nExiting...\n");
    }else{
        for(int i=0;i<H;i++){ 
            printf("Enter philosopher %d position:",(i+1));
            scanf("%d",&HH[i]);
        }
        while(1) {
            printf("1.One can eat at a time\n2.Two can eat at a time\n3.Exit\nEnter your Cice:"); 
            scanf("%d", &C);
            switch(C){
                case 1: one(); break;
                case 2: two(); break; 
                case 3: exit(0);
                default: printf("\nInvalid option..");
            }
        }
    }
    return 0;
}
