#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<set<pair<int,int>>> nodes(n);
	int edge;
	cin>>edge;

	int i;
	for(i = 0; i < edge; i++)
	{
		int src,dest,weight;
		cin>>src>>dest>>weight;
		nodes[src].insert(make_pair(dest,weight));
	}

	vector<int> distance(n,INT_MAX);
	distance[0] = 0;

	vector<bool> allSelected(n,false);
	allSelected[0] = 1;

	int s;
	s = 0;
	set<pair<int,int>>::iterator it;

	while(1)
	{		for(it = nodes[s].begin(); it != nodes[s].end(); it++)
		{
			if(distance[s]+(*it).second < distance[(*it).first])
			{
				distance[(*it).first] = distance[s]+(*it).second;
			}
		}

		int min = INT_MAX;

		int j;
		s = -1;
		for(j = 0; j < n; j++)
		{
			if(!allSelected[j]&&distance[j]<min)
			{
				min = distance[j];
				s = j;
			}
		}

		if(s == -1)
			break;
		allSelected[s] = 1;
	}

	for(i = 0; i < n; i++)
	{
		cout<<"distance from src to "<<i<<" is "<<distance[i]<<endl;
	}
}