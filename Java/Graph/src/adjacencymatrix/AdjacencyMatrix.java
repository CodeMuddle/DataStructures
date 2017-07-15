package adjacencymatrix;

import java.util.Scanner;

public class AdjacencyMatrix {

	static boolean[][] A = new boolean[10][10];

	public static void initialize(int x, int y){
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				//initialize every element of matrix to false
				A[i][j] = false;
			}
		}
	}

	public static void main(String[] args){
		int x, y, nodes, edges = 0;
		initialize(10, 10);
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the number of nodes:");
		nodes = scanner.nextInt();
		System.out.println("Enter the number of edges:");
		edges = scanner.nextInt();

		for(int i = 0; i < edges; i++){
			x = scanner.nextInt();
			y = scanner.nextInt();
			A[x][y] = true;	
		}

		if(A[3][4] == true){
			System.out.println("There is an edge between 3 and 4");
		} else{
			System.out.println("There is no edge between 3 and 4");
		}
	}
}
