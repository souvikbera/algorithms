#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define MAX 100000
void calculate(char* p)
{
    int v,e,i,j,k,src,dest,wt;
    FILE *fp;
	fp=fopen(p,"r");
	fscanf(fp,"%d %d",&v,&e);
    int *arr[v];
    for(j=0;j<v;j++) 
    arr[j]=new int[v];
    for(i=0;i<v;i++)
    {
    	for(j=0;j<v;j++)
        {
    		if(i==j)
    			arr[i][j] = 0;
    			else
    			arr[i][j]=MAX;
    	}
    }
      	for(i=0;i<e;i++){
        fscanf(fp,"%d %d %d", &src,&dest,&wt);
        arr[src-1][dest-1] = wt;
	}
	fclose(fp);
    for (i=0;i<v;i++)
    {
        for (j=0;j<v;j++)
        {   
            for (k=0;k<v;k++)
            {
                if (arr[j][i]+arr[i][k]<arr[j][k])
                    arr[j][k]=arr[j][i]+arr[i][k];
            }
        }
    }
    
    for(i=0;i<v;i++)
    {
    	for(j=0;j<v;j++)
        {
    		if(i==j&&arr[i][j]<0)
    		break;
    	}
    }    
    if(j!=v)
    {
         printf("Cycle is present\n");
	}
	else
    {
		int min=MAX;
		for(i=0;i<v;i++)
        {
        	for(j=0;j<v;j++)
            {
        		if(arr[i][j]<min)
        			min=arr[i][j];
        	}
        }
    printf("Shortest path=%d\n",min);
   	}
    
}
int main()
{
    calculate("g1.txt");
    calculate("g2.txt");
    calculate("g3.txt");
    getch();
    return 0;
}
