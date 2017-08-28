#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#define SIZE 200000
using namespace std;

int** array=new int*[SIZE];
int arrcluster[SIZE];
int onecount[SIZE];

void solve(int n,int sz)
{    
    int countclus=n,count,diff;
    for(int i=0; i<n; i++)
    {
            int current=arrcluster[i], ones=onecount[i];
            for(int j=0; j<n; j++)
            {
                     diff=abs(ones-onecount[j]);
                    if(arrcluster[j]!=arrcluster[i] && (diff>=0&&diff<=3))
                   {
                        count=0;
                       for(int k=0;k<sz;k++)
                        {
                               if(count<3)
                               {
                                if(array[i][k]!=array[j][k]) 
                                count++;
                                }
                        }
                        if(count<3)
                        {
                                  int previous=arrcluster[j];
                                  for(int p=0; p<n; p++)
                                  {
                                          if(arrcluster[p]==previous)
                                          arrcluster[p]=current;
                                  }
                                  countclus--;
                        }
                   }
            }
    }
    printf("clusters required=%d\n",countclus);
}

int main()
{
    int n,sz;
    FILE *fp;
    fp=fopen("clustering_big.txt","r");
    fscanf(fp,"%d %d",&n,&sz);
    for(int i=0; i<n; i++)
    {
            arrcluster[i]=i;
            onecount[i]=0;
            array[i]=new int[sz];
            for(int j=0;j<sz;j++)
            {
                    fscanf(fp,"%d",&array[i][j]);
            if(array[i][j]==1) 
            onecount[i]++;
            }
    }
    fclose(fp);
    solve(n,sz);
    getch();
    return 0;
}
