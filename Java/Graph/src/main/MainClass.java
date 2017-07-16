package main;

import java.util.Scanner;

import adjacencylist.AdjacencyList;
import adjacencymatrix.AdjacencyMatrix;

public class MainClass {

	public static void main(String[] args){
		
		AdjacencyList adjacencyList = new AdjacencyList();
		AdjacencyMatrix adjacencyMatrix = new AdjacencyMatrix();
		
		Scanner scanner = new Scanner(System.in);

		System.out.println("Enter the no of nodes: ");
		int nodes = scanner.nextInt();
		System.out.println("Enter the no of edges: ");
		int edges = scanner.nextInt();
		
		adjacencyList.printAdjacencyList(nodes, edges);
		adjacencyMatrix.createAdjacencyMatrix(nodes, edges);
	}
}
