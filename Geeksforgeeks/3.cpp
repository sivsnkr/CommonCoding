#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nodes = 9,edges = 14;
	vector<vector<pair<int,int>>> graph(nodes);

	int i;
	for(i = 0; i < edges; i++)
	{
		int src,dest,weight;
		cin>>src>>dest>>weight;
		graph[src].push_back({dest,weight});
	}

	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> included(edges);

	vector<unordered_set<int>> mst(nodes);
	// find min edge

	tuple<int,int,int> minEdge;
	int min = INT_MAX;
	for(i = 0; i < nodes; i++)
	{
		int size = graph[i].size();
		for(int j = 0; j < size; j++)
		{
			if(graph[i][j].second < min)
			{
				min = graph[i][j].second;
				minEdge = {graph[i][j].second,i,graph[i][j].first};
			}
		}
	}

	mst[get<1>(minEdge)].insert(get<2>(minEdge));
	int counter = 1;
	while(counter < nodes)
	{
		// insert all the new edges to priority queue
		// all the edges connected to src
		int size = graph[get<1>(minEdge)].size();
		for(i = 0; i < size; i++)
		{
			included.push({graph[get<1>(minEdge)][i].second,get<1>(minEdge),graph[get<1>(minEdge)][i].first})
		}

		// all the edge from dest
		size = graph[get<2>(minEdge)].size();
		for(i = 0; i < size; i++)
		{
			included.push({graph[get<2>(minEdge)][i].second,get<2>(minEdge),graph[get<2>(minEdge)][i].first})
		}

		minEdge = included.top();
		included.pop();
		mst[get<1>(minEdge)].insert(get<2>(minEdge));
		counter++;
	}

	int l = 0;
	for(auto i : mst)
	{
		cout<<l<<" ";
		int size = mst[i].size();
		for(int j = 0; j < size; j++)
		{
			cout<<*j<<endl;
		}
		cout<<endl;
	}
}