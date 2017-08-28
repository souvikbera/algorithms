#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define V 500
using namespace std;
void primMST();
 int g[V][V]={0};
int main()
{
   
    FILE *fp;
	fp=fopen("edges.txt","r");
    int nodes, edges, x, y;
    long long int wt, mincost;
    fscanf(fp,"%d %d",&nodes,&edges);
    for(int i = 0;i < edges;++i)
    {
        fscanf(fp,"%d %d %lld",&x,&y,&wt);
        g[x-1][y-1]=wt;
        g[y-1][x-1]=wt;
    }
    fclose(fp);
    primMST();
    getch();
    return 0;
}
int min(int key[], bool visited[])
{
   int min = INT_MAX,pos;
   for (int i = 0; i < V; i++)
     if (visited[i] == false && key[i] < min)
         {
                    min = key[i];
                     pos = i;
         }
   return pos;
}
void totalcost(int parent[])
{
    long long int sum=0;   
   for (int i = 1; i < V; i++)
   sum=sum+g[i][parent[i]];
      printf("%lld\n",sum);
}
 

void primMST()
{
     int parent[V]; // Array to store constructed MST
     int key[V];   
     bool visited[V];
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, visited[i] = false;
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
     for (int i = 0;i < V-1;i++)
     {
        int u = min(key, visited);
             visited[u] = true;
                for (int v = 0; v < V; v++)
                {
                 if (g[u][v] && visited[v] == false && g[u][v] <  key[v])
                    {
                             parent[v]  = u;
                             key[v] = g[u][v];
                             }
             }
     }
      totalcost(parent);
}
