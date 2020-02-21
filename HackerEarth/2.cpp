#include<bits/stdc++.h>

using namespace std;

long int dist;

void Dfs(int startNode, unordered_set<int> edgeNode, vector<unordered_set<int>> nodes,unordered_set<int> cities,vector<int> &visited){
    if(visited[startNode]||cities.size()==0)
        return;

    visited[startNode] = 1;
    unordered_set<int>::iterator it;

    for(it = nodes[startNode].begin(); it != nodes[startNode].end(); it++){
        if(!visited[*it] && (cities.find(*it)!=cities.end() || edgeNode.find(*it) == edgeNode.end())){
            dist++;
            cities.erase(startNode);
            Dfs(*it,edgeNode,nodes,cities,visited);
        }
    }
}

int main(){
    int n,q;
    cin>>n>>q;

    vector<unordered_set<int>> nodes(n+1);

    int i;
    for( i = 0; i < n-1; i++){
        int u,v;
        cin>>u>>v;
        nodes[u].insert(v);
        nodes[v].insert(u);
    }

    unordered_set<int> edgeNode;

    for(i = 0; i < n; i++){
        if(nodes[i].size() == 1){
            edgeNode.insert(i);
        }
    }

    for(i = 0; i < q; i++){
        int k;
        cin>>k;
        unordered_set<int> cities;

        int j;
        for(j = 0; j < k; j++){
            int t;
            cin>>t;
            cities.insert(t);
        }

        int startNode = *cities.begin();

        vector<int> visited(n,0);

        dist = 0;

        Dfs(startNode,edgeNode,nodes,cities,visited);
        cout<<ceil(float(dist)/2)<<endl;
    }
}