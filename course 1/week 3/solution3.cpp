#include<stdio.h>
#include<conio.h>
#define n 10000
int arr[n]={0};
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int findMedian(int low,int high)
{
        int median;
        int mid = (low + high) / 2;
        int a=arr[low];
        int b=arr[mid];
        int c=arr[high];
        if(a > b)
         {
			if(c > a) 
				return low;
			 else if(c < b) 
				return mid;
			 else 
				return high;
		}
         else 
         {
			if(c < a) 
				return low;
		    else if(c > b) 
				return mid;
			 else 
				return high;
			
		} 
        
}

int partition(int low, int high) {
    int med=findMedian(low,high-1);
    swap(&arr[med],&arr[low]);
    int pivot = arr[low];
    int pivpos = low;    
    for (int i = low + 1; i < high; i++) {
      if (arr[i] < pivot) {
         swap(&arr[i], &arr[pivpos+1]);
        pivpos++;
      }
    }
    
    arr[low] = arr[pivpos];
    arr[pivpos] = pivot;
    return pivpos;
  }
   
int quickSort(int low, int high)
 {
    if(high-low<=1)
    return 0;
    int pivpos = partition( low, high);
    int lc=quickSort(low, pivpos);
    int rc=quickSort(pivpos + 1, high);
    return lc+rc+high - low - 1 ;
    
  }
int main()
{       
    FILE *fp;
	fp=fopen("quicksort.txt","r");
    int p;    
    for(int i = 0;i<n;i++)
        fscanf(fp,"%d",&arr[i]);
    fclose(fp);
    int count=quickSort(0, n);
    printf("%d\n",count);
    getch();
    return 0;
}
