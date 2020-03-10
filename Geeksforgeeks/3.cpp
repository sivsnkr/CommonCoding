#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> test;

	test.push_back(12);
	test.push_back(1);
	test.push_back(22);
	test.push_back(32);
	test.push_back(2);
	test.push_back(4);
	test.push_back(7);
	test.push_back(0);
	test.push_back(2);
	test.push_back(2);

	vector<int> sorted(33,0);

	for(auto i = 0; i < 10; i++)
	{
		sorted[test[i]]++;
	}

	test.clear();

	for(auto i = 0;i < 33; i++)
	{
		while(sorted[i]>0)
		{
			test.push_back(i);
			sorted[i]--;
		}
	}

	for(auto i = 0; i < 10; i++){
		cout<<test[i]<<" ";
	}
	cout<<endl;
}