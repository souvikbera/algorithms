#include <iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<stdio.h>
#include<limits.h>
#include<math.h>
using namespace std;

double length = 0.0;
int vis[33708]={0};
typedef struct
{
    double xc;
    double yc;
}TSP;
vector<TSP>points;
double calcdist(int src,int dest)
{
       double a,b,c;
     a=pow(points[src].xc - points[dest].xc,2);
     b=pow(points[src].yc - points[dest].yc,2);
     c=sqrt(a+b);
     return c;
}
int nextdest(int n,int src)
{
    int dest;
    double mindist=INT_MAX;
    for(int i=0;i<n;i++)
    {
        double dis=calcdist(src,i);
        if(dis<mindist&&vis[i]==0)
        {
            mindist=dis;
            dest=i;
        }
    }
    length=length+mindist;
    return dest;
}
double TSPCal(int n){
    int src=0;
    vis[src]=1;
    for(int i=1;i<n;i++)
    {
        vis[src]=1;
        src=nextdest(n,src);   
    }
    length=length+calcdist(src,0);
    return length;
}
int main()
{
    int n,p;
    double a,b;
    FILE *fp;
    fp=fopen("nn.txt","r");
    fscanf(fp,"%d",&n);
    TSP t;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d %lf %lf",&p,&a,&b);
        t.xc=a;
        t.yc=b;
        points.push_back(t);
        vis[i]=0;
    }
    long long int ans=(long long int)TSPCal(n);
    printf("TSP Heuristic distance=%lld\n",ans);
    getch();
    return 0;
}
