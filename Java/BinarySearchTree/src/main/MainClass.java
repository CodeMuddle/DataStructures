package main;

import binarysearch.BinarySearchTree;

public class MainClass {

	public static void main(String[] args) {
		
		BinarySearchTree binarySearchTree = BinarySearchTree.createBinarySearchTree(500);
		binarySearchTree.insert(50);
		binarySearchTree.insert(600);
		binarySearchTree.insert(10);
		binarySearchTree.insert(100);
		binarySearchTree.insert(2990);
		binarySearchTree.insert(700);
		binarySearchTree.insert(5);
		
		int level = 3;
		
		System.out.println("The elements in binarySearchTree are : ");
		binarySearchTree.display(binarySearchTree);
		
		System.out.println("Search result : " + binarySearchTree.find(100, binarySearchTree));

		System.out.println("Displaying only the element at level " + level);
		binarySearchTree.displayLevel(level, binarySearchTree);
	}

}
