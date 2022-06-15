//contributed by github@mishalalshahari
#include<stdio.h>
#include<stdlib.h>

void main(){
    int buffer[100],bufsize,in=0,out=0,produce,consume,choice=0;
    printf("\nEnter the size of buffer:");
    scanf("%d",&bufsize);
    bufsize++;
    while(choice!=3){
        printf("\n\n1.Produce\n2.Consume\n3.Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if((in+1)%bufsize==out) printf("\nBuffer is full!\n");
                else{
                    printf("\nEnter the value:");
                    scanf("%d",&produce);
                    buffer[in]=produce;
                    in=(in+1)%bufsize;
                }
                break;
            case 2:
                if(in==out) printf("\nBuffer is Empty!\n");
                else{
                    consume=buffer[out];
                    printf("\nThe consumed value is %d.\n",consume);
                    out=(out+1)%bufsize;
                }
                break;
            case 3:
                break;
            default:
                printf("\nInvalid Choice!\n");
                exit(0);
        }
    }
}
