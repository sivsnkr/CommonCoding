// C++ program to find root which gives minimum height to tree 
#include <bits/stdc++.h> 
using namespace std; 

// This class represents a undirected graph using adjacency list 
// representation 
class Graph 
{ 
public: 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency lists 
	list<int> *adj; 

	// Vector which stores degree of all vertices 
	vector<int> degree; 

	Graph(int V);		 // Constructor 
	void addEdge(int v, int w); // To add an edge 

	// function to get roots which give minimum height 
	vector<int> rootForMinimumHeight(); 
}; 

// Constructor of graph, initializes adjacency list and 
// degree vector 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
	for (int i = 0; i < V; i++) 
		degree.push_back(0); 
} 

// addEdge method adds vertex to adjacency list and increases 
// degree by 1 
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list 
	adj[w].push_back(v); // Add v to w’s list 
	degree[v]++;		 // increment degree of v by 1 
	degree[w]++;		 // increment degree of w by 1 
} 

// Method to return roots which gives minimum height to tree 
vector<int> Graph::rootForMinimumHeight() 
{ 
	queue<int> q; 

	// first enqueue all leaf nodes in queue 
	for (int i = 0; i < V; i++) 
		if (degree[i] == 1) 
			q.push(i); 

	// loop untill total vertex remains less than 2 
	while (V > 2) 
	{ 
		for (int i = 0; i < q.size(); i++) 
		{ 
			int t = q.front(); 
			q.pop(); 
			V--; 

			// for each neighbour, decrease its degree and 
			// if it become leaf, insert into queue 
			for (auto j = adj[t].begin(); j != adj[t].end(); j++) 
			{ 
				degree[*j]--; 
				if (degree[*j] == 1) 
					q.push(*j); 
			} 
		} 
	} 

	// copying the result from queue to result vector 
	vector<int> res; 
	while (!q.empty()) 
	{ 
		res.push_back(q.front()); 
		q.pop(); 
	} 
	return res; 
} 

// Driver code to test above methods 
int main() 
{ 
	Graph g(7); 
	g.addEdge(0, 1); 
	g.addEdge(1, 2); 
	g.addEdge(2, 3); 
	g.addEdge(3, 4); 
	g.addEdge(4, 5); 
	g.addEdge(5, 6);
	vector<int> res = g.rootForMinimumHeight(); 
	for (int i = 0; i < res.size(); i++) 
		cout << res[i] << " "; 
	cout << endl; 
} 
