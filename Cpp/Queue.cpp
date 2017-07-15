#include<iostream>
using namespace std;

struct Node{
	int value;
	Node* prevNode;
	Node* nextNode;

	Node(int value){
		this->value = value;
		this->prevNode = NULL;
		this->nextNode = NULL;
	}
};

struct Queue{

	Node *root;
	int size;

	Queue(int value){
		size = 0;
		root = new Node(value);
		size ++;
	}

	public:
	void enqueue(int value){
		Node *n = new Node(value);
		n->value = value;
		n->nextNode = root;
		root = n;
		size++;
	}

	public:
	void dequeue(){
		Node *temp = root;
		Node *curr;

		// if single node
		if(root->nextNode == NULL){
			root = NULL;
			return;
		}

		while(temp->nextNode!=NULL){
			curr = temp;
			temp = temp->nextNode;
		}
		curr->nextNode = NULL;
		delete temp;
		size--;
	}

	public:
	void display(){
		Node *temp = root;
		while(temp!=NULL){
			cout << temp->value << endl;
			temp = temp->nextNode;
		}
	}

	int getSize(){
		return size;
	}
};

int main(){
	Queue queue(500);
	queue.enqueue(400);
	queue.enqueue(300);
	queue.enqueue(200);
	cout << "before dequeue" << endl;
	queue.display();
	cout << "The queue size after enqueuing all the numbers is " << queue.getSize() << endl;

	queue.dequeue();
	cout << "after dequeue" << endl;
	queue.display();
	cout <<"The queue size after dequeing a number is " << queue.getSize() << endl;
}
