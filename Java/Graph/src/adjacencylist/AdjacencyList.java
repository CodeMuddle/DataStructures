package adjacencylist;

import java.util.LinkedList;
import java.util.Scanner;

public class AdjacencyList {

	static LinkedList <Integer> adj[];

	public static void main(String[] main){

		int x, y, nodes, edges;

		Scanner scanner = new Scanner(System.in);

		nodes = scanner.nextInt();
		edges = scanner.nextInt();

		adj = new LinkedList[10];

		for(int i = 0; i < 10; ++i){
			adj[i] = new LinkedList<Integer>();
		}

		for(int i = 0; i < edges; ++i){
			x = scanner.nextInt();
			y = scanner.nextInt();

			//all the elements connected to x are added to it
			adj[x].add(y);	
		}

		for(int i = 1; i <=nodes; ++i){
			System.out.println("Adjacent list for node " + i + "is :");
			for(int j = 0; j < adj[i].size(); ++j){
				if(j == adj[i].size() -1){
					System.out.println(adj[i].get(j));
				} else {
					System.out.println(adj[i].get(j) + "--->");
				}
			}
		}
	}	
}
