#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<algorithm>
#define n 10000
using namespace std;
int arr[n]={0}; 

int calcMedian()
{
    int sum = 0;
    for (int i = 0; i <n; i++) 
    {
        int mid=i/2;//finding the median in sorted array
        int t[i+1];//fot storing the array elements and then sorting them
        for (int j = 0; j <= i; j++) 
            t[j] = arr[j];    
        sort(t,t+i+1);
        sum = (sum + t[mid])%10000;
    }
    return sum;
}
int main()
{
          
    FILE *fp;
	fp=fopen("Median.txt","r");
    int p;    
    for(int i = 0;i<n;i++)
        fscanf(fp,"%d",&arr[i]);
    fclose(fp);
    int MedianSum=calcMedian();    
    printf("%d\n",MedianSum);
    getch();
    return 0;
}
