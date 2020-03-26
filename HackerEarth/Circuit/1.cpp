#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<unordered_set<int>> &graph, vector<int> &visited)
{
    unordered_set<int>::iterator it;
    for(it = graph[src].begin(); it != graph[src].end(); it++)
    {
        if(visited[*it] >= 1)
            visited[*it]++;
        else
        {
            visited[*it]++;
            dfs(*it,graph,visited);
        }
    }
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    nodes++;
    vector<unordered_set<int>> graph(nodes);

    int i;
    for(i  = 0; i < edges; i++)
    {
        int src, dest; 
        cin>>src>>dest;
        graph[src].insert(dest);
        graph[dest].insert(src);
    }

    vector<int> visited(nodes,0);
    dfs(1,graph,visited);

    for(i = 0; i < nodes; i++)
    {
        cout<<i<<" "<<visited[i]<<endl;
    }
}