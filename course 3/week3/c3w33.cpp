#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main(){
     FILE *fp;
     fp=fopen("mwis.txt","r");
     int n;
     fscanf(fp,"%d",&n);
     long long int wt[n];
     wt[0] = 0;
     for(int i = 1 ; i <=n ; i++){
            fscanf(fp,"%lld",&wt[i]);
            //printf("%lld\n",wt[i]);
    }
    fclose(fp);
    long long int dp[n + 1];
    dp[0] = 0;
    dp[1] = wt[1];
    for(int i = 2 ; i <=n; i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+wt[i]);
    }
    int i = n;
    printf("the verices in max weight independent set are\n");
    while( i >= 1 ){
        if( dp[i]==dp[i-1] )
        i--;
        else
        {
            if(i<5||i==17)
				printf("%d\n",i);
            if(i==117||i==517)
				printf("%d\n",i);
            if(i==997)
				printf("%d\n",i);
            i=i-2;
        }     
    }
    getch();
    return 0;
}
