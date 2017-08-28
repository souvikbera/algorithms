#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<conio.h>
#include<limits.h>
using namespace std;

struct MinHeapNode
{
    string data;                
    int freq;             
    MinHeapNode *lc, *rc;  
    MinHeapNode(string data, int freq)
    {
        lc = rc = NULL;
        this->data = data;
        this->freq = freq;
    }
};
int minv=INT_MAX;
int maxv=0;
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int min(int a,int b)
{
    if(a<b)
    return a;
    return b;
} 
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return; 
    if (root->data != "$") // not internal node
        cout << root->data << ": " << str << "\n"; 
    printCodes(root->lc, str + "0");
    printCodes(root->rc, str + "1");
} 
int calclength(struct MinHeapNode* root, int val,int option)
{
    if (root == NULL) 
     return 0;
    if (root->lc==NULL && root->rc==NULL)
    return val;
    if(option==1)
    return min(calclength(root->lc, val+1,option),calclength(root->rc, val+1,option));
    else if(option==0)
    return max(calclength(root->lc, val+1,option),calclength(root->rc, val+1,option));    
} 
void solve(string data[], int freq[], int size)
{
    struct MinHeapNode *lc,*rc,*top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i=0;i<size;i++)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    while (minHeap.size() != 1)
    {       
        lc = minHeap.top();
        minHeap.pop();
        rc = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode("$", lc->freq + rc->freq);
        top->lc = lc;
        top->rc = rc;
        minHeap.push(top);
    }
  	printCodes(minHeap.top(), "");
    int max=calclength(minHeap.top(), 0,0);
    int min=calclength(minHeap.top(), 0,1);
    printf("min length of codeword=%d\n",min);
    printf("max length of codeword=%d\n",max);
} 
int main()
{	
     int n,wt;
     FILE *fp;
     fp=fopen("huffman.txt","r");
     fscanf(fp,"%d", &n);
     string arr[n];
     int freq[n];
     for(int i=0;i<n;i++)
     {
        fscanf(fp,"%d", &wt);
        arr[i]=wt;
        freq[i]=wt;
	}     
    solve(arr, freq, n);
 	getch();
    return 0;
}
