#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int santa_bag[n];
        unordered_set<int>gifts;

        int i;
        for(i = 0; i < n; i++)
        {
            cin>>santa_bag[i];
        }

        int arr[m];
        for(i = 0; i < m; i++)
        {
            int value;
            cin>>value;
            gifts.insert(value);
            arr[i] = value;
        }

        unordered_set<int> live;

        long long int sum = 0;
        int index = 0;
        for(int j : arr)
        {
            if(live.find(j) != live.end())
            {
                sum++;
                live.erase(j);
            }
            else
            {
                int c = live.size();
                while(santa_bag[index] != j)
                {
                    c++;
                    live.insert(santa_bag[index]);
                    index++;
                }
                index++;
                sum+=(2*c+1);
            }
        }

        cout<<sum<<endl;
    }
}