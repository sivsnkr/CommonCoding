#include <bits/stdc++.h>
using namespace std;

int main()
{
	// priority_queue<tuple<int, int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	set<tuple<int, int, int>> q;
	q.insert({1, 2, 3});
	q.insert({4, 5, 4});
	q.insert({0, 5, 4});
	q.insert({3, 5, 3});

	q.erase(q.begin());
	auto i = *(q.begin());

	cout << get<0>(i) << endl;
}