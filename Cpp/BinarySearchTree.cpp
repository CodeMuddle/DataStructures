#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node*right;

	Node(int value){
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};


class BinarySearchTree{

	public:
		Node *root;

		BinarySearchTree(int value){
			root = new Node(value);
		}

		void insert(int value){
			Node *newNode = new Node(value);
			Node *current = root;
			Node *parent = NULL;
			while(true){
				parent = current;
				if(value < current->data){
					current = current->left;
					if(current == NULL){
						parent->left = newNode;
						return;
					}
				} else {
					current = current->right;
					if(current == NULL){
						parent->right = newNode;
						return;
					}
				}
			}
		}

		void display(Node* root){
			if(root != NULL){
				display(root->left);
				cout << root->data << endl;;
				display(root->right);
			}
		}

		bool find(int value){
			Node* current = root;
			while(current != NULL){
				if(current->data == value){
					return true;
				}else if(current->data > value){
					current = current->left;
				}else{
					current = current->right;
				}
			}
			return false;
		}

		bool deleteValue(int value){
			Node* parent = root;
			Node* current = root;
			bool isLeftChild = false;
			while(current->data != value){
				parent = current;
				if(current->data > value){
					isLeftChild = true;
					current = current->left;
				}else{
					isLeftChild = false;
					current = current->right;
				}
				if(current == NULL){
					return false;
				}
			}
			//after the node has been found, three cases may arise
			//Case 1: if node to be deleted has no children
			if(current->left == NULL && current->right == NULL){
				if(current == root){
					root = NULL;
				}
				if(isLeftChild == true){
					parent->left = NULL;
				}else{
					parent->right = NULL;
				}
			}
			//Case 2 : if node to be deleted has only one child
			else if(current->right == NULL){
				if(current == root){
					root = current->left;
				}else if(isLeftChild){
					parent->left = current->left;
				}else{
					parent->right = current->left;
				}
			}
			else if(current->left == NULL){
				if(current == root){
					root = current->right;
				}else if(isLeftChild){
					parent->left = current->right;
				}else{
					parent->right = current->right;
				}
			}else if(current->left != NULL && current->right != NULL){

				//now we have found the minimum element in the right sub tree
				Node *successor	 = getSuccessor(current);
				if(current == root){
					root = successor;
				}else if(isLeftChild){
					parent->left = successor;
				}else{
					parent->right = successor;
				}			
				successor->left = current->left;
			}

			return true;		
		}

		Node* getSuccessor(Node* deleteNode){
			Node* successsor = NULL;
			Node* successsorParent = NULL;
			Node* current = deleteNode->right;
			while(current != NULL){
				successsorParent = successsor;
				successsor = current;
				current = current->left;
			}
			return successsor;
		}
};


int main(){
	BinarySearchTree bst(55);
	bst.insert(33);
	bst.insert(60);
	bst.insert(18);
	bst.insert(17);
	bst.insert(65);
	bst.insert(85);
	cout << "Before deleting any elements " << endl;
	bst.display(bst.root);
	cout <<"Check if the element 33 is present " << endl;
	cout << bst.find(33) << endl;
	cout << "After deleting 33" << endl;
	cout << "Delete status is " << bst.deleteValue(33) << endl;
	cout << "The elements remaining are " << endl;
	bst.display(bst.root);
	cout << "Check if the element 33 is present " << endl;
	cout << bst.find(33);

}
