#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<set<pair<int,int>>> graph(9);

    int i;

    for(i = 0; i < 14; i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        graph[src].insert({dest,weight});
    }
    int max_dist = 14;
    vector<set<int>> bucket(14*9);
    vector<int> weights(9,0);

    bucket[0].insert(0);

    for(i = 0; i < 14*9; i++)
    {
        if(bucket[i].size() > 0)
        {
            set<int>::iterator it;

            for(it = bucket[i].begin(); it != bucket[i].end(); it++)
            {
                int src = *it;

                if(weights[src] == 0)
                    weights[src] = i;
                else 
                    continue;
                set<pair<int,int>>::iterator it1;

                for(it1 = graph[src].begin(); it1 != graph[src].end(); it1++)
                {
                    int dest = it1->first;
                    int weight = it1->second;

                    bucket[weight+i].insert(dest);
                }
            }
        }
    }

    for(i = 0; i < 9; i++)
    {
        cout<<"weight of "<<i<<" is "<<weights[i]<<endl;
    }
}