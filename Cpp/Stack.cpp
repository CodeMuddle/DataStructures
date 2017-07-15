#include<iostream>
using namespace std;

struct Node{
	int value;
	Node *nextNode;
	Node *prevNode;

	Node(int value){
		this->value = value;
		this->nextNode = NULL;
		this->prevNode = NULL;
	}
};

struct Stack{

	Node *root;
	int size;

	Stack(int value){
		size = 0;
		root = new Node(value);
		size++;
	}

	void push(int value){
		cout << "pushing the value to stack..." << endl;
		Node *n = new Node(value);
		n->nextNode = root;
		root = n;
		size++;
	}

	void display(){
		Node *temp = root;
		while(temp!= NULL){
			cout << temp->value << endl;
			temp = temp->nextNode;
		}

	}

	void remove(int value){
		cout<<"removing the value"<< value <<" from stack..." << endl;
		Node *temp = root;
		if(root->value == value){
			root = root->nextNode;
			size--;
			return;
		}
		while(temp->nextNode != NULL){
			Node *tempn = temp->nextNode;
			Node *tempnn = tempn->nextNode;
			if(tempn->value == value){
				delete tempn;
				temp->nextNode = tempnn;
			}
			temp = temp->nextNode;
		}
		size--;
	}

	int pop(){
		cout<<"popping out the values from stack..."<<endl;
		if(root == NULL){
			cout<<"The stack is empty"<<endl;
		}
		Node *temp = root;
		int tempValue = temp->value;
		root = temp->nextNode;
		delete temp;
		size--;
		return tempValue;
	}

	void popAll(){
		cout<<"popping out all values from stack..."<<endl;
		Node *temp = root;
		while(temp!=NULL){
			pop();
			temp = temp->nextNode;
		}
	}

	int getSize(){
		return size;
	}
};

int main(){
	Stack *stack = new Stack(23);
	stack->push(1);
	stack->push(2);
	stack->push(3);
	// cout << "Stack size is : " <<  stack->getSize() << endl;
	stack->display();
	cout << "Stack size after pushing all the numbers is: " << stack->getSize() << endl;
	stack->pop();
	stack->display();
	cout << "Stack size after popping an element is: " << stack->getSize() << endl;
	stack->remove(2);
	stack->display();
	cout << "Stack size after removing 2 is: " << stack->getSize() << endl;
	stack->popAll();
	stack->display();
	cout << "Stack size after popping out all the elements is: " << stack->getSize() << endl;
	delete stack;
}




