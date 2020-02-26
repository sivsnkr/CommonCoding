#include<bits/stdc++.h>
using namespace std;

int dsrc,ddest,totalSum;
int minSum = INT_MAX;

int dfs(int src,vector<unordered_set<int>> &nodes, vector<bool> &visit, vector<int> &weight, bool getNodes){
	if(nodes[src].size()==0)
		return weight[src];

	int sum = weight[src];
	visit[src] = true;

	unordered_set<int>::iterator it;

	for(it = nodes[src].begin(); it != nodes[src].end(); it++){
		int sum1 = 0;
		if(!visit[*it]){
			sum1=dfs(*it,nodes,visit,weight,getNodes);
			sum+=sum1;
			if(getNodes){
				int bsum = totalSum-sum1;
				if(abs(bsum-sum1)<minSum){
					minSum = abs(bsum-sum1);
					dsrc = src;ddest = *it;
				}
			}
		}
	}

	return sum;
}

int main()
{
	int n;
	cin>>n;

	int i;

	vector<unordered_set<int>> nodes(n);
	vector<int> weight(n);
	for(i = 0; i < n-1; i++){
		int src,dest;
		cin>>src>>dest;

		nodes[src].insert(dest);
	}

	cout<<"Enter the weights of nodes"<<endl;

	for(i = 0; i < n; i++){
		cin>>weight[i];
	}

	vector<bool> visit(n,false);

	totalSum = dfs(0,nodes,visit,weight,false);

	visit.assign(n,false);
	
	dfs(0,nodes,visit,weight,true);

	cout<<dsrc<<" "<<ddest<<endl;}