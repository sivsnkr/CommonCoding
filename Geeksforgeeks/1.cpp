#include<bits/stdc++.h>
using namespace std;

int sidha = 0,ulta = 0;

void dfs(int src, vector<pair<unordered_set<int>,unordered_set<int>>> &nodes,vector<int> &ok, vector<int> &rev, vector<bool> &visit){
	visit[src] = true;

	unordered_set<int>::iterator it;

	for(it = nodes[src].first.begin(); it != nodes[src].first.end(); it++){
		if(!visit[*it]){
			sidha++;
			if(ok[*it] != 0)
				ok[*it] = min(sidha,ok[*it]);
			else
				ok[*it] = sidha;
			rev[*it] = ulta;
			dfs(*it,nodes,ok,rev,visit);
		}
	}


	for(it = nodes[src].second.begin(); it != nodes[src].second.end(); it++){
		if(!visit[*it]){
			ulta++;
			if(rev[*it] != 0)
				rev[*it] = min(ulta,rev[*it]);
			else
				rev[*it] = ulta;
			ok[*it] = sidha;
			dfs(*it,nodes,ok,rev,visit);
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<pair<unordered_set<int>,unordered_set<int>>> nodes(n);

	int i;
	for(i = 0; i < n-1; i++){
		int src,dest;
		cin>>src>>dest;

		nodes[src].first.insert(dest);
		nodes[dest].second.insert(src);
	}

	vector<int> ok(n,0),rev(n,0);
	vector<bool> visit(n,false);

	dfs(0,nodes,ok,rev,visit);

	int m = INT_MAX,node = 0;
	for(i = 0; i < n; i++){
		int res = ok[i]+ulta-rev[i];

		if(res < m){
			m = res;
			node = i;
		}
	}

	cout<<node<<endl;
	cout<<m<<endl;
}