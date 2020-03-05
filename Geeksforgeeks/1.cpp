#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k;

	vector<vector<int>> weights(4,vector<int>(4,50));

	for(i = 0; i < 7; i++)
	{
		int weight;
		cin>>j>>k>>weight;
		weights[j][k] = weight;
	}

	for(i = 0; i < 4; i++)
	{
		weights[i][i] = 0;
	}

	for(k = 0; k < 4; k++)
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				weights[i][j] = min(weights[i][j],weights[i][k]+weights[k][j]);
			}
		}
	}

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			cout<<weights[i][j]<<" ";
		}
		cout<<endl;
	}
}