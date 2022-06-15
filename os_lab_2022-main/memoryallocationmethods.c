//contributed by github@mishalalshahari
#include <stdio.h>
#include <stdlib.h>

void insert(int);
void traverse();

struct node{
    int data;
    struct node *next;
}*temp,*head=NULL;

struct memory{
    int app[10];
    int game[10];
    int media[10];
}s;

void sequential(){
    int arr[100],n,i;
    printf("\nEnter the size of the memory:");
    scanf("%d",&n);
    printf("\nSpecify the allocation:");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("\nThe memory allocation in sequential form:\n");
    for(i=0;i<n-1;i++) printf("%d, ",arr[i]);
    printf("%d",arr[n-1]);
}

void linked(){
    int i,t;
    printf("\nSpecify the allocation (Enter '-1' if previous is the last allocation):\n");
    while(1){
        scanf("%d",&t);
        if(t==-1) break;
        else insert(t);
    }
    traverse();
}

void insert(int num){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=num;
    n->next=NULL;
    
    if(head==NULL){
        head=n;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}

void traverse(){
    temp=head;
    printf("\nThe memory allocation in linked form:\n");
    while(temp!=NULL){
        printf("%d, ",temp->data);
        temp=temp->next;
    }
}

void indexed(){
    int n,i,a=0,g=0,me=0,t;
    printf("\nEnter the allocation for Apps (Enter '-1' if previous is the last allocation):\n");
    i=0;
    while(1){
        scanf("%d",&t);
        if(t==-1) break;
        else{
            s.app[i]=t;
            i++;
            a++;
        }
    }
    printf("\nEnter the allocation for Games (Enter '-1' if previous is the last allocation):\n");
    i=0;
    while(1){
        scanf("%d",&t);
        if(t==-1) break;
        else{
            s.game[i]=t;
            i++;
            g++;
        }
    }
    printf("\nEnter the allocation for Medias (Enter '-1' if previous is the last allocation):\n");
    i=0;
    while(1){
        scanf("%d",&t);
        if(t==-1) break;
        else{
            s.media[i]=t;
            i++;
            me++;
        }
    }
    printf("\nThe memory allocation in indexed form:\n");
    printf("\nApps: ");
    for(i=0;i<a-1;i++) printf("%d, ",s.app[i]);
    printf("%d",s.app[a-1]);
    printf("\nGames: ");
    for(i=0;i<g-1;i++) printf("%d, ",s.game[i]);
    printf("%d",s.game[g-1]);
    printf("\nMedia: ");
    for(i=0;i<me-1;i++) printf("%d, ",s.media[i]);
    printf("%d",s.media[me-1]);
}

int main(){
    int choice;
    printf("Program for various memory allocation methods.\n");
    printf("Select the method for memory allocation:\n");
    printf("1.Sequential\t2.Linked\t3.Indexed\n");
    printf("Your selection:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            sequential();
            break;
        case 2:
            linked();
            break;
        case 3:
            indexed();
            break;
        default:
            printf("\nWrong choice!");
    }
    return 0;
}
