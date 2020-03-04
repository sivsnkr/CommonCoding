#include<bits/stdc++.h>
using namespace std;

int main()
{
	int noofvertices = 0;

	int n;
	cout<<"Enter the no of edges: ";
	cin>>n;

	int i;

	vector<tuple<int,int,int>> edges(n);
	for(i = 0; i < n; i++)
	{
		int src,dest;
		int weight;
		cin>>src>>dest>>weight;
		edges[i] = make_tuple(src,dest,weight);
		if(noofvertices<dest){
			noofvertices = dest;
		}
	}

	vector<int> shortestPaths(noofvertices+1,INT_MAX);
	shortestPaths[0] = 0;

	for(i = 0; i <= noofvertices; i++)
	{

		bool  changed = false;
		for(int j = 0; j < n; j++)
		{
			int src = get<0>(edges[j]);
			int dest = get<1>(edges[j]);
			int weight = get<2>(edges[j]);

			if(shortestPaths[src]+weight < shortestPaths[dest])
			{
				shortestPaths[dest] = shortestPaths[src]+weight;
				changed = true; 
			}
		}

		if(!changed)
			break;
	}

	for(i = 0; i <= noofvertices; i++)
	{
		cout<<"Min path from 0 to "<<i<<" is "<<shortestPaths[i]<<endl;
	}
}