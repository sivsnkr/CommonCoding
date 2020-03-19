#include<bits/stdc++.h>
using namespace std;

int min_no = INT_MAX;
void find_min_ans(vector<vector<pair<bool,int>>> &graph, vector<bool> &visited, int src, int dest, int no)
{
	if(visited[src])
		return;

	if(src == dest)
	{
		if(no < min_no)
		{
			min_no = no;
		}
		return;
	}

	visited[src] = 1;

	vector<pair<bool,int>>::iterator it;

	for(it = graph[src].begin(); it != graph[src].end(); it++)
	{
		if(!visited[it->second])
		{
			if(it->first == 1)
				find_min_ans(graph,visited,it->second, dest, no);
			else
				find_min_ans(graph,visited,it->second, dest, no+1);
		}
	}
}

int main()
{
	int edge = 7,nodes = 7;
	vector<vector<pair<bool,int>>> graph(nodes);

	int i;
	for(i = 0; i < edge; i++)
	{
		int src,dest;
		cin>>src>>dest;
		graph[src].push_back({1,dest});
		graph[dest].push_back({0,src});
	}

	vector<bool> visited(nodes,false);
	find_min_ans(graph,visited,0,6,0);
	cout<<min_no<<endl;
}