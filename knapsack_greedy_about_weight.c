#include <stdio.h>
#include <string.h>
#define MAX 3   //change the value as per req
typedef struct object
{
    char name[2];
    float profit;
    float weight;
    float pwratio;
} object;
void getdata(object a[])    //this method gets the data from keybord
{
    for (int i = 0; i < MAX; i++)
    {
        printf("\nEnter object name: ");
        scanf("%s", &a[i].name);
        printf("Enter object profit: ");
        scanf("%f", &a[i].profit);
        printf("Enter object weight: ");
        scanf("%f", &a[i].weight);
        a[i].pwratio = (a[i].profit) / (a[i].weight);   //caluclate profit to weight ratio
        printf("P/W: %f", a[i].pwratio);
    }
    // for(int i=0;i<MAX;i++)
    // a[i].pwratio = (a[i].profit) / (a[i].weight);
}
void sort(object a[])   //sort the structure array with respect to profit:weight ratio
{
    object key;
    int hole;
    for (int i = 1; i < MAX; i++)
    {
        strcpy(key.name, a[i].name);
        key.weight = a[i].weight;
        key.profit = a[i].profit;
        key.pwratio = a[i].pwratio;
        hole = i;
        while (hole > 0 && a[hole - 1].pwratio < key.pwratio)
        {
            strcpy(a[hole].name, a[hole - 1].name);
            a[hole].weight = a[hole - 1].weight;
            a[hole].profit = a[hole - 1].profit;
            a[hole].pwratio = a[hole - 1].pwratio;
            hole--;
        }
        strcpy(a[hole].name, key.name);
        a[hole].weight = key.weight;
        a[hole].profit = key.profit;
        a[hole].pwratio = key.pwratio;
    }
}
void display(object a[])    //display the result
{
    int i = 0;
    printf("\nObject:\t\t");
    while (i < MAX)
        printf("%s\t", a[i++].name);
    i = 0;
    printf("\nProfit:\t\t");
    while (i < MAX)
        printf("%.2f\t", a[i++].profit);
    i = 0;
    printf("\nWeight:\t\t");
    while (i < MAX)
        printf("%.2f\t", a[i++].weight);
    i = 0;
    printf("\nPWRati:\t\t");
    while (i < MAX)
        printf("%.2f\t", a[i++].pwratio);
}
float knapsack(object a[], int m)
{
    sort(a);
    float profit;
    for (int i = 0; i < MAX; i++)
    {
        if (m > 0 && m >= a[i].weight)
        {
            m -= a[i].weight;
            profit += a[i].profit;
        }
        else
        {
            profit = profit + (m * a[i].pwratio);
            break;
        }
    }
    return profit;
}
void main() //driver function
{
    object a[MAX];
    int weightofbag;
    getdata(a);
    printf("\nEnter the weight of the bag: ");
    scanf("%d", &weightofbag);
    float profit = knapsack(a, weightofbag);
    display(a);
    printf("\n\nMax profit: %.2f", profit);
}