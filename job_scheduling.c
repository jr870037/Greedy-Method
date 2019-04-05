#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct job
{
    char name[2];
    int deadline;
    int profit;
} job;
void getdata(job *j, int n)
{
    int i;
    printf("\nGetting the data:\n\n");
    for (i = 1; i < n; i++)
    {
        printf("Enter the name of the job: ");
        scanf("%s", &(j + i)->name);
        printf("Enter the deadline of %s: ", (j + i)->name);
        scanf("%d", &(j + i)->deadline);
        printf("Enter the profit of %s: ", (j + i)->name);
        scanf("%d", &(j + i)->profit);
        printf("\n");
    }
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int findmaxdeadline(job *j, int n)
{
    int max = j->deadline;
    for (int i = 1; i < n; i++)
        if (max < (j + i)->deadline)
            max = (j + i)->deadline;
    return max;
}
void initialize(int *t, int n)
{
    for (int i = 1; i < n; i++)
        t[i] = -1;
}
void sort(job *j, int n)
{
    int hole;
    job key;
    for (int i = 2; i < n; i++)
    {
        hole = i;
        key.deadline = (j + i)->deadline;
        key.profit = (j + i)->profit;
        strcpy(key.name, (j + i)->name);
        while (hole > 1 && (j + hole - 1)->profit < key.profit)
        {
            (j + hole)->deadline = (j + hole - 1)->deadline;
            (j + hole)->profit = (j + hole - 1)->profit;
            strcpy((j + hole)->name, (j + hole - 1)->name);
            hole--;
        }
        (j + hole)->deadline = key.deadline;
        (j + hole)->profit = key.profit;
        strcpy((j + hole)->name, key.name);
    }
}
void printtimeslot(job *j,int *ts,int dmax)
{
    char c[2];
    for(int i=1;i<dmax;i++)
    {
        if(ts[i]!=-1)
        {
           strcpy(c,j[ts[i]].name);
           printf("%s\t",c); 
        }
    }
    printf("\n");
}
int jobseq(job *j, int n)
{
    int profit = 0, k, dmax;
    dmax = findmaxdeadline(j, n);
    sort(j, n);
    int *ts = (int *)malloc(sizeof(int) * dmax + 1);
    initialize(ts, dmax + 1);
    for (int i = 1; i < n; i++)
    {
        // k = min((j + i)->deadline, dmax);
        k=(j+i)->deadline;
        while (k > 0)
        {
            if (ts[k] == -1)
            {
                profit += j[i].profit;
                ts[k] = i;
                break;
            }
            else
                k--;
        }
    }
    printtimeslot(j,ts,dmax+1);
    return profit;
}
void main()
{
    int n;
    printf("\nEnter the number of jobs: ");
    scanf("%d", &n);
    n += 1;
    job *j = (job *)malloc(sizeof(job) * n);
    getdata(j, n);
    int profit = jobseq(j, n);
    printf("\nMax Profit: %d", profit);
}










// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #define MAX 3
// typedef struct scheduling{
//     char jobname[2];
//     int deadline;
//     int profit;
// }job;
// void getdata(job a[])
// {
//     int i=0;
//     while(i<MAX)
//     {
//         printf("\nEnter job name: ");
//         scanf("%s",&a[i].jobname);
//         printf("Enter deadline: ");
//         scanf("%d",&a[i].deadline);
//         printf("Enter profit: ");
//         scanf("%d",&a[i++].profit);
//     }
// }
// void sort(job a[])
// {
//     job key;
//     int hole;
//     for(int i=1;i<MAX;i++)
//     {
//         strcpy(key.jobname,a[i].jobname);
//         key.deadline=a[i].deadline;
//         key.profit=a[i].profit;
//         hole=i;
//         while(hole>0 && a[hole-1].deadline<key.deadline)
//         {
//             strcpy(a[hole].jobname,a[hole-1].jobname);
//             a[hole].deadline=a[hole-1].deadline;
//             a[hole].profit=a[hole-1].profit;
//             hole--;
//         }
//         strcpy(a[hole].jobname,key.jobname);
//         a[hole].deadline=key.deadline;
//         a[hole].profit=key.profit;
//     }
// }
// void display(job a[])
// {
//     int i=0;
//     printf("\nJOB:\t\t");
//     while(i<MAX)
//     printf("%s\t",a[i++].jobname);
//     i=0;
//     printf("\nDeadline:\t");
//     while(i<MAX)
//     printf("%d\t",a[i++].deadline);
//     i=0;
//     printf("\nProfit:\t\t");
//     while(i<MAX)
//     printf("%d\t",a[i++].profit);
//     printf("\n\n");
// }
// void printtimeslot(job a[],int *timeslot,int n)
// {
//     for(int i=0;i<n;i++)
//     if(timeslot[i]!=-1)
//     printf("%s\t",a[timeslot[i]].jobname);
//     printf("\n");
// }
// int jobscheduling(job a[])
// {
//     sort(a);
//     int profit=0,maxslot=a[0].deadline,k,*timeslot=(int*)malloc(sizeof(int)*maxslot);
//     for(int i=0;i<maxslot;i++)
//     timeslot[i]=-1;
//     for(int i=0;i<MAX;i++)
//     {
//         k=a[i].deadline;
//         while(k>0)
//         {
//             if(timeslot[k]==-1)
//             {
//                 profit+=a[i].profit;
//                 timeslot[k]=i;
//                 break;
//             }
//             else
//             k-=1;
//         }
//     }
//     printtimeslot(a,timeslot,maxslot);
//     return profit;
// }
// void main()
// {
//     job a[MAX];
//     getdata(a);
//     display(a);
//     int maxprofit=jobscheduling(a);
//     printf("Max Profit: %d",maxprofit);
// }