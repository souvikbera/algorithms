#include <stdio.h>
#include<conio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#define SIZE 2000000
using namespace std; 

int a[1000000];
int b[1000000];
vector<int> graph[SIZE];
vector<int> revgraph[SIZE];
bool visited[SIZE];
bool revvisited[SIZE];
stack<int> s;
int scc[SIZE];
int counter = 1;
void addEdges(int a, int b)
{
    graph[a].push_back(b);
}
void addinvEdges(int a, int b)
{
    revgraph[b].push_back(a);
}
void DFS(int u)
{
    if(visited[u])
        return; 
    visited[u] = 1;
    for (int i=0;i<graph[u].size();i++)
        DFS(graph[u][i]);
    s.push(u);
}
void revdfs(int u)
{
    if(revvisited[u])
        return;
    revvisited[u] = 1;
    for (int i=0;i<revgraph[u].size();i++)
        revdfs(revgraph[u][i]);
    scc[u] = counter;
}
void calc2sat(int n, int a[], int b[])
{
    for(int i=0;i<n;i++)
    {
        if (a[i]>0 && b[i]>0)
        {
            addEdges(a[i]+n, b[i]);
            addinvEdges(a[i]+n, b[i]);
            addEdges(b[i]+n, a[i]);
            addinvEdges(b[i]+n, a[i]);
        } 
        else if (a[i]>0 && b[i]<0)
        {
            addEdges(a[i]+n, n-b[i]);
            addinvEdges(a[i]+n, n-b[i]);
            addEdges(-b[i], a[i]);
            addinvEdges(-b[i], a[i]);
        }
        else if (a[i]<0 && b[i]>0)
        {
            addEdges(-a[i], b[i]);
            addinvEdges(-a[i], b[i]);
            addEdges(b[i]+n, n-a[i]);
            addinvEdges(b[i]+n, n-a[i]);
        }
        else
        {
            addEdges(-a[i], n-b[i]);
            addinvEdges(-a[i], n-b[i]);
            addEdges(-b[i], n-a[i]);
            addinvEdges(-b[i], n-a[i]);
        }
    }
    for (int i=1;i<=2*n;i++)
        if (!visited[i])
            DFS(i);
 while (!s.empty())
    {
        int n = s.top();
        s.pop();
        if (!revvisited[n])
        {
            revdfs(n);
            counter++;
        }
    } 
    for (int i=1;i<=n;i++)
    {
        if(scc[i]==scc[i+n])
        {
            printf("0-not satisfied\n");
            return;
        }
    }
            printf("1-satisfied\n");
            return;
}
int main()
{
    int p;
    FILE *fp;
    fp=fopen("2sat1.txt","r");
    //fp=fopen("2sat2.txt","r");
    //fp=fopen("2sat3.txt","r");
    //fp=fopen("2sat4.txt","r");
    //fp=fopen("2sat5.txt","r");    
    //fp=fopen("2sat6.txt","r");//replace the filename with the filename which we want to execute
    fscanf(fp,"%d",&p);
    for(int i=0;i<p;i++)
    {
            fscanf(fp,"%d %d",&a[i],&b[i]);
    }
    calc2sat(p, a, b);
    fclose(fp);
    getch();
    return 0;
}
