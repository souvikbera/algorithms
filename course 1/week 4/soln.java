import java.util.*;
import java.io.*;
public class soln {
	int min = 201;
	Map<Integer,List<Integer>> adjacencylist;
	List<Integer> vertexlist;
	
	void initialise() 
	{
		adjacencylist = new HashMap<Integer,List<Integer>>();
		vertexlist = new ArrayList<Integer>();
		try 
		{
			File input=new File("kargerMinCut.txt");
			Scanner scanner=new Scanner(input);
		    while(scanner.hasNextLine()) 
			{
			   String s = scanner.nextLine();
			   String num[] = s.split("\\t");//each element is considered separated by horizontal tab
			   vertexlist.add(Integer.parseInt(num[0]));
			   List<Integer> adj = new ArrayList<Integer>();
			   for (int i = 1; i < num.length; i++)
				   adj.add(Integer.parseInt(num[i]));
			   adjacencylist.put(Integer.parseInt(num[0]), adj);
			   
		    }
		    
		}
		catch (Exception e) 
			{
			  e.printStackTrace();
			}
	}
	void findmincut() 
	{
		while(adjacencylist.size() > 2) 
		{
			int startpos = vertexlist.get(new Random().nextInt(vertexlist.size()));//start vertex of random edge
			List<Integer> v = adjacencylist.get(startpos);
			int endpos = v.get(new Random().nextInt(v.size()));//end vertex of a random edge
			List<Integer> d = adjacencylist.get(endpos);
			for (Iterator<Integer> iterator = d.iterator(); iterator.hasNext();) 
			{
				int auxIndex = iterator.next();
				List<Integer> aux = adjacencylist.get(auxIndex);
				while(aux.remove(new Integer(endpos)));//Remove end vertex from vertex list for each aux vertex
				aux.add(new Integer(startpos));
				v.add(auxIndex);
			}
			adjacencylist.remove(endpos);// Remove end vertex list from adjacency list
			vertexlist.remove(new Integer(endpos));
			while(v.remove(new Integer(startpos)));//remove self loops
		}
		if(min>adjacencylist.get(vertexlist.get(0)).size())
			min=adjacencylist.get(vertexlist.get(0)).size();
	}	
	public static void main(String args[]) 
	{
		soln obj = new soln();
				for (int i = 1; i <=40000; i++)//0(n^2) where n=200 
			    {
				  obj.initialise();
				  obj.findmincut();
				  System.out.println("When i= " + i + " mincut value= " + obj.min);
			    }
		  System.out.println("Final Value="+obj.min);
	}
}