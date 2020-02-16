#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<long int,int>> sums(n);

    int i;
    for(i = 0; i < n; i++){
        int x,y,a,b;
        cin>>x>>y>>a>>b;

        long int sum = a+b+x+y;

        sums[i] = {sum,i};

    }

    sort(sums.begin(),sums.end(), [](pair<long int,int>a,pair<long int,int> b)->bool{
        return a.first<b.first;
    });

    for(i = 0; i < n; i++){
        cout<<sums[i].second+1<<" ";
    }
    cout<<endl;
}