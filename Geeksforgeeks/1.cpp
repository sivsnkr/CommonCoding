#include<bits/stdc++.h>
using namespace std;
int n,m;
void Dfs(vector<vector<int>>&nodes,int i, int j){
	if(nodes[i][j]!=1)
		return;

	nodes[i][j] = 2;
	if(i-1>=0){
		Dfs(nodes,i-1,j);
	}

	if(i+1<n){
		Dfs(nodes,i+1,j);
	}

	if(j+1<m){
		Dfs(nodes,i,j+1);
	}

	if(j-1>=0){
		Dfs(nodes,i,j-1);
	}
}

int main(){
	int k,r;
	cin>>n>>m>>k>>r;

	int i;
	vector<vector<int>> nodes(n, vector<int>(m,1));

	for(i = 0; i< k; i++){
		int a,b;
		cin>>a>>b;

		int x,y;

		x=a,y=b;

		y-=r;
		x-=r;

		if(y<0)
			y = 0;
		if(x < 0)
			x = 0;
		int j,k;

		for(j = y; j < y+2*r+1; j++){
			for(k = x; k < x+2*r+1; k++){
				nodes[k][j] = 0;
			}
		}
	}

	for(i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<nodes[i][j]<<" ";
		}
		cout<<endl;
	}

	Dfs(nodes,0,0);

	if(nodes[n-1][m-1] == 2){
		cout<<"Possible";
	}else{
		cout<<"Not Possible";
	}
	cout<<endl;
}