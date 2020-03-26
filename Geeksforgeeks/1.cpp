#include <bits/stdc++.h>
using namespace std;

int find(vector<int> root, int node)
{
    if (root[node] == node)
        return node;
    return find(root, root[node]);
}

void dfs(int src, vector<unordered_set<int>> mst, int &nodeCount, vector<bool> &visited)
{
    if (visited[src])
        return;

    visited[src] = true;
    unordered_set<int>::iterator it;
    for (it = mst[src].begin(); it != mst[src].end(); it++)
    {
        if (!visited[*it])
        {
            nodeCount++;
            dfs(*it, mst, nodeCount, visited);
        }
    }
}

int main()
{
    int nodes = 9, edges = 14;
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> graph(nodes);

    vector<int> root(nodes);
    iota(root.begin(), root.end(), 0);

    int i;
    for (i = 0; i < edges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push({weight, dest});
        graph[dest].push({weight, src});
    }

    vector<unordered_set<int>> mst(nodes);
    while (1)
    {
        // select all the min of components and add to set
        for (i = 0; i < nodes; i++)
        {
            if (!graph[i].empty())
            {
                auto top = graph[i].top();
                int src = i, dest = top.second;
                int root1 = find(root, src);
                int root2 = find(root, dest);
                graph[i].pop();

                if (root1 != root2)
                {
                    mst[src].insert(dest);
                    mst[dest].insert(src);
                }
                root[dest] = root1;
            }
        }

        //  check if all nodes are added to set
        int edgeCount = 0;
        vector<bool> visited(nodes, false);
        for (i = 0; i < nodes; i++)
        {
            if (mst[i].size() > 0 && !visited[i])
            {
                dfs(i, mst, edgeCount, visited);
            }
        }
        cout << "nodecount " << edgeCount << endl;
        if (edgeCount >= nodes - 1)
            break;
    }

    for (i = 0; i < nodes; i++)
    {
        cout << i << " ";
        for (auto j = mst[i].begin(); j != mst[i].end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}