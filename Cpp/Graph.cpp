#include <iostream>
using namespace std;


struct AdjacentNode{
	int data;
	AdjacentNode* next;
};


struct AdjacentList{
	struct AdjacentNode* head;
};

class Graph
{
	private:
		int V;
		AdjacentList* array;

	public:
		Graph(int V)
		{
			this->V = V;
			array = new AdjacentList[V];		 
			for (int i = 0; i < V; ++i)
				array[i].head = NULL;  	
		}

		AdjacentNode* newAdjListNode(int data)
		{
			AdjacentNode* newNode = new AdjacentNode;
			newNode->data = data;
			newNode->next = NULL;
			return newNode;
		}

		/*
		 * Add Edge to Graph
		 */ 
		void addEdge(int src, int dest)
		{
			AdjacentNode* newNode = newAdjListNode(dest);
			newNode->next = array[src].head;
			array[src].head = newNode;
			newNode = newAdjListNode(src);
			newNode->next = array[dest].head;
			array[dest].head = newNode;
		}

		void printGraph()
		{
			int v;
			for (v = 0; v < V; ++v)
			{
				AdjacentNode* tmp = array[v].head; 
				cout<<"\n Adjacency list of vertex " << v <<"\n head";
				while (tmp)
				{
					cout<<"-> "<<tmp->data;
					tmp = tmp->next;
				}
				cout<<endl;
			}
		}
};

int main(){

	Graph gh(5);
	gh.addEdge(0, 1);
	gh.addEdge(0, 4);
	gh.addEdge(1, 2);
	gh.addEdge(1, 3);
	gh.addEdge(1, 4);
	gh.addEdge(2, 3);
	gh.addEdge(3, 4);

	// print the adjacency list representation of the above graph
	gh.printGraph();

	return 0;
}
