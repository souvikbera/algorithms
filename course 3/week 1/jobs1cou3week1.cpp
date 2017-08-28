#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct str{
       int wt;
       int l;
       int diff;
       };
long long int calcsum(str a[],int n)
{
         int i,t=0;
         long long int sum=0;
	     for(i=0;i<n;i++){
		 t=t+a[i].l;
		 sum=sum+a[i].wt*t;
	}
	return sum;
}       

void mysort(str a[],int n){
	int i,j,pos,C=0;
	long long int sum=0;
	str t;
	for(i=0;i<n-1;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(a[j].diff>=a[pos].diff)
			{
                if(a[j].diff>a[pos].diff)                         
				pos=j;
			    else if((a[j].diff==a[pos].diff)&&(a[j].wt>a[pos].wt))
				pos=j;
			}
        }
		t.wt=a[i].wt;
		t.l=a[i].l;
		t.diff=a[i].diff;
		a[i].wt=a[pos].wt;
		a[i].l=a[pos].l;
		a[i].diff=a[pos].diff;
		a[pos].wt=t.wt;
		a[pos].l=t.l;
		a[pos].diff=t.diff;
		}
        
}                    
int main(){
	FILE *fp;
	fp=fopen("jobs.txt","r");
	int l,w,n,i,d;
	long long int sum=0;
	fscanf(fp,"%d",&n);
	str a[n];
	for(i=0;i<n;i++){
	fscanf(fp,"%d %d",&w,&l);
	a[i].wt=w;
	a[i].l=l;
	a[i].diff=w-l;
	}
	fclose(fp);
	mysort(a,n);
	sum=calcsum(a,n);
	printf("%lld\n",sum);
    getch();
	return 0;
}
