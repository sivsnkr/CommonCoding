#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	q.push({1,{1,1}});
	q.push({2,{2,1}});

	auto i = q.top();
	cout<<i.first<<endl;
}