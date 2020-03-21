#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<tuple<int, int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	q.push({1,2, 3});
	q.push({4, 5,4});
	q.push({0, 5,4});
	q.push({3, 5,3});

	auto i = q.top();

	cout << get<0>(i) << endl;
}