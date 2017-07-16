package adjacencylist;

import java.util.LinkedList;
import java.util.Scanner;

public class AdjacencyList {

	LinkedList <Integer> adj[];

	private LinkedList<Integer>[] createLists(int n){

		adj = new LinkedList[n];

		for(int i = 0; i < adj.length; ++i){
			adj[i] = new LinkedList<Integer>();
		}
		return adj;
	}

	private LinkedList<Integer>[] addInAdjacentList(int edges, int nodes){
		int x, y;

		LinkedList<Integer>[] adj = this.createLists(nodes + 1);

		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the coordinates of edges for adjacent list: ");
		for(int i = 0; i < edges; i++){
			x = scanner.nextInt();
			y = scanner.nextInt();

			adj[x].add(y);
		}

		return adj;
	}

	public void printAdjacencyList(int nodes, int edges){
		this.addInAdjacentList(edges, nodes);
		for(int i = 1; i <=nodes; ++i){
			System.out.println("Adjacent list for node " + i + " is :");
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
