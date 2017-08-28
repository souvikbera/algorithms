#include<stdio.h>
#include<conio.h> 
#include<iostream>
using namespace std;
#define MAX(a,b) a>b?a:b
long long int knapSack(long long int size,long long int wt[],long long int val[],long long int n)
{
    long long  int dp[2][size+1];
    for(int i=1; i<=n; i++)
    {
          for(long long int j=0; j<=size; j++)
             if(j>=wt[i])
                dp[1][j]=max(dp[0][j],dp[0][j-wt[i]]+val[i]);
             else
                dp[1][j]=dp[0][j];
          for(long long int k=0; k<=size; k++)
             dp[0][k]=dp[1][k];
    }
    printf("%lld\n",dp[1][size]);
    return 1;
}
int main()
{
          
    FILE *fp;
	fp=fopen("knapsack1.txt","r");
    long long int size,n;
    fscanf(fp,"%lld %lld",&size,&n);
    long long int val[n];
    long long int wt[n];    
    for(int i = 0;i<n;i++)
    {
        fscanf(fp,"%lld %lld",&val[i],&wt[i]);
        //printf("%lld %lld\n",val[i],wt[i]);
    }
    fclose(fp);
    long long int ans=knapSack(size, wt, val, n);
    
    getch();
    return 0;
}

