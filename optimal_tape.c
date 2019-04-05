#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tape{
    char name[3];
    int length;
}tape;
void getdata(tape *t,int n)
{   
    int i;
    printf("\nGetting the data:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the name of the program: ");
        scanf("%s",&(t+i)->name);
        printf("Enter the length of the program: ");
        scanf("%d",&(t+i)->length);
    }
}
void optimal_storing(tape *t,int n)
{
    tape key;
    int hole,i;
    for(i=1;i<n;i++)
    {
        hole=i;
        key.length=(t+i)->length;
        strcpy(key.name,(t+i)->name);
        while (hole>0 && (t+hole-1)->length>key.length)
        {
            (t+hole)->length=(t+hole-1)->length;
            strcpy((t+hole)->name,(t+hole-1)->name);
            hole--;
        }
        (t+hole)->length=key.length;
        strcpy((t+hole)->name,key.name);
    }
}
void print_optimal(tape *t,int n)
{
    printf("\nThe programs should be stored in the given order: ");
    for(int i=0;i<n;i++)
    {
        printf("%s",(t+i)->name);
        if(i!=n-1)
        printf("->");
    }
}
int main()
{
    int n;
    printf("\nEnter the size of tape: ");
    scanf("%d",&n);
    tape *t=(tape*)malloc(sizeof(tape));
    getdata(t,n);
    optimal_storing(t,n);
    print_optimal(t,n);
    return 0;
}