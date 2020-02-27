#include<bits/stdc++.h>

using namespace std;

int res(int a,int b){
	queue<pair<int,int>> q;
	q.push({a,0});

	unordered_set<int> visit;
	visit.insert(a);
	while(!q.empty()){
		pair<int,int> curnode = q.front();
		q.pop();

		int x = curnode.first;
		int level = curnode.second;

		if(2*x == b|| x-1 == b)
			return level+1;

		if(visit.find(2*x) == visit.end()){
			visit.insert(2*x);
			q.push({2*x,level+1});
		}
		if(visit.find(x-1) == visit.end()){
			visit.insert(x-1);
			q.push({x-1,level+1});
		}
	}
	return 0;
}
int main(){
	int a,b;
	cin>>a>>b;

	int r = res(a,b);
	if(r != 0){
		cout<<r<<endl;
	}else{
		cout<<"Not possible "<<endl;
	}
}