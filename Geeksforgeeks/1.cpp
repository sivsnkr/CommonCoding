#include<bits/stdc++.h>
using namespace std;

int main()
{
	int edge = 5;

	int i; // counter

	vector<tuple<int,int,int>> edges(edge);

	for(i = 0; i < edge; i++)
	{
		int src,dest,weight;
		cin>>src>>dest>>weight;
		edges[i] = {src,dest,weight};
	}

	vector<tuple<int,int,int>> modifiedEdges(edge+4);
	modifiedEdges.assign(edges.begin(),edges.end());

	vector<int> weights(5);
	weights[0] = 0;

	int j;

	for(i = 0; i < 3; i++)
	{
		bool changed = false;
		for(j = 0; j < edge; j++)
		{
			int src = get<0>(modifiedEdges[j]);
			int dest = get<1>(modifiedEdges[j]);
			int weight = get<2>(modifiedEdges[j]);

			if(weights[dest] > weights[src]+weight)
			{
				changed = false;
				weights[dest] = weights[src]+weight;
			}
		}

		if(!changed)
			break;

	}

	for(i = 0; i < edge; i++)
	{
		int src = get<0>(edges[i]);
		int dest = get<1>(edges[i]);
		get<2>(edges[i]) = weights[dest]-weights[src]+ get<2>(edges[i]);
	}

	// now run djiskstra for all vertices as source and store nodes in adjacency list
}