#include <bits/stdc++.h>
using namespace std;

void addEdge(int src, int dest, unordered_map<int, unordered_set<int>> &level)
{
    if (level.find(src) != level.end())
    {
        level[src].insert(dest);
    }
    else
    {
        unordered_set<int> temp;
        temp.insert(dest);
        level.insert({src, temp});
    }
}

void BFS(unordered_map<int, unordered_set<int>> &graph, unordered_map<int,int>&levels,int src){

    queue<pair<int,int>> nodes;
    nodes.push({src,0});
    levels.insert({src,0});

    while(!nodes.empty()){
        int node = nodes.front().first;
        int level = nodes.front().second;

        nodes.pop();

        unordered_set<int>::iterator it;
        for(it = graph[node].begin(); it!= graph[node].end(); it++){
            if(levels.find(*it)==levels.end()){
                nodes.push({*it,level+1});
                levels.insert({*it,level+1});
            }
        }
    }
}

int main()
{
    int edges;
    cin >> edges;

    int nodes = 2*edges;

    unordered_map<int, int> levels(nodes);
    unordered_map<int, unordered_set<int>> graph(nodes);
    int i;
    for (i = 0; i < edges; i++)
    {
        int src,dest;
        cin>>src>>dest;
        addEdge(src,dest,graph);
        addEdge(dest,src,graph);
    }

    unordered_map<int,unordered_set<int>>::iterator it;
    for(it = graph.begin(); it != graph.end(); it++){
        if(levels.find((*it).first)==levels.end())
            BFS(graph,levels,(*it).first);
    }

    cout<<"------------"<<endl;

    for(auto it = levels.begin(); it!=levels.end(); it++){
        cout<<(*it).first<< " "<< levels[(*it).first]<<endl;
    }
}