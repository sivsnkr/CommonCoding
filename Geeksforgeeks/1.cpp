#include <bits/stdc++.h>
using namespace std;

int bfs(int number){
	queue<string> q;
	string t = "1";
	q.push(t);

	while(!q.empty()){
		string curn = q.front();

		int currNumber = stoi(curn);

		q.pop();

		if(currNumber%number == 0)
			return currNumber;

		q.push(curn+"1");
		q.push(curn+"0");
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;


	int res = bfs(n);
	cout<<res<<endl;
}