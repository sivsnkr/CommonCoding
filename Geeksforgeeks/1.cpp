#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int noofnodes;
	unordered_set<int> *nodes;
	bool hasCycle = false;
public:
	Graph(int n)
	{
		this->nodes = new unordered_set<int>[n];
		this->noofnodes = n;
	}

	void addEdge(int src, int dest);

	bool isCyclic();
};

void Graph::addEdge(int src, int dest)
{
	nodes[src].insert(dest);
}

bool dfs(int src, unordered_set<int> nodes[], vector<bool> &visited)
{
	if(visited[src])
		return true;

	visited[src] = true;

	unordered_set<int>::iterator it;

	int isCycle = false;

	for(it = nodes[src].begin(); it != nodes[src].end(); it++)
	{
		isCycle = dfs(*it,nodes,visited);
		if(isCycle)
			break;
	}

	return isCycle;
}

bool Graph::isCyclic()
{
	if(hasCycle)
		return hasCycle;

	vector<bool> visited(noofnodes,false);

	return dfs(0,nodes,visited);
}

int main()
{
	int n;
	cin>>n;
	int edge;
	cin>>edge;
	Graph graph(n);

	int i;
	for(i = 0; i < edge; i++){
		int src,dest;
		cin>>src>>dest;
		graph.addEdge(src,dest);
	}

	bool hasCycle = graph.isCyclic();

	if(hasCycle)
		cout<<"True";
	else
		cout<<"False";
	cout<<endl;
}