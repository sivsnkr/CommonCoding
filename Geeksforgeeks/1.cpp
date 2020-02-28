#include <bits/stdc++.h>
using namespace std;

int bfs(vector<set<int>> &nodes, int size){
	queue<pair<int,int>> q;
	q.push({0,0});

	vector<bool> visit(size,false);
	visit[0] = true;
	while(!q.empty()){
		int curnode = q.front().first;

		int level = q.front().second;

		q.pop();

		set<int>::iterator it;

		for(it = nodes[curnode].begin(); it != nodes[curnode].end(); it++){
			if(*it == size - 1)
				return level+1;
			else{
				visit[*it] = true;
				q.push({*it,level+1});
			}
		}
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;

	vector<int> elements(n);

	int i;
	for(i = 0; i < n; i++){
		cin>>elements[i];
	}

	unordered_map<int,set<int>> connectingNodes(n);

	unordered_map<int,set<int>>::iterator it;
	set<int>::iterator it1;

	set<int> temp;

	for(i = 0; i < n; i++){
		if(connectingNodes.find(elements[i]) == connectingNodes.end()){
			temp.insert(i);
			connectingNodes.insert({elements[i],temp});
			temp.clear();
		}else{
			connectingNodes[elements[i]].insert(i);
		}
	}

	vector<set<int>> nodes(n);

	for(it = connectingNodes.begin(); it != connectingNodes.end(); it++){
		int index = (*(*it).second.begin());

		if(index - 1 >= 0){
			nodes[index].insert(index-1);
		}

		if(index + 1 < n){
			nodes[index].insert(index+1);
		}

		it1 = (*it).second.begin();
		it1++;

		for(it1 = it1; it1 != (*it).second.end(); it1++){
			nodes[index].insert(*it1);
		}
	}


	for(i = 0; i < n; i++){
		if(nodes[i].size() == 0){
			if(i - 1 >= 0){
				nodes[i].insert(i-1);
			}

			if(i + 1 < n){
				nodes[i].insert(i+1);
			}
		}
	}

	int res = bfs(nodes,n);
	cout<<res<<endl;
}