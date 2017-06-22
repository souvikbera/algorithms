#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#define n 1000000
using namespace std;
long long int arr[n]={0};
int calculate() {
		int i;
		int count = 0;
		int c=0;
		sort(arr,arr+n);
		for ( i = -10000; i <= 10000; i++) {
			int start = 0;
            int end = n- 1;
			while (start < end) {
				long sum = arr[start] + arr[end];
				if (i==sum) {
					if (arr[start] != arr[end])
						count++;
					break;
				} else if (sum <i) {
					start++;
				} else {
					end--;
				}
			}
			
			if (i % 1000 == 0)
			{
                printf("counter=%d\n",c);
                c++;  
             }
		}
		return count;
	}
	
int main()
{
          
    FILE *fp;
	fp=fopen("2sum.txt","r");
    int p;    
    for(int i = 0;i<n;i++)
        fscanf(fp,"%lld",&arr[i]);
    fclose(fp);\
    printf("Please execute until counter=20\n"); 
    int ans=calculate();    
    printf("Anser is %d\n",ans);
    getch();
    return 0;
}
