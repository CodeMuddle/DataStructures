#include<iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node *root;

    LinkedList(int value){
        root = new Node(value);
    }
    
    void add(int value){
        cout << "adding.."<<endl;
        Node *n = new Node(value);
        n->next = root;
        root = n;
    }
    
    void display(){
        Node *temp = root;
        while(temp->next != NULL){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    
    bool search(int value){
        Node *temp = root;
        while(temp->next!=NULL){
            if(temp->value == value){
        	    return true;
            }
            temp=temp->next;
        }
        return false;
    }
    
    void removeAll(){
        Node *temp = root;
        while(temp->next!= NULL){
            root = temp->next;
            temp = temp->next;
            }
            cout<<"Removing all nodes"<<endl;
    }
    
    void remove(int value){
        Node *temp = root;
        /*
            if root has the value,
            root's "next" is the new root
        */
        if(root->value == value){
            root = root->next;
            return;
        }
    
        //else
        /*
            We check for the value between two nodes:
            prev->current->next
            so that we can remove "Current"
            and point "prev" to "next"
        */
        while(temp->next != NULL){
            Node *tempn = temp->next;
            Node *tempnn = tempn->next;
            if(tempn->value == value){
                delete tempn;
                temp->next = tempnn;
            }
    
            temp = temp->next;
        }
    }

    void insert(int data, int n){
        Node* temp1 = new Node(data);
        if(n == 1){
            temp1->next = root;
            root = temp1;
            return;
         }
         Node* temp2 = root;
         for(int i =0; i<n-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

    void deleteNode(int n){
        Node * temp1 = root;
        if(n ==1){
            root = temp1->next;
            delete temp1;
            return;
        }
        for(int i=0; i<n-2 ;i++){
            temp1 = temp1->next;
            Node *temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
            }
        }
};

int main(){
    
    LinkedList l(100);
    l.insert(400,1);
    l.insert(20,2);
    l.insert(30,3);
    l.add(-99);
    l.add(200);
    l.add(300);
    l.add(500);
    l.add(600);
    l.add(700);
    l.add(800);
    cout << "before...." << endl;
    l.display();
    bool found= l.search(200);
    cout<<"The search status is "<<found<<endl;
    cout<<"after.."<<endl;
    l.remove(700);
    cout<<"The remaining nodes after removing a node by its value are"<<endl;
    l.display();
    l.deleteNode(3);
    cout<<"The remaining nodes after removing a node by its location are"<<endl;
    l.display();
    l.removeAll();
    found= l.search(200);
    cout<<"The search status after removing all nodes is "<<found<<endl;

}
