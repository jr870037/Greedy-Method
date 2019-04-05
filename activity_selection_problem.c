#include<stdio.h>
#include<string.h>
#define MAX 3
typedef struct typeactivty{
    char name[2];
    int start,finish;
}activity;
void getdata(activity a[]);
void display(activity a[]);
void sort(activity a[]);
void activityselection(activity a[]);
void printtheactivity(activity a[],int temparray[],int m);
void main()
{
    activity a[MAX];
    getdata(a);
    activityselection(a);
}
void getdata(activity a[])
{
    for(int i=0;i<MAX;i++)
    {
        printf("\nEnter the activity name: ");
        scanf("%s",&a[i].name);
        printf("Enter starting time: ");
        scanf("%d",&a[i].start);
        printf("Enter finish time: ");
        scanf("%d",&a[i].finish);
    }
}
void activityselection(activity a[])
{
    sort(a);
    int temparray[MAX],k=0,m=0;
    temparray[m++]=0;
    for(int i=1;i<MAX;i++)
    {
        if(a[i].start>=a[k].finish)
        {
            temparray[m++]=i;
            k=i;
        }
    }
    printtheactivity(a,temparray,m);
}
void sort(activity a[])
{
    activity key;
    int hole;
    for(int i=1;i<MAX;i++)
    {
        strcpy(key.name,a[i].name);
        key.start=a[i].start;
        key.finish=a[i].finish;
        hole=i;
        while(hole>0 && a[hole-1].finish>key.finish)
        {
            a[hole].finish=a[hole-1].finish;
            a[hole].start=a[hole-1].start;
            strcpy(a[hole].name,a[hole-1].name);
            hole--;
        }
        a[hole].finish=key.finish;
        a[hole].start=key.start;
        strcpy(a[hole].name,key.name);
    }
}
void display(activity a[])
{
    printf("\nActivity\tS\tF");
    for(int i=0;i<MAX;i++)
    printf("\n%s\t\t%d\t%d ", a[i].name, a[i].start, a[i].finish);
        
}
void printtheactivity(activity a[],int temparray[],int m)
{
    display(a);
    printf("\n\nActivity selected: ");
    for(int i=0;i<m;i++)
    {
        printf("%s",a[temparray[i]].name);
        if(i!=m-1)
        printf("->");
    }
}