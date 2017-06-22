import java.io.*;
import java.util.*;
public class soln
{
	static int mat[][]=new int[200][200];
	static int a[]={7,37,59,82,99,115,133,165,188,197};
    public static void main(String[] args) throws Exception 
	{
		Scanner sc = new Scanner(new File("dijkstraData.txt"));
		for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 200; j++) {
                if (i == j) {
                    mat[i][j] = 0;
                } else {
                    mat[i][j] = 99999;
                }
            }
        }
		for (int i = 0; i < 200; i++) 
		{
            String[] s = sc.nextLine().split("\t");
            int k = Integer.parseInt(s[0]);
            for (int j = 1; j < s.length; j++) 
			{
                String[] ls = s[j].split(",");
				int dest=Integer.parseInt(ls[0]) - 1;
				int d=Integer.parseInt(ls[1]);
                mat[k - 1][dest] = d;
				if(mat[k-1][dest]==0)
					mat[k-1][dest]=1000000;
            }
        }
		dijkstra(mat,0);
		
    }
static	int mindist(int distance[], boolean included[])
{
  
   int min = 1000001, pos=0;
  
   for (int v = 0; v < 200; v++){
     if (included[v] == false && distance[v] <= min)
	 {
		 min = distance[v];
		 pos = v;
	 }
   }
   return pos;
   
}
static int printans(int distance[], int n)
{
	for(int i=0;i<9;i++)
			System.out.print(distance[a[i]-1]+",");
	System.out.println(distance[196]);
  
   	return 1;
}
static 	void dijkstra(int graph[][], int start)
{
     int distance[]=new int[200];   
  
     boolean included[]=new boolean[200]; // included[i] will true if vertex i is included in shortest path
  
     // Initialize all distances as INFINITE and included[] as false
     for (int i = 0; i < 200; i++)
	 {distance[i] = 1000001;
		included[i] = false;
	 }
     distance[start] = 0;//distance to itself always 0
  
     // Find shortest path for all vertices
     for (int i = 0; i < 199; i++)
     {
       int u = mindist(distance, included);// Pick the minimum distances vertex from the set of vertices not yet processed
       included[u] = true;
		for (int v = 0; v < 200; v++) // Update distance value of the adjacent vertices of the picked vertex.
	   {
         if ( graph[u][v]!=0 && distance[u] != 1000001&& distance[u]+graph[u][v] < distance[v])//update distance[v]
		 {
			 if(!included[v])
				 distance[v] = distance[u] + graph[u][v];
		 }  
		}
	 }
     printans(distance, 200);

	
}
}