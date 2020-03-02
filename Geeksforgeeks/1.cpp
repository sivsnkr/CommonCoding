#include<bits/stdc++.h>
using namespace std;

void dfs(int parent, int src, vector<unordered_set<int>> &nodes, int edgenumber, int &count,int level, vector<bool> &visit)
{
	if(level == edgenumber-1)
	{
		if(nodes[src].find(parent) != nodes[src].end())
			count++;
		return;
	}

	visit[src] = true;

	unordered_set<int>::iterator it;
	for(it = nodes[src].begin(); it != nodes[src].end(); it++)
	{
		if(!visit[*it])
			dfs(parent, *it, nodes, edgenumber, count, level+1,visit);
	}
	if(level != 1)
		visit[src] = false;
}

int main()
{
	int n = 5,edge = 6,edgenumber = 3;
	vector<unordered_set<int>> nodes(n);

	int i;
	for(i = 0; i < edge; i++)
	{
		int src,dest;
		cin>>src>>dest;

		nodes[src].insert(dest);
		nodes[dest].insert(src);
	}

	int count = 0;
	vector<bool> visit(n, false);
	for(i = 0; i < n-(edgenumber-1); i++)
	{
		// parent src nodes edgenumber count level
		dfs(i, i, nodes, edgenumber, count, 0, visit);
		visit.assign(n,false);
		visit[i] = true;
	}

	cout<<count<<endl;
}