#include<bits/stdc++.h>
using namespace std;

void bfs(int src,vector<unordered_set<int>> &nodes, unordered_map<int,int> &parent, vector<bool> &visited,bool backward, queue<int> &q){
	unordered_set<int>::iterator it;
	visited[src] = true;

	for(it = nodes[src].begin(); it != nodes[src].end(); it++){
		if(!visited[*it]){
			visited[*it] = true;

			if(backward){
				parent.insert({*it,src});
			}else{
				parent.insert({src,*it});
			}

			visited[*it] = true;
			q.push(*it);
		}
	}
}

int main(){
	int src = 0,dest = 10;
	vector<unordered_set<int>> nodes(50);

	int i;
	cin>>i;

	for(int j = 0; j < i; j++){
		int s,d;
		cin>>s>>d;
		nodes[s].insert(d);
		nodes[d].insert(s);
	}

	queue<int> q,q1;
	q.push(src);
	q1.push(dest);

	unordered_map<int,int> parent;
	parent.insert({src,-1});
	vector<bool> visited(11),visited1(11);

	int clasedvertex = -1;

	while(!q.empty() && ! q1.empty()){
		int src1 = q.front();
		q.pop();
		int src2 = q1.front();
		q1.pop();

		bfs(src2,nodes,parent,visited1,true,q1);
		bfs(src1,nodes,parent,visited,false,q);

		int i = 0;
		bool found = false;
		for(i = 0; i < 11; i++){
			if(visited[i]==visited1[i]){
				found = true;
				break;
			}
		}

		if(found)
			clasedvertex = i;
	}

	cout<<"classed "<<clasedvertex<<endl;

	if(clasedvertex!=-1){
		// print the path
		cout<<dest;
		int p = parent[dest];
		cout<<p;
		while(p!=-1){
			p = parent[p];
			cout<<p;
		}
		cout<<endl;
	}else{
		cout<<"No paths available"<<endl;
	}
}