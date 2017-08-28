#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int search(int);
void merge(int,int);
int numClusters();

typedef struct
{
    int src;
    int dest;
    int cost;
}Edge;
int base[500];
int min(int a,int b)
{
        if(a<b)
        return a;
        else
        return b;
}
bool cmp(Edge e1, Edge e2) 
{
     return (e1.cost < e2.cost);
} 
int countcluster()
{
		//-ve entries=no.of clusters
		int c = 0;
		for(int k = 0; k <500; k++)
		{
			if (base[k]<0) 
            c++;
            }
		return c;	
        
}
int search(int a)
{
    	
		while (base[a]>0)
		{
			a = base[a];
		}
		return a;
	
}
void merge(int a, int b)
{
     	int basea = search(a);
		int baseb = search(b);
		if (basea == baseb) 
        base[basea] += -1;
		else 
		{
			if (base[basea] < base[baseb])
			{
				base[basea] += base[baseb];
				base[baseb] = basea;
			}else
			{
				base[baseb] += base[basea];
				base[basea] = baseb;
			}
		}		
}	
int main()
{
    vector<Edge> E;
    Edge e; 
    int v;    
    memset(base, -1 ,sizeof(base) ) ;    
    FILE *fp;
	fp=fopen("clustering1.txt","r");
    
        fscanf(fp,"%d",&v);
        int a,b,c;

       for(int k=0;k<v*(v-1)/2;k++)
        {
                        fscanf(fp,"%d %d %d",&a,&b,&c);
                        e.src=a-1;
                        e.dest=b-1;
                        e.cost=c;
                        E.push_back(e);
                                        //printf("%d %d %d\n",e.src,e.dest,e.cost);
        }  
    sort(E.begin(), E.end(), cmp);
    for(int k=0;k<499*500/2;k++)
    {
            merge(E[k].src,E[k].dest);			
				if (countcluster()==4) 
				break;
    }
    
			int max = INT_MAX;
     for(int k=0;k<499*500/2;k++)
    {
            if (search(E[k].src)!=search(E[k].dest))
                { 
                                             
                                         max=min(max,E[k].cost);	
                }	
    }
			printf("max distance %d",max);	
    getch();
    return 0;
}
