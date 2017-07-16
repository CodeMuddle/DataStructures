package adjacencymatrix;

import java.util.Scanner;

public class AdjacencyMatrix {

	boolean[][] A = new boolean[10][10];

	public void initialize(int x, int y){
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				//initialize every element of matrix to false
				A[i][j] = false;
			}
		}
	}

	public void createAdjacencyMatrix(int nodes, int edges){
		int x, y;
		initialize(nodes + 1, nodes + 1);
		Scanner scanner = new Scanner(System.in);
	
		System.out.println("Enter the coordinates of edges for adjacent matrix: ");
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
