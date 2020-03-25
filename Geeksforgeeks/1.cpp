#include<bits/stdc++.h>
using namespace std;
int main()
{
	int edges = 14, nodes = 9;

	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> graph;

	int i;
	for(i = 0; i < edges; i++)
	{
		int src,dest,weight;
		cin>>src>>dest>>weight;
		graph.push({weight,src,dest});
	}

	vector<bool> visited(nodes,false);
	vector<unordered_set<int>> mst(nodes);
	int nodesCounter = 0;
	while(!graph.empty())
	{
		int src,dest;
		auto top = graph.top();
		src = get<1>(top);
		dest = get<2>(top);

		graph.pop();
		if(!(visited[src]&&visited[dest]))
		{
			mst[src].insert(dest);
		}
		visited[src] = true,visited[dest] = true;
	}

	for(i = 0; i < nodes; i++)
	{
		cout<<i<<" ";
		for(auto j = mst[i].begin(); j != mst[i].end(); j++)
		{
			cout<<*j<<" ";
		}
		cout<<endl;
	}
}