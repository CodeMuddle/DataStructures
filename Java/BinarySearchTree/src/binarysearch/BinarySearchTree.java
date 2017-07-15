package binarysearch;

/**
 * 
 * Creates BinarySearchTree.
 * Insert, display and find the elements in the tree.
 *
 */

public class BinarySearchTree {

	private int data;
	private BinarySearchTree left;
	private BinarySearchTree right;

	private BinarySearchTree(){}

	private BinarySearchTree(int value){
		this.data = value;
	}

	/**
	 * 
	 * Creates binarySearchTree without creating new object of the class
	 * @param value 
	 * 			root node of the binary tree
	 * @return BinarySearchTree
	 *          tree with only root node
	 * 
	 */

	public static BinarySearchTree createBinarySearchTree(int value){
		BinarySearchTree root = new BinarySearchTree(value);
		return root;
	}

	/**
	 * 
	 * Inserts new data in the tree
	 * @param value
	 * 
	 */

	public void insert(int value){
		//the left node of the tree
		if(value < data) {
			if(left == null){
				//creates the left node
				left = new BinarySearchTree(value);
			}
			else {
				//the existing left node acts as the root. So, this inserts new value at the left of the
				//new root.
				left.insert(value);
			}
		}
		if(value > data) {
			//the right node of the tree
			if(right == null){
				//creates the right node
				right = new BinarySearchTree(value);
			}
			else {
				//the existing right node acts as the root. So, this inserts new value at the right of the 
				//new root
				right.insert(value);
			}
		}
	}

	/**
	 * 
	 * Displays numbers of the tree
	 * @param root 
	 * 			the root node of the tree
	 * 
	 */

	public void display(BinarySearchTree root){
		if(root != null){
			//goes towards the far left
			display(root.left);
			//prints the data at the leftmost end
			System.out.println(root.data);
			//checks the data at the right of the leftmost end, comes back to the second last element,
			//checks its right part and so on.
			display(root.right);
		}
	}

	/**
	 * 
	 * Displays numbers only at the specific level
	 * @param level
	 * @param root
	 * 
	 */

	public void displayLevel(int level, BinarySearchTree root){

		//there are no element
		if (root == null){
			return;

			//only the root is present
		} else if(level == 1){
			System.out.println(root.data);

		} else if (level > 1){
			//repeat this until the level is one. Then, print its leftmost element.
			displayLevel(level-1, root.left);
			//print the righmost element after level is one.
			displayLevel(level-1, root.right);
		}
	}

	/**
	 * 
	 * Search the number in the tree
	 * @param element
	 * @param root
	 * @return
	 */

	public boolean find(int element, BinarySearchTree root){

		BinarySearchTree current = root;

		while(current != null){
			//root contains the number being searched
			if(current.data == element){
				return true;
			} else {
				//the left part of the tree contains the number
				if(element < current.data){
					current = current.left;
					//the right part contains the number
				} else if(element > current.data){
					current = current.right;
				}
			}
		}
		return false;
	}
}

