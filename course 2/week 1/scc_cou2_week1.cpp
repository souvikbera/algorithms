#include <stdio.h>
#include<conio.h>
#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
#include <string>
using namespace std;
#define SIZE 875714

struct str {
       vector<int> source;
       vector<int> dest;
	   bool visited;
	   int comp;
};
vector<int> SCC;
vector <int> top;
stack<int> st;
str Graph[SIZE];




void DFS(int n) {
	if(Graph[n].visited == true) 
    return;
    Graph[n].visited = true;
	for(int i = 0; i < Graph[n].dest.size(); i++) 
    {
		DFS(Graph[n].dest[i]);
	}
	st.push(n);
	return;
}

void revDFS(int n,int count) {
	if(Graph[n].visited == false) return;

	Graph[n].visited = false;
	int t = 0;
	for(int i = 0; i < Graph[n].source.size(); i++) {
		t = Graph[n].source[i];
		revDFS(t,count);
	}
	Graph[n].comp = count;
	SCC[count - 1]++;
	return;
}


int main() {
	int count = 0;
    FILE *fp;
	fp=fopen("SCC.txt","r");
	int start,end;
    while( fscanf(fp,"%d %d", &start, &end) > 0) {
		Graph[start].dest.push_back(end);
		Graph[end].source.push_back(start);
	}
	fclose(fp);
	
	for(int j = 1; j < SIZE + 1; j++) {
		if( !Graph[j].visited ) 
        DFS(j);
	}
	
	//reverse DFS
	while(!st.empty()) {
		int top = st.top();
		st.pop();
		if(Graph[top].visited == true) {
			count++;
			SCC.push_back(0);
			revDFS(top,count);
		}
	}

	
    for(int i = 0; i < SCC.size(); i++) {
		top.push_back(SCC[i]);
	}
	sort (top.rbegin(),top.rend());  // sorting in descending order
	 for(int i = 0; i < 5; i++) {
		printf("%d\n",top[i]);
	}    	
	getch();
	return 0;
}
