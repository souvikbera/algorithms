#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
long long int countinv(long long int a[], long long int n)
{
     long long int count = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i+1; j < n; j++)
      if (a[i] > a[j])
        count++;
 
  return count;
}
int main(){
	FILE *fp;
	fp=fopen("IntegerArray.txt","r");
	long long int size=100000;
	long long int a[size];
	long long int t[size];
	
	int i;
	 long long int sum=0;
	for(i=0;i<size;i++)
	{
       fscanf(fp,"%lld",&a[i]);
      // printf("%d\n",a[i]);
     }
    sum=countinv(a, size);
    printf("wait for 90 seconds");
    printf(" Number of inversions are %lld \n", sum);
    fclose(fp);
    getch();
	return 0;
}
// Number of inversions are 2407905288
