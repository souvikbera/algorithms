#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct str{
       int wt;
       int l;
       float ratio;
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
			if(a[j].ratio>=a[pos].ratio)
			pos=j;
        }
		t.wt=a[i].wt;
		t.l=a[i].l;
		t.ratio=a[i].ratio;
		a[i].wt=a[pos].wt;
		a[i].l=a[pos].l;
		a[i].ratio=a[pos].ratio;
		a[pos].wt=t.wt;
		a[pos].l=t.l;
		a[pos].ratio=t.ratio;
		}		
    }           
int main(){
	FILE *fp;
	fp=fopen("jobs.txt","r");
	int l,w,n,i,d;
	float f;
	long long int sum=0;
	fscanf(fp,"%d",&n);
	str a[n];
	for(i=0;i<n;i++){
	fscanf(fp,"%d %d",&w,&l);
    a[i].wt=w;
	a[i].l=l;
	f=(float)w/(float)l;
	a[i].ratio=f;
	//printf("%d %d %f\n",job[i].wt,job[i].l,f);
	}
	fclose(fp);
	mysort(a,n);
	sum=calcsum(a,n);
	printf("%lld\n",sum);
	getch();
	return 0;
}
