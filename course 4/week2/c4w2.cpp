//please run this program in linux environment and not windows environment
#include<stdio.h>
//#include<conio.h>
#include<vector>
#include<string>
#include<iostream>
#include<limits.h>
#include<math.h>
#include<stdint.h>
#include<limits.h> 
#include<stdlib.h>
#define INF 999999
using namespace std;

int ncity;
typedef struct
{
    float xc;
    float yc;
}TSP;
vector<TSP>points;
float dist[25][25]={0.0};
float calcdist(int src,int dest)
{
       float a,b,c;
     a=pow(points[src].xc - points[dest].xc,2);
     b=pow(points[src].yc - points[dest].yc,2);
     c=sqrt(a+b);
     return c;
}
void finddist()
{
            for (int i=0;i<ncity;i++)
                for (int j=0;j<ncity;j++)
                {
                    dist[i][j] =calcdist(i,j);
                }
}
void solve(int n)
{	
	 float **dp = new float*[1<<n];
            for (int i=0;i<(1<<n);i++)
            {
                dp[i] = new float[n];         
            }
     	int i,j,k,p;
   	 float ans;
     	for (k=0;k<n;k++) 
	{
            for (i=0;i<n;i++) 
	    {
                for (j=0;j<n;j++) 
		{
                    if (i!=j&&i!=k&&j!=k) 
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        for(int i=0;i<(1<<n);i++)
        {
                for(j=0;j<n;j++)
                dp[i][j]=-1.0;
        }
        dp[1][0]=0;
        // TSP solution using DP and bitmasking
        for (i=1;i<(1<<n);i++) 
        {
            for (j=0;j<n;j++) 
            {
                if (dp[i][j]==-1.0)
                 continue;
                for (k=1;k<n;k++) 
                {
                    if ((i&(1<<k))!=0) 
                    continue;
                    p=(i|(1<<k));
                    if (dp[p][k]==-1) 
                    dp[p][k]=dp[i][j]+dist[j][k];
                    dp[p][k]=min(dp[p][k],dp[i][j]+dist[j][k]);
                }
            }
        }
        ans=INF;
        for (i=1; i<n; i++) {
            if (dp[(1<<n)-1][i]>0) 
            ans=min(ans,dp[(1<<n)-1][i]+dist[i][0]);
        }
        printf("Ans=%d\n",(int)ans);
	    for (int i=0;i<(1<<n);i++)
            {
                delete[] dp[i];
            }
            delete[] dp;    
}
int main()
{
    float a,b;
    FILE *fp;
    fp=fopen("tsp.txt","r");
    fscanf(fp,"%d",&ncity);
    TSP t;
    for(int i=0;i<ncity;i++)
    {
        fscanf(fp,"%f %f",&a,&b);
        t.xc=a;
        t.yc=b;
        points.push_back(t);        
    }
    finddist();
    solve(ncity);
   //getch();
    return 0;
}
