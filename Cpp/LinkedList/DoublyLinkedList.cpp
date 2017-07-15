#include<iostream>
using namespace std;

struct Node{
	int value; 
	Node *prevNode;
	Node *nextNode;

	Node(int value){
		this->value = value;
		this->prevNode = NULL;
		this->nextNode = NULL;
	}
};

class DoublyLinkedList{
	public:
		Node *root; 
		Node *temp;

		DoublyLinkedList(int value){
			root = new Node(value);
			temp = root;
		}

		void insertAtBeginning(int newValue){
			Node *n = new Node(newValue);
			temp->prevNode = n;
			n->nextNode = temp;
			temp = n;
		}

		void insertAtEnd(int newValue){
			Node *n = new Node(newValue);
			temp->nextNode = n; 
			n->prevNode = temp;
			temp = n;
		}

		void displayInReverseOrder(){
			Node *temp = root;
			while(temp->nextNode != NULL){
				temp = temp->nextNode;
			}  
			while(temp != NULL){
				cout << temp->value << endl;
				temp = temp->prevNode;
			}
		}

		void display(){
			Node *temp = root;
			while(temp->prevNode != NULL){
				temp = temp->prevNode;
			}
			while(temp != NULL){
				cout << temp->value << endl;
				temp = temp->nextNode;
			}

		}

		bool search(int n){
			Node *temp = root;
			while (temp->prevNode != NULL){
				temp = temp->prevNode;
			}
			while(temp !=NULL){
				if(temp->value == n){
					return true;
				}
				temp = temp->nextNode;
			}
			return false;

		}

		bool removeValue(int n){
			Node *temp = root;
			while(temp->prevNode != NULL){
				temp = temp->prevNode;
			}
			while(temp != NULL){
				if(temp->value == n){
					delete temp;
				}
				temp = temp->nextNode;
			}
		}

};


int main(){
	DoublyLinkedList dl(500);
	dl.insertAtBeginning(300);
	dl.insertAtBeginning(200);
	cout << "The elements which are inserted from beginning are " << endl;
	dl.display();
	cout << "The elements inserted from beginning when printed in reverse order are " << endl;
	dl.displayInReverseOrder();
	dl.insertAtEnd(100);
	dl.insertAtEnd(50);
	dl.insertAtEnd(25);
	cout << "The elements inserted from end are " << endl;
	dl.display();
	cout << "Searching 200 in the list " <<  dl.search(200) << endl;
	cout << "Removing 200 from the list " << dl.removeValue(200) << endl;
	cout << "The elements after removal of 200 is " << endl;
	dl.display();
	cout << "Searching 200 again in the list " << dl.search(200);

}
