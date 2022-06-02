#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of philospher : ");
    scanf("%d", &n);
    int arr[100];
    int i;
    for(i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n Its lunch time ");
    int p1,p2;
    printf("\nEnter the philospher number : ");
    scanf("%d", &p1);
    printf("\nEnter the philospher number : ");
    scanf("%d", &p2);
    int sub=p2-p1;
    for(i=1;i<=n;i++)
    {
        if(p1==arr[i]||p2==arr[i])
        {
            printf("%d and %d are eating .",p1,p2);
            break;
        }
        else
        {
            printf("\nDeadlock genrated");
            break;
        }
        sub=0;
    }
}